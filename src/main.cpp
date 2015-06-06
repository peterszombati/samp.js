#pragma comment(lib, "winmm.lib")


#include "sdk.h"


#include "SAMP_JS.h"
#include "samp/SAMP_Callbacks.h"

#define NOMINMAX


#include <fstream>
#include <sstream>
#include <regex>
#include <iostream>
#include <string> 
#include <map>

#include "utils/Helpers.h"

//uv #include "uv.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_BUGFIX 4

typedef void(*logprintf_t)(char* format, ...);
logprintf_t logprintf;

extern void *pAMXFunctions;

std::vector<std::string> js_scripts;


void ReadConfig(){
	std::ifstream config("server.cfg");
	if (!config){
		std::cout << "Config File does not exist" << std::endl;
	}
	else {
		std::string line;
		while (std::getline(config, line)){
			std::vector<std::string> args = sjs::string::split(line);
			if (args.size() > 1){
				if (args[0] == "jsfiles"){
					for (unsigned int i = 1; i < args.size(); i++){
						js_scripts.push_back(args[i]);
					}
				}
			}
		}
	}
}


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports(){
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData){
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	sjs::logger::printf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	/*
	std::stringstream buf;
	std::streambuf * old = std::cout.rdbuf(buf.rdbuf());
	std::cout << std::endl;
	std::cout << std::string(30, '-') + " samp.js " + std::string(30, '-') << std::endl;
	std::cout << "*** Loaded samp.js v" << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUGFIX << " by !damo!spiderman ***" << std::endl;
	std::cout << std::string(30, '-') + std::string(9,'-') + std::string(30, '-') << std::endl;
	std::cout << std::endl; */

	sjs::logger::printf("Testing");
	ReadConfig();

	SAMP_JS::InitJS();
	
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload(){
	std::cout << std::endl;
	std::cout << std::string(30, '-') + " samp.js unloaded " + std::string(30, '-') << std::endl;
	std::cout << std::endl;

	SAMP_JS::UnloadJS();
}
#include "samp/SAMP_Natives.h"

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx){
	int res = 0;
	if (res = amx_Register(amx, PluginNatives, -1)){
		printf("Failed to register samp.js natives.\n");
	}

	int idx;
	if (!amx_FindPublic(amx, "SAMPJS_Init", &idx)){
		if (js_scripts.size() > 0){
			for (unsigned int i = 0; i < js_scripts.size(); i++){
				SAMP_JS::New(js_scripts[i], amx);
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "[samp.js] No JS Scripts configured. Add jsfiles to your server.cfg" << std::endl;
		}
	}
	return 1;
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx){
	for (auto it = SAMP_JS::_scripts.begin(); it != SAMP_JS::_scripts.end();){
		if (it->second->GetAMX() == amx){
			it->second->Shutdown();
			SAMP_JS::_scripts.erase(it++);
		}
		else {
			++it;
		}
	}
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick(){
	for (auto it = SAMP_JS::_scripts.begin(); it != SAMP_JS::_scripts.end();++it){
		it->second->ProcessTick();
	
	}
}



