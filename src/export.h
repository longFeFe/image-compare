#ifndef __EXPORT__H_
#if defined(_MSC_VER)
//  Microsoft
#ifdef EXPORTING_DLL
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#elif defined(__GNUC__)
//  GCC
#ifdef EXPORTING_DLL
#define EXPORT_DLL __attribute__((visibility("default")))
#else
#define EXPORT_DLL
#endif
#else
//  do nothing and hope for the best?
#ifdef EXPORTING_DLL
#define EXPORT_DLL
#else
#define EXPORT_DLL
#endif
#pragma warning Unknown dynamic link import/export semantics.
#endif
#endif //__EXPORT__H_