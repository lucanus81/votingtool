#include "utils/CommandLineParser.h"

int main(int argc, char** argv)
{
    cmdline_parser parser;
    if (!parser.parse("test"))
        return -1;
    return 0;
}
