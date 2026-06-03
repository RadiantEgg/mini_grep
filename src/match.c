#include <string.h>
#include "match.h"

int match_line(Config *cfg, char *line)
{
    int found = (strstr(line, cfg->pattern) != NULL);
    if (cfg->except == 1)
        found = !found;
    return found;
}
