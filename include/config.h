#ifndef CONFIG_H
#define CONFIG_H

// #define MAX_PATTERN_LENGTH 20
// #define MAX_FILE_COUNT 5
// #define MAX_FILE_NAME_LENGTH 20
typedef enum {
    MODE_PRINT,
    MODE_COUNT
} OutputMode;

typedef struct {
    int number;
    int except;
    int ignore_case;

    OutputMode mode;
    
    char *pattern;

    char **files;
    int file_count;

} Config;


void init_config(Config *cfg);

#endif