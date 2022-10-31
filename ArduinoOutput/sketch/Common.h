#line 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\Common.h"
#pragma once

#define DEBUGMODE 1

#ifdef DEBUGMODE
	#define DEBUGMODE_PRINT_FPS 0
	#define DEBUGMODE_PRINT_INPUTS 0
#else
	#define DEBUGMODE_PRINT_FPS 0
	#define DEBUGMODE_PRINT_INPUTS 0
#endif // DEBUGMODE