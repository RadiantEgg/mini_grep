#include <string.h>
#include <ctype.h>
#include "match.h"

#define LINE_MAX_LENGTH 1024
#define PATTERN_MAX_LENGTH 256

static void to_lower_str(char *dst, char *src)
{
    while (*src) {
        *dst++ = tolower((unsigned char)*src++);
    }
    *dst = '\0';
}


int match_line(Config *cfg, char *line)
{
    char lower_line[LINE_MAX_LENGTH];
    char lower_pattern[PATTERN_MAX_LENGTH];

    to_lower_str(lower_pattern, cfg->pattern);
    to_lower_str(lower_line, line);

    int found = (strstr(lower_line, lower_pattern) != NULL);

    if (cfg->except == 1)
        found = !found;
        
    return found;
}
