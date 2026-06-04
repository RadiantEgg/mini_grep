#ifndef CONFIG_H
#define CONFIG_H

// #define MAX_PATTERN_LENGTH 20
// #define MAX_FILE_COUNT 5
// #define MAX_FILE_NAME_LENGTH 20

typedef struct {
    int number;
    int except;
    int ignore_case;
    char *pattern;

    char **files;
    int file_count;
} Config;

void init_config(Config *cfg);

#endif