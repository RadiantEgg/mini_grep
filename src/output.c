#include <stdio.h>
#include <string.h>
#include "output.h"
#include "config.h"

#define PREFIX_MAX_LENGTH 128

static void build_prefix(Config *cfg, char *prefix, char *filename, long lineno)
{
    int len = 0;
    prefix[0] = '\0';
    if (cfg->file_count > 1)
        len += snprintf(prefix + len, PREFIX_MAX_LENGTH, "%s:", filename);
    
    if (cfg->number == 1)
        len += snprintf(prefix + len, PREFIX_MAX_LENGTH, "%ld:", lineno);
}


void output_line(Config *cfg, char *filename, long lineno, char *line)
{
    char *separator = ":";
    build_separator(&separator);
    char prefix[PREFIX_MAX_LENGTH];
    build_prefix(cfg, &prefix, filename, lineno);
    printf("%s%s%s\n", prefix, separator, line);
}

