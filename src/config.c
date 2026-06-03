#include "config.h"
#include <stdio.h>
#include <stdlib.h>

void init_config(Config* cfg)
{
    cfg->number = 0;
    cfg->except = 0;
    cfg->pattern = NULL;
    cfg->file_count = 0;
    cfg->files = NULL;
}