RegisterPublic("OnGameModeInit", "", "GameModeInit");
RegisterPublic("OnGameModeExit", "", "GameModeExit");
RegisterPublic("OnFilterScriptInit", "", "FilterScriptInit");
RegisterPublic("OnFilterScriptExit", "", "FilterScriptExit");
RegisterPublic("OnPlayerConnect", "P", "PlayerConnect", ['playerid']);
RegisterPublic("OnPlayerDisconnect", "Pi", "PlayerDisconnect", ['playerid', 'reason']);
RegisterPublic("OnPlayerSpawn", "P", "PlayerSpawn", ['playerid']);
RegisterPublic("OnPlayerDeath", "PPi", "PlayerDeath", ['playerid', 'killerid', 'reason']);
RegisterPublic("OnVehicleSpawn", "V", "VehicleSpawn", ['vehicleid']);
RegisterPublic("OnVehicleDeath", "VP", "VehicleDeath", ['vehicleid', 'killerid']);
RegisterPublic("OnPlayerText", "Ps", "PlayerText", ['playerid', 'text']);
RegisterPublic("OnPlayerCommandText", "Ps", "PlayerCommandText", true, ['playerid', 'cmdtext']);
RegisterPublic("OnPlayerRequestClass", "Pi", "PlayerRequestClass", ['playerid', 'classid']);
RegisterPublic("OnPlayerEnterVehicle", "PVi", "PlayerEnterVehicle", ['playerid', 'vehicleid', 'ispassenger']);
RegisterPublic("OnPlayerExitVehicle", "PV", "PlayerExitVehicle", ['playerid', 'vehicleid']);
RegisterPublic("OnPlayerStateChange", "Pii", "PlayerStateChange", ['playerid', 'newstate', 'oldstate']);
RegisterPublic("OnPlayerEnterCheckpoint", "P", "PlayerEnterCheckpoint", ['playerid']);
RegisterPublic("OnPlayerLeaveCheckpoint", "P", "PlayerLeaveCheckpoint", ['playerid']);
RegisterPublic("OnPlayerEnterRaceCheckpoint", "P", "PlayerEnterRaceCheckpoint", ['playerid']);
RegisterPublic("OnPlayerLeaveRaceCheckpoint", "P", "PlayerLeaveRaceCheckpoint", ['playerid']);
RegisterPublic("OnRconCommand", "s", "RconCommand", true, ['cmd']);
RegisterPublic("OnPlayerRequestSpawn", "P", "PlayerRequestSpawn", ['playerid']);
RegisterPublic("OnObjectMoved", "O", "ObjectMoved", ['objectid']);
RegisterPublic("OnPlayerObjectMoved", "PO", "PlayerObjectMoved", ['playerid', 'objectid']);
RegisterPublic("OnPlayerPickUpPickup", "Pi", "PlayerPickUpPickup", ['playerid', 'pickupid']);
RegisterPublic("OnVehicleMod", "PVi", "VehicleMod", ['playerid', 'vehicleid', 'componentid']);
RegisterPublic("OnEnterExitModShop", "Pii", "EnterExitModShop", ['playerid', 'enterexit', 'interiorid']);
RegisterPublic("OnVehiclePaintjob", "PVi", "VehiclePaintjob", ['playerid', 'vehicleid', 'paintjobid']);
RegisterPublic("OnVehicleRespray", "PVii", "VehicleRespray", ['playerid', 'vehicleid', 'color1', 'color2']);
RegisterPublic("OnVehicleDamageStatusUpdate", "VP", "VehicleDamageStatusUpdate", ['vehicleid', 'playerid']);
RegisterPublic("OnUnoccupiedVehicleUpdate", "VPiffffff", "UnoccupiedVehicleUpdate", ['vehicleid', 'playerid', 'passenger_seat', 'new_x', 'new_y', 'new_z', 'vel_x', 'vel_y', 'vel_z']);
RegisterPublic("OnPlayerSelectedMenuRow", "Pi", "PlayerSelectedMenuRow", ['playerid', 'row']);
RegisterPublic("OnPlayerExitedMenu", "P", "PlayerExitedMenu", ['playerid']);
RegisterPublic("OnPlayerInteriorChange", "Pii", "PlayerInteriorChange", ['playerid', 'newinteriorid', 'oldinteriorid']);
RegisterPublic("OnPlayerKeyStateChange", "Pii", "PlayerKeyStateChange", ['playerid', 'newkeys', 'oldkeys']);
RegisterPublic("OnRconLoginAttempt", "ssi", "RconLoginAttempt", ['ip', 'password', 'success']);
RegisterPublic("OnPlayerUpdate", "P", "PlayerUpdate", ['playerid']);
RegisterPublic("OnPlayerStreamIn", "PP", "PlayerStreamIn", ['playerid', 'forplayerid']);
RegisterPublic("OnPlayerStreamOut", "PP", "PlayerStreamOut", ['playerid', 'forplayerid']);
RegisterPublic("OnVehicleStreamIn", "VP", "VehicleStreamIn", ['vehicleid', 'forplayerid']);
RegisterPublic("OnVehicleStreamOut", "VP", "VehicleStreamOut", ['vehicleid', 'forplayerid']);
RegisterPublic("OnActorStreamIn", "iP", "ActorStreamIn", ['actorid', 'forplayerid']);
RegisterPublic("OnActorStreamOut", "iP", "ActorStreamOut", ['actorid', 'forplayerid']);
RegisterPublic("OnDialogResponse", "Piiis", "DialogResponse", ['playerid', 'dialogid', 'response', 'listitem', 'inputtext']);
RegisterPublic("OnPlayerTakeDamage", "PPfii", "PlayerTakeDamage", ['playerid', 'issuerid', 'amount', 'weaponid', 'bodypart']);
RegisterPublic("OnPlayerGiveDamage", "PPfii", "PlayerGiveDamage", ['playerid', 'damagedid', 'amount', 'weaponid', 'bodypart']);
RegisterPublic("OnPlayerGiveDamageActor", "Pifii", "PlayerGiveDamageActor", ['playerid', 'damaged_actorid', 'amount', 'weaponid', 'bodypart']);
RegisterPublic("OnPlayerClickMap", "Pfff", "PlayerClickMap", ['playerid', 'fX', 'fY', 'fZ']);
RegisterPublic("OnPlayerClickTextDraw", "Pi", "PlayerClickTextDraw", ['playerid', 'clickedid']);
RegisterPublic("OnPlayerClickPlayerTextDraw", "Pi", "PlayerClickPlayerTextDraw", ['playerid', 'playertextid']);
RegisterPublic("OnIncomingConnection", "Psi", "IncomingConnection", ['playerid', 'ip_address', 'port']);
RegisterPublic("OnTrailerUpdate", "PV", "TrailerUpdate", ['playerid', 'vehicleid']);
RegisterPublic("OnVehicleSirenStateChange", "PVi", "VehicleSirenStateChange", ['playerid', 'vehicleid', 'newstate']);
RegisterPublic("OnPlayerClickPlayer", "PPi", "PlayerClickPlayer", ['playerid', 'clickedplayerid', 'source']);
RegisterPublic("OnPlayerEditObject", "POOiffffff", "PlayerEditObject", ['playerid', 'playerobject', 'objectid', 'response', 'fX', 'fY', 'fZ', 'fRotX', 'fRotY', 'fRotZ']);
RegisterPublic("OnPlayerEditAttachedObject", "Piiiifffffffff", "PlayerEditAttachedObject", ['playerid', 'response', 'index', 'modelid', 'boneid', 'fOffsetX', 'fOffsetY', 'fOffsetZ', 'fRotX', 'fRotY', 'fRotZ', 'fScaleX', 'fScaleY', 'fScaleZ']);
RegisterPublic("OnPlayerSelectObject", "PiOifff", "PlayerSelectObject", ['playerid', 'type', 'objectid', 'modelid', 'fX', 'fY', 'fZ']);
RegisterPublic("OnPlayerWeaponShot", "PiiPfff", "PlayerWeaponShot", ['playerid', 'weaponid', 'hittype', 'hitid', 'fX', 'fY', 'fZ']);