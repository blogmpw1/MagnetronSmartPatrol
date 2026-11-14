
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Build-validation scaffold only.
// No game hooks are installed and no gameplay behavior is changed.

extern "C" __declspec(dllexport) const char* MSP_GetBuildStatus() noexcept {
    return "BUILD_SCAFFOLD_ONLY_NOT_GAMEPLAY_IMPLEMENTED";
}

extern "C" __declspec(dllexport) unsigned int MSP_GetInterfaceVersion() noexcept {
    return 1;
}

BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID) {
    return TRUE;
}
