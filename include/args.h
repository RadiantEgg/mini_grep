#ifndef ARGS_H
#define ARGS_H

#include "config.h"
#include "input.h"

// 参数提取
void parse_args(int argc, char **argv, Config *cfg, InputSource **srcs, int *count);

#endif