#ifndef FILE_H
#define FILE_H

#include "config.h"
#include "input.h"

void process_file(Config *cfg, char *filename);
 
void process_all(Config *cfg, InputSource *sources, int n);

#endif