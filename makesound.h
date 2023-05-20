#include "frequencies.h"
#include "windows.h"

void makesound(char chr, int duration)
{
    const int freq = getfrq(chr);
    if (freq == -1 || chr != ' ')
    {
        Beep(freq, duration);
        return;
    }
    Sleep(duration);
}