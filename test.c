#include "term.h"
#include <stdlib.h>

char *boxc[] = {
    "╔", "╗", "╚", "╝", "═", "║"
};
void box(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
    tm_setxy(x,y);
    fputs(boxc[0], stdout);
    for(int i = 0; i < w - 2; ++i)
        fputs(boxc[4], stdout);
    fputs(boxc[1], stdout);
    
    tm_setxy(x, y + h - 1);
    fputs(boxc[2], stdout);
    for(int i = 0; i < w - 2; ++i)
        fputs(boxc[4], stdout);
    fputs(boxc[3], stdout);
    
    tm_setxy(x, y + 1);
    for(int i = 0; i < h - 1; ++i)
    {
        fputs(boxc[5], stdout);
        tm_setxy(x, y + 1 + i);
    }
    
    tm_setxy(x + w - 1, y + 1);
    for(int i = 0; i < h - 1; ++i)
    {
        fputs(boxc[5], stdout);
        tm_setxy(x + w - 1, y + 1 + i);
    }
}
int main()
{
    char c;
    tm_init();
    tm_cls();
    tm_setxy(0,0);
    printf("Hello.");
    tm_setxy(10,2);
    printf("Hi");
    tm_setxy(8,7);
    int w, h;
    tm_getwh(&w, &h);
    printf("w:%d h:%d i:%u o:%u\n", w, h, __tm_tstructi.c_ispeed, __tm_tstruct.c_ospeed);
    tm_setcan(0);
    tm_setecho( 0);
    box(6, 5, w-10, h-10);
    getchar();
    tm_cls();
    tm_setxy(0,0);
    tm_reset();
    return 0;
}
