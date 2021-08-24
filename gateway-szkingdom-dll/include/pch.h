// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#pragma comment(lib, "lib/x64/KSMMApi.lib")

// add headers that you want to pre-compile here
#include "framework.h"
#include "include/Define.h"

extern "C" _declspec(dllexport) int Add(int a, int b);
extern "C" _declspec(dllexport) int Sub(int a, int b);
//extern "C" _declspec(dllexport) int InitPluginUseCfg(PST_tagInitInfo pInitInfo, int nThreads = 1, char* pszLogName = "", char* pszAlgoName = OEM_PRODUCT_NAME);
extern "C" _declspec(dllexport) int InitPluginUseCfg(PST_tagInitInfo pInitInfo);

#endif //PCH_H
