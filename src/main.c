#include <stdio.h>
#include "args.h"
#include "file.h"

int main(int argc, char **argv)
{
    Config cfg;
    init_config(&cfg);

    parse_args(argc, argv, &cfg);

    for (int i = 0; i < cfg.file_count; i++) {
        process_file(&cfg, cfg.files[i]);
    }

    return 0;
}