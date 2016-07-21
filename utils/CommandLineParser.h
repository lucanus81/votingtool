#ifndef _COMMAND_LINE_PARSER_H
#define _COMMAND_LINE_PARSER_H

#include <string>

struct cmdline_parser 
{
    bool parse(const std::string& line);
};

#endif
