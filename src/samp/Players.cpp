
#include "samp/Players.h"
#include "utils/Helpers.h"
#include "utils/Utils.h"

using namespace sampjs;

Players::Players(Server* sampjs){
	_sampjs = sampjs;
	JS_SCOPE(sampjs->_isolate);
	JS_CONTEXT(sampjs->_isolate, sampjs->_context);
	Local<Array> player_arr = Array::New(sampjs->GetIsolate(),0);
	sampjs->SetGlobalObject("$players", player_arr);

	

	std::string src = R"(
	"use strict";
class $PLAYER extends $EVENTS {

	constructor(id){
		
		super();
		this.id = id;
		this.name_ =  "";
		this.ip_ = null;
		this.pos_ = {x:0,y:0,z:0};
		this.velocity_ = {x:0,y:0,z:0};
		this.health_ = 0;
		this.armour_ = 0;
		this.currentAmmo_ = 0;
		this.currentWeapon_ = 0;
		this.weaponState_ = 0;
		this.targetPlayer_ = 0;
		this.weapons_ = [];
		this.color_ = 0;
		this.money_ = 0;
		this.skin_ = 0;
		this.score_ = 0;
		this.state_ = 0;
		this.wantedLevel_ = 0;
	
	}


	get isValid(){
		return (this.id < 65535);
	}
	get name(){
		this.name_ = GetPlayerName(this.id);
		return this.name_; 		
	}
	set name(name){
		SetPlayerName(this.id, name);
		this.name_ = name;	
	}	
	get ip() {
		if(this.ip_ == null) this.ip_ = GetPlayerIp(this.id);
		return this.ip_;
	}
	get facingAngle() {
		this.pos_.a = GetPlayerFacingAngle(this.id);
		return this.pos_.a;
	}
	set facingAngle(angle) {
		this.pos_.a = angle;
		SetPlayerFacingAngle(this.id,angle);
	}
	get pos(){
		var tmpp = GetPlayerPos(this.id);
		var tmpa = this.facingAngle;
		this.pos_ = {x: tmpp.x, y: tmpp.y, z: tmpp.z, a: tmpa };
		return this.pos_;
	}
	set pos(pos){
		if(Array.isArray(pos)){
			if(pos.length > 3) this.facingAngle = pos[3];
			this.pos_.x = pos[0];
			this.pos_.y = pos[1];
			this.pos_.z = pos[2];
		} else {
			if(pos.hasOwnProperty('a')) this.facingAngle = pos.a;
			this.pos_.x = pos.x;
			this.pos_.y = pos.y;
			this.pos_.z = pos.z;
		}
		SetPlayerPos(this.id,this.pos_.x,this.pos_.y,this.pos_.z);
	}
	get health(){
		this.health_ = GetPlayerHealth(this.id);
		return this.health_;
	}
	set health(health){
		this.health_ = health;
		SetPlayerHealth(this.id, this.health_);
	}
	get armour(){
		this.armour_ = GetPlayerArmour(this.id);
		return this.health_;
	}
	set armour(armour){
		this.armour_ = armour;
		SetPlayerArmour(this.id, this.armour_);
	}
	get ammo() {
		this.currentAmmo_ = GetPlayerAmmo(this.id);
		return this.currentAmmo_;
	}
	setAmmo(weaponid,ammo) {
		this.weapons_[weaponid] = ammo;
		SetPlayerAmmo(this.id,weaponid,this.weapons_[weaponid]);
	}
	get weaponState() {
		this.weaponState_ = GetPlayerWeaponState(this.id);
		return this.weaponState_;
	}
	get targetPlayer() {
		this.targetPlayer_ = GetPlayerTargetPlayer(this.id);
		return this.targetPlayer_;
	}
	get team() {
		this.team_ = GetPlayerTeam(this.id);
		return this.team_;
	}
	set team(team) {
		this.team_ = team;
		SetPlayerTeam(this.id,team);
	}
	get interior() {
		this.interior_ = GetPlayerInterior(this.id);
		return this.interior_;
	}
	set interior(interior) {
		this.interior_ = interior;
		SetPlayerInterior(this.id,interior);
	}
	giveWeapon(weaponid,ammo) {
		this.weapons_[weaponid] = ammo;
		GivePlayerWeapon(this.id,weaponid,this.weapons_[weaponid]);
	}
	resetWeapons() {
		for(var i=0;i<47;i++) this.weapons_[i] = 0;
		ResetPlayerWeapons(this.id);
	}
	get weapon() {
		this.currentWeapon_ = GetPlayerWeapon(this.id);
		return this.currentWeapon_;
	}
	set weapon(weaponid) {
		this.currentWeapon_ = weaponid;
		SetPlayerArmedWeapon(this.id,this.currentWeapon_);
	}
	get weaponData() {
		for(var i=0;i<13;i++) {
			var data = GetPlayerWeaponData(this.id,i);
			this.weapons_[data.weapons] = data.ammo;
		}
		return this.weapons_;
	}
	get color() {
		this.color_ = GetPlayerColor(this.id);
		return this.color_;
	}
	set color(color) {
		this.color_ = color;
		SetPlayerColor(this.id,this.colour_);
	}
	getDistanceFromPoint(point) {
		if(Array.isArray(pos)) return GetPlayerDistanceFromPoint(this.id,point[0],point[1],point[2]);
		else return GetPlayerDistanceFromPoint(this.id,point.x,point.y,point.z);
	}
	get keys() {
		var keys = GetPlayerKeys(this.id);
		return keys.keys;
	}
	get arrowKeys() {
		var keys = GetPlayerKeys(this.id);
		return {updown: keys.updown, leftright: keys.leftright};
	}
	get lastShotVectors() {
		var vectors = GetPlayerLastShotVectors(this.id);
		return {origin: {x: vectors.fOriginX, y: vectors.fOriginY, z: vectors.fOriginZ},
				hitPos: {x: vectors.fHitPosX, y: vectors.fHitPosY, z: vectors.fHitPosZ}};
	}
	get money() {
		this.money_ = GetPlayerMoney(this.id);
		return this.money_;
	}
	set money(money) {
		var currentMoney = this.money;
		this.money_ = money;
		this.giveMoney(money - currentMoney);
	}
	giveMoney(money) {
		this.money_ += money;
		GivePlayerMoney(this.id,money);
	}
	resetMoney(money) {
		this.money_ = 0;
		ResetPlayerMoney(this.id);
	}
	get score() {
		this.score_ = GetPlayerScore(this.id);
		return this.score_;
	}
	set score(score) {
		this.score_ = score;
		SetPlayerScore(this.id,this.score_);
	}
	get skin() {
		this.skin_ = GetPlayerSkin(this.id);
		return this.skin_;
	}
	set skin(skin) {
		this.skin_ = skin;
		SetPlayerSkin(this.id,this.skin_);
	}
	get state() {
		this.state_ = GetPlayerState(this.id);
		return this.state_;
	}
	get wantedLevel() {
		this.wantedLevel_ = GetPlayerWantedLevel(this.id);
		return this.velocity_;
	}
	set wantedLevel(wantedLevel) {
		this.wantedLevel_ = wantedLevel;
		SetPlayerWantedLevel(this.id,this.wantedLevel_);
	}
	get velocity(){
		var vel = GetPlayerVelocity(this.id);
		this.velocity_ = {x: vel.x, y: vel.y, z: vel.z};
		return this.pos_;
	}
	set velocity(vel){
		if(Array.isArray(vel)) {
			this.velocity_.x = vel[0];
			this.velocity_.y = vel[1];
			this.velocity_.z = vel[2];
		} else {
			this.velocity_.x = vel.x;
			this.velocity_.y = vel.y;
			this.velocity_.z = vel.z;
		}
		SetPlayerVelocity(this.id,this.velocity_.x,this.velocity_.y,this.velocity_.z);
	}

	set vehicle(vehicleid){
		RemovePlayerFromVehicle(this.id);
		PutPlayerInVehicle(this.id, vehicleid, 0);
	}

	get vehicle(){
		return GetPlayerVehicleID(this.id);
	}

	valueOf(){
		return this.id;
	}
};
	
	new $PLAYER(65535);
)";
	
	Local<String> source = String::NewFromUtf8(sampjs->GetIsolate(), src.c_str());
	Local<String> name = String::NewFromUtf8(sampjs->GetIsolate(), "[players.js]");

	TryCatch try_catch;
	Local<Script> script = Script::Compile(source, name);
	if (script.IsEmpty()){
		sampjs->GetIsolate()->CancelTerminateExecution();
		Utils::PrintException(&try_catch);
	}
	
	Local<Object> player = Local<Object>::Cast(script->Run());

	if (player.IsEmpty()){
		//printf("Why am I empty???\n");

	}


	playerObj.Reset(sampjs->GetIsolate(), player);

	sampjs->SetGlobalObject("$PLAYER", player);
	std::string src2 = R"(
		"use strict";

		class $SERVER extends $EVENTS {
			constructor(){
				super();
				this.weather_ = 0;
				this.gravity_ = 0.008;
				this.time_ = 0;
			}

			checkPlayers(){
				for(var i = 0; i < 1000; i++){
					if(CallNative("IsPlayerConnected", "i", i)){
						print("Player "+i+" is connected");
						$server.AddPlayer(i);
					}
				}
			}
			
			set time(hour){
				SetWorldTime(hour);
			}

			get time(){
				return hour;
			}

			set gravity(amount){
				SetGravity(amount);
			}

			get gravity(){
				return GetGravity();
			}


			set weather(weatherid){
				SetWeather(weaterid);
				this.weather_ = weatherid;
			}

			get weather(){
				return this.weather_;
			}
		};
		
		var $server = new $SERVER();
	)";

	TryCatch try_catch2;
	Local<String> source2 = String::NewFromUtf8(sampjs->GetIsolate(), src2.c_str());
	Local<String> name2 = String::NewFromUtf8(sampjs->GetIsolate(), "[server.js]");

	Local<Script> script2 = Script::Compile(source2, name2);

	if (script2.IsEmpty()){
		Utils::PrintException(&try_catch2);
	}
	script2->Run();

	Local<Object> server = sampjs->GetGlobalObject("$server");

	Local<FunctionTemplate> dbgtmp = FunctionTemplate::New(sampjs->GetIsolate(), Utils::JS_Debug);
	server->Set(String::NewFromUtf8(sampjs->GetIsolate(), "Debug"), dbgtmp->GetFunction());

	Local<FunctionTemplate> fntmp = FunctionTemplate::New(sampjs->GetIsolate(), Players::CreatePlayer);
	server->Set(String::NewFromUtf8(sampjs->GetIsolate(), "AddPlayer"), fntmp->GetFunction());
	

}

