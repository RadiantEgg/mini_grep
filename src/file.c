#include <stdio.h>
#include "file.h"
#include "config.h"
#include "match.h"
#include "output.h"

#define MAX_LINE_LENGTH 1024

void process_file(Config *cfg, char *filename)
{
    char line[MAX_LINE_LENGTH];
    long lineno = 0;

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror(filename);
        return;
    }


    while (fgets(line, sizeof(line), fp)) {
        lineno++;

        if (match_line(cfg, line) == 1) 
            output_line(cfg, filename, lineno, line);
    }
    
    fclose(fp);
}