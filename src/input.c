#include <stdio.h>
#include "input.h"


int next_line(InputSource *src, char *buf, int size)
{
    return fgets(buf, size, src->fp) != NULL;
}