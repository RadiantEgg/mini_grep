#ifndef OUTPUT_H
#define OUTPUT_H

#include "config.h"

void output_line(Config *cfg,
                 char *filename,
                 long lineno,
                 char *line,
                 int match,
                 int multi_file);

#endif