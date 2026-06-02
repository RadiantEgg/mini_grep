#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int number;
    int except;
    char *pattern;

    char **files;
    int file_count;
} Config;

#endif