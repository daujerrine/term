<<<<<<< HEAD
//#include "tm.h"
//#include <stdlib.h>
=======
#include "tm.h"
#include <stdlib.h>
>>>>>>> 1424dcfa02a4f14b7aa5ad5eef875466a68ac91b

// Demonstrating DEC box drawing characters
// Unicode characters can be used but they're not likely to be supported
// Universally, I believe.
char *boxc[] = {
    TM_DEC "\x6c" TM_DECE, TM_DEC "\x6b" TM_DECE, TM_DEC "\x6d" TM_DECE, TM_DEC "\x6a" TM_DECE, 
    TM_DEC "\x71" TM_DECE, TM_DEC "\x78" TM_DECE
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
    int w, h;
    tm_init();
    tm_cls();
    tm_setcv(0);
    
    tm_setxy(0,0);
    printf("Hello.");
    tm_setxy(10,2);
    printf("Hi");
    
    tm_setxy(8,7);
    tm_getwh(&w, &h);
    printf("width:%d height:%d", w, h);
    
    tm_setcan(0);
    tm_setecho( 0);
    box(6, 5, w-10, h-10);
    
    getchar();
    
    tm_cls();
    tm_setxy(0,0);
    tm_reset();
    tm_setcv(1);
    
    return 0;
}
