#include "term.h"

void tm_init()
{
    tcgetattr(0, &__tm_tstructi);
    __tm_tstruct = __tm_tstructi;
}

void tm_reset()
{
    tcsetattr(0, TCSANOW, &__tm_tstructi);
}

void tm_setxy(unsigned int x, unsigned int y)
{
    char q[_TM_CLIM];
    sprintf(q, TM_ESC "[%u;%uH", y, x);
    fputs(q, stdout);
}

void tm_getwh(unsigned int *w, unsigned int *h)
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &__tm_wstruct);
    *w = __tm_wstruct.ws_col;
    *h = __tm_wstruct.ws_row;
}

void tm_setcan(char f)
{
    __tm_tstruct.c_lflag &= ~((!f) ^ ICANON); // if f then set else unset
    tcsetattr(0, TCSANOW, &__tm_tstruct);
    
}
void tm_setecho(char f)
{
    __tm_tstruct.c_lflag &= ~((!f) ^ ECHO);
    tcsetattr(0, TCSANOW, &__tm_tstruct);
}

void tm_cls()
{
    fputs(TM_CLS, stdout);
}

void tm_f256(unsigned short int c, char *t)
{
    sprintf(t, TM_ESC "[38;5;" "%u" "m", c);
}

void tm_b256(unsigned short int c, char *t)
{
    sprintf(t, TM_ESC "[48;5;" "%u" "m", c);
}
