#pragma once

#define DEBUGMODE 0

#ifdef DEBUGMODE
	#define DEBUGMODE_PRINT_FPS 0
	#define DEBUGMODE_PRINT_INPUTS 0
	#define DEBUGMODE_PRINT_STATE 0
	#define DEBUGMODE_PRINT_ANIM 0
#else
	#define DEBUGMODE_PRINT_FPS 0
	#define DEBUGMODE_PRINT_INPUTS 0
	#define DEBUGMODE_PRINT_STATE 0
	#define DEBUGMODE_PRINT_ANIM 0
#endif // DEBUGMODE