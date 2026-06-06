#include <stdio.h>
#include "args.h"
#include "file.h"
#include "input.h"


int main(int argc, char **argv)
{
    // 初始化参数结构体
    Config cfg;
    init_config(&cfg);

    // 设置文件流数组
    InputSource *sources;
    int count;

    // 提取参数
    parse_args(argc, argv, &cfg, &sources, &count);

    // 处理所有文件流
    process_all(&cfg, sources, count);

    return 0;
}