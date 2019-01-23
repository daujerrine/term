// term.c - small library for program interaction through the terminal
// It is more suitable to use termcap.h though.

#ifndef TMLIB_H
#define TMLIB_H

#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>

// A character limit for strings imposed on certain functions.
#define _TM_CLIM 32

#define TM_ESC    "\x1B"

// Colours:

// Foreground colours
#define TM_FBLACK   TM_ESC "[30m"
#define TM_FRED     TM_ESC "[31m"
#define TM_FGREEN   TM_ESC "[32m"
#define TM_FYELLOW  TM_ESC "[33m"
#define TM_FBLUE    TM_ESC "[34m"
#define TM_FPINK    TM_ESC "[35m"
#define TM_FCYAN    TM_ESC "[36m"
#define TM_FLGREY   TM_ESC "[37m"
#define TM_FGREY    TM_ESC "[90m"
#define TM_FLGRAY   TM_CLGREY
#define TM_FGRAY    TM_CGREY
#define TM_FLRED    TM_ESC "[91m"
#define TM_FLGREEN  TM_ESC "[92m"
#define TM_FLYELLOW TM_ESC "[93m"
#define TM_FLBLUE   TM_ESC "[94m"
#define TM_FLPINK   TM_ESC "[95m"
#define TM_FLCYAN   TM_ESC "[96m"
#define TM_FWHITE   TM_ESC "[97m"

#define TM_FNORM  TM_ESC "[39m"

#define TM_F256 TM_ESC "[38;5;"
#define TM_F256E "m"

// Background colours
#define TM_BBLACK   TM_ESC "[40m"
#define TM_BRED     TM_ESC "[41m"
#define TM_BGREEN   TM_ESC "[42m"
#define TM_BYELLOW  TM_ESC "[43m"
#define TM_BBLUE    TM_ESC "[44m"
#define TM_BPINK    TM_ESC "[45m"
#define TM_BCYAN    TM_ESC "[46m"
#define TM_BLGREY   TM_ESC "[47m"
#define TM_BGREY    TM_ESC "[100m"
#define TM_BLGRAY   TM_CLGREY
#define TM_BGRAY    TM_CGREY
#define TM_BLRED    TM_ESC "[101m"
#define TM_BLGREEN  TM_ESC "[102m"
#define TM_BLYELLOW TM_ESC "[103m"
#define TM_BLBLUE   TM_ESC "[104m"
#define TM_BLPINK   TM_ESC "[105m"
#define TM_BLCYAN   TM_ESC "[106m"
#define TM_BWHITE   TM_ESC "[107m"

#define TM_BNORM  TM_ESC "[49m"

#define TM_B256 TM_ESC "[48;5;"
#define TM_B256E "m"

// Formatting:

// Set
#define TM_BOLD  TM_ESC "[1m"
#define TM_DIM   TM_ESC "[2m"
#define TM_UL    TM_ESC "[4m"
#define TM_BLINK TM_ESC "[5m"
#define TM_INV   TM_ESC "[7m"
#define TM_HID   TM_ESC "[8m"

// Unset
#define TM_UBOLD  TM_ESC "[21m"
#define TM_UDIM   TM_ESC "[22m"
#define TM_UUL    TM_ESC "[24m"
#define TM_UBLINK TM_ESC "[25m"
#define TM_UINV   TM_ESC "[27m"
#define TM_UHID   TM_ESC "[28m"

#define TM_NORM TM_ESC "[0m"

// Deletion
#define TM_CL0 TM_ESC "[1K" // Clear from start to cursor
#define TM_CLE TM_ESC "[0K" // Clear from cursor to end
#define TM_CLX TM_ESC "[2K" // Clear whole line
#define TM_CLS TM_ESC "[2J" // Cear whole screen

// Cursor handling
#define TM_CRIVIS TM_ESC "[?25l"
#define TM_CRVIS  TM_ESC "[?25h"

// Special input sequences
#define TM_KUP    TM_ESC "[[A"
#define TM_KDOWN  TM_ESC "[[B"
#define TM_KRIGHT TM_ESC "[[C"
#define TM_KLEFT  TM_ESC "[[D"

// Prefix and suffix for DEC special alternate character set
// (https://en.wikipedia.org/wiki/DEC_Special_Graphics)
// The following chars are available for box drawing:
// 6a 6b 6c 6d 6e 71 74 75 76 77 78
#define TM_DEC   TM_ESC "(0"
#define TM_DECE  TM_ESC "(B"


static struct winsize __tm_wstruct;
static struct termios __tm_tstruct; // Current
static struct termios __tm_tstructi; // Initial

// !TODO Error handling if any
void tm_init(); // Initialise stuff 
void tm_reset(); // Destroy allocated stuff and reset term to default cfg
void tm_setxy(unsigned int x, unsigned int y); // Set cursor position
void tm_setcv(char f); // Set cursor visibility
void tm_setcan(char f); // Set/unset canonical mode
void tm_setecho(char f); // Set/unset input echo
void tm_getwh(unsigned int *w, unsigned int *h);
void tm_f256(unsigned short int c, char *t); // Set 256 colours (foreground)
void tm_b256(unsigned short int c, char *t); // Set 256 colours (background)
void tm_cls(); // Clear screen
#endif
