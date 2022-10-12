#include <Windows.h>
#include "main.h"

SAMPFUNCS *SF = new SAMPFUNCS();

bool Initialized = true;

void CALLBACK od(std::string params) {
	int count = std::stoi(params);
	if (count < 6) {
		PEDSELF->GetVehicle()->OpenDoor(count, 1.0f, false);
		SF->getSAMP()->getChat()->AddChatMessage(-1, "{4A4A4A}[VehicleElement]:{727272} открыл элемент - {ff0000}%d", count);
	}
	else { SF->getSAMP()->getChat()->AddChatMessage(-1, "{4A4A4A}[VehicleElement]:{727272} нельзя вводить значение больше 6-ти"); }
}

void __stdcall mainloop() {
	if (SF->getSAMP()->IsInitialized()) {
		if (Initialized) {
			SF->getSAMP()->getChat()->AddChatMessage(-1, "{4A4A4A}VehicleElement]:{727272} is initialized");
			SF->getSAMP()->registerChatCommand("od", od);
			Initialized = false;
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved) {
	if (dwReasonForCall == DLL_PROCESS_ATTACH)
		SF->initPlugin(mainloop, hModule);
	return TRUE;
}