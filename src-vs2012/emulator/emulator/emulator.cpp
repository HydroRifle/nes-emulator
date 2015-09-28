// emulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// local header files
#include "macros.h"
#include "types/types.h"
#include "unittest/framework.h"

#include "nes/internals.h"
#include "nes/opcodes.h"
#include "nes/mmc.h"

static void welcome()
{
	puts("Portable NES Emulator 1.0"); 
}

static void usage(_TCHAR* self_path)
{
	// _tprintf(_T("%s <nes file path>\n"), self_path);
}

static void init()
{
	initOpcodeTable();
	resetMMC();
}

int _cdecl _tmain(int argc, _TCHAR* argv[])
{
	welcome();
	usage(argv[0]);
	TestFramework::instance().runAll();
	init();
	

	TestFramework::destroy();
	return 0;
}