void Players::Shutdown(){
	// Do Cleanup
}

void Players::CreatePlayer(const FunctionCallbackInfo<Value> & args){
	Server *sampjs = Server::GetInstance(args.GetIsolate()->GetCallingContext());
	Players *players = (Players*)sampjs->GetModule("players");
	players->AddPlayer(args[0]->Int32Value());
}

Local<Object> Players::GetPlayerObject(int playerid){
	TryCatch try_catch;
	Locker v8Locker(_sampjs->GetIsolate());
	Isolate::Scope isolate_scope(_sampjs->GetIsolate());
	EscapableHandleScope handle_scope(_sampjs->GetIsolate());
	JS_CONTEXT(_sampjs->GetIsolate(), _sampjs->_context)

	if (playerid == 65535){ //INVALID_PLAYER_ID
		Local<Object> val = _sampjs->GetGlobalObject("$PLAYER");
		return handle_scope.Escape(val);
	}
	Local<Value> val = _sampjs->GetGlobalObject("$players")->Get(playerid);

	if (val->IsObject()){
		Local<Object> player = Local<Object>::Cast(val);
		if (try_catch.HasCaught()){
			_sampjs->GetIsolate()->CancelTerminateExecution();
			Utils::PrintException(&try_catch);
		}
		return handle_scope.Escape(player);
	}
	else {
		AddPlayer(playerid);
		Local<Object> player = GetPlayerObject(playerid);
		if (try_catch.HasCaught()){
			_sampjs->GetIsolate()->CancelTerminateExecution();
			Utils::PrintException(&try_catch);
		} 
		return handle_scope.Escape(player);
	} 



}

void Players::AddPlayer(int playerid){
	Local<Integer> playerido = Integer::New(_sampjs->GetIsolate(), playerid);
	Local<Object> obj = Local<Object>::New(_sampjs->GetIsolate(), playerObj)->Clone();
	obj->Set(String::NewFromUtf8(_sampjs->GetIsolate(), "id"), playerido);
	_sampjs->GetGlobalObject("$players")->Set(playerid, obj);
}

void Players::RemovePlayer(int playerid){
	_sampjs->GetGlobalObject("$players")->Delete(playerid);
}