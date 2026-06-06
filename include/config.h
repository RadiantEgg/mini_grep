#ifndef CONFIG_H
#define CONFIG_H

// 输出模式: 查找 or 计数
typedef enum {
    MODE_PRINT,
    MODE_COUNT
} OutputMode;


// 参数
typedef struct {
    int number;         // -n 输出行数
    int except;         // -x 反向输出
    int ignore_case;    // -i 忽略大小写

    OutputMode mode;    // 输出模式
    
    char *pattern;      // 匹配目标

    char **files;       // 查询文件
    int file_count;     // 问价个数

} Config;

// 初始化
void init_config(Config *cfg);

#endif