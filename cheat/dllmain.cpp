#include "pch.h"
#include "cheat.hpp"

HMODULE g_Module = nullptr;

static void CheatThread()
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    printf("womp womp nigga\n");

    Cheat cheat;

    while (true)
    {
        cheat.Tick();
        Sleep(50);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        g_Module = hModule;
        DisableThreadLibraryCalls(hModule);
        std::thread(CheatThread).detach();
    }
    return TRUE;
}