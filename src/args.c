#include "args.h"

void parse_args(int argc, char **argv, Config *cfg)
{
    int c, i = 0;

    while (--argc > 0) {
        if ((*++argv)[0] == '-') 
            while (c = *++argv[0])
                switch(c) {
                case 'n':
                    cfg->number = 0;
                    break;
                case 'x':
                    cfg->except = 0;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    cfg->file_count = -1;
                    argc = 0;
                    break;
                }     
        else 
            break;
    }
    // 模式列表pattern_list
    // while ((*++argv)[0] != "\"") {
    //     cfg->pattern[i] = *++argv;
    // }
    cfg->pattern = *argv;

    while (*++argv) {
        cfg->file_count++;
        cfg->files[i++] = *argv;
    }
}