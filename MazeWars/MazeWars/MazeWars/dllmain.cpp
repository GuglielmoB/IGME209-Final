// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	#if defined(DEBUG) | defined(_DEBUG)
		// Enable memory leak detection as a quick and dirty
		// way of determining if we forgot to clean something up
		//  - You may want to use something more advanced, like Visual Leak Detector
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	#endif

	switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

