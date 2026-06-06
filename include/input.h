#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

// 输入抽象为输入文件流
typedef struct {
    FILE *fp;   
    char *name;
} InputSource;

// 获取文件流内容
int next_line(InputSource *src, char *buf, int size);

#endif