#include <stdio.h>
#include "file.h"
#include "config.h"
#include "match.h"
#include "input.h"
#include "output.h"

#define MAX_LINE_LENGTH 1024

// 处理单个文件流
static void process_source(Config *cfg, InputSource *src)
{
    char line[MAX_LINE_LENGTH];
    long lineno = 0;
    int match_count = 0;
    
    while (next_line(src, line, sizeof(line))) {
        lineno++;
        
        if (match_line(cfg, line)) {
            switch (cfg->mode) {
                case MODE_PRINT:
                    output_line(cfg, src->name, lineno, line);
                    break;
                case MODE_COUNT:
                    match_count++;
                    break;
            }
        }
    }
    
    if (cfg->mode == MODE_COUNT)
    printf("%d\n", match_count);
}

void process_all(Config *cfg, InputSource *srcs, int count)
{
    for (int i = 0; i < count; i++) 
        process_source(cfg, &srcs[i]);
}


// void process_file(Config *cfg, char *filename)
// {
//     char line[MAX_LINE_LENGTH];
//     long lineno = 0;
//     int count = 0;

//     FILE *fp = fopen(filename, "r");
//     if (!fp) {
//         perror(filename);
//         return;
//     }


//     while (fgets(line, sizeof(line), fp)) {
//         lineno++;

//         if (match_line(cfg, line) == 1) {
//             switch (cfg->mode) {
//             case MODE_PRINT:
//                 output_line(cfg, filename, lineno, line);            
//                 break;            
//             case MODE_COUNT:
//                 count++;
//                 break;
//             }
//         }
//     }

//     if (cfg->mode == MODE_COUNT)
//         printf("%d\n", count);
    
//     fclose(fp);
// }