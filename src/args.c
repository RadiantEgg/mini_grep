#include <stdio.h>
#include <stdlib.h>
#include "args.h"
#include "input.h"

void parse_args(int argc, char **argv, Config *cfg, InputSource **srcs, int *count)
{
    char c;

    while (--argc > 0) {
        if ((*++argv)[0] == '-') 
        while ((c = *++argv[0]))
        switch(c) {
            case 'n':
            cfg->number = 1;
            break;
            case 'x':
            cfg->except = 1;
            break;
            case 'i':
            cfg->ignore_case = 1;
            break;
            case 'c':
            cfg->mode = MODE_COUNT;
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

    cfg->pattern = *argv;
    argc--;
    argv++;
    
    cfg->file_count = argc;
    
    if (argc > 0) {
        *srcs = malloc(argc * sizeof(InputSource));
        
        for (int i = 0; i < argc; i++) {
            (*srcs)[i].fp = fopen(argv[i], "r");
            (*srcs)[i].name = argv[i];
        }
        
        *count = argc;
    } else {
        *srcs = malloc(sizeof(InputSource));
        (*srcs)[0].fp = stdin;
        (*srcs)[0].name = "stdin"; 
        
        *count = 1;
    }
}






    // void parse_args(int argc, char **argv, Config *cfg)
    // {
    //     char c;
    
    //     while (--argc > 0) {
    //         if ((*++argv)[0] == '-') 
    //             while ((c = *++argv[0]))
    //                 switch(c) {
    //                 case 'n':
    //                     cfg->number = 1;
    //                     break;
    //                 case 'x':
    //                     cfg->except = 1;
    //                     break;
    //                 case 'i':
    //                     cfg->ignore_case = 1;
    //                     break;
    //                 case 'c':
    //                     cfg->mode = MODE_COUNT;
    //                     break;
    //                 default:
    //                     printf("find: illegal option %c\n", c);
    //                     cfg->file_count = -1;
    //                     argc = 0;
    //                     break;
    //                 }     
    //         else 
    //             break;
    //     }
    //     // 模式列表pattern_list
    //     // while ((*++argv)[0] != "\"") {
    //     //     cfg->pattern[i] = *++argv;
    //     // }
    //     cfg->pattern = *argv;
    
    //     cfg->file_count = argc - 1;
    //     cfg->files = ++argv;
    
    // }
