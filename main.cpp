#include "utils/CommandLineParser.h"

#include <iostream>

int main(int argc, char** argv)
{
    cmdline_parser parser{argc, argv};
    if (parser.is_cmd_help())
        std::cout <<parser.cmd_line() <<std::endl;
    return 0;
}
