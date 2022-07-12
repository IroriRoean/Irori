// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <codecvt>
#include <Windows.h>
#include <iostream>
#include <detours.h>
#include <locale>

#include "il2cpp-appdata.h"
#include "helpers.h"


using namespace app;

extern const LPCWSTR LOG_FILE = L"debuglog.txt";

const std::string NotMelonLoader = "irori_not_melon_loader";
String* not_melon_loader;

std::string ConvertString(String* stringName)
{
	std::string newString(((char*)&stringName->fields.m_firstChar), stringName->fields.m_stringLength * 2);
	newString.erase(std::remove(newString.begin(), newString.end(), 0x00), newString.end());

	return newString;
}

void DoNothingMethod(MethodInfo* method)
{

}

bool File_Exists_Hook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	if(skey.find("dll") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}



	return app::File_Exists(str, method);
}

bool Directory_Exists_Hook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));
	if(skey.find("MelonLoader") != std::string::npos || skey.find(NotMelonLoader) != std::string::npos)
	{
		return false;
	}

	return app::Directory_Exists(str, method);
}

bool String_Contains_Hook(String* str, String* str2, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));

	if(skey.find("MelonLoader") != std::string::npos
		|| skey.find(NotMelonLoader) != std::string::npos
		|| skey.find("bypass-log.txt") != std::string::npos
		|| skey.find("imgui.ini") != std::string::npos
		|| skey.find("PhasBypass.dll") != std::string::npos
		|| skey.find("phasbypass.dll") != std::string::npos
		|| skey.find("version.dll") != std::string::npos
		|| skey.find("winhttp.dll") != std::string::npos
		|| skey.find("doorstop_config.ini") != std::string::npos
		|| skey.find("phasmobootstrapper.exe") != std::string::npos
		|| skey.find("phasmobootstrapper (steam).exe") != std::string::npos)
	{
		return false;
	}

	return app::String_Contains(str, str2, method);
}


void* TryGetModuleHandleHook(String* str, MethodInfo* method)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wideToNarrow;
	std::string skey = wideToNarrow.to_bytes(std::wstring((const wchar_t*)
		(&((Il2CppString*)str)->chars), ((Il2CppString*)str)->length));

	return nullptr;
}

String* GetMelonLoaderSearchStrings(Byte__Array* theArray, bool b, MethodInfo* method)
{
	return not_melon_loader;
}


void Run()
{
	not_melon_loader = (String*)il2cpp_string_new(NotMelonLoader.c_str());
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)app::u0A6Cu0A74u0A70u0A66u0A72u0A68u0A71u0A6Eu0A6Fu0A65u0A74_u0A6Au0A6Eu0A68u0A70u0A71u0A65u0A66u0A6Eu0A6Eu0A65u0A70, TryGetModuleHandleHook);
	DetourAttach(&(PVOID&)app::File_Exists, File_Exists_Hook);
	DetourAttach(&(PVOID&)app::Directory_Exists, Directory_Exists_Hook);
	DetourAttach(&(PVOID&)app::String_Contains, String_Contains_Hook);

	LONG lError = DetourTransactionCommit();
}
