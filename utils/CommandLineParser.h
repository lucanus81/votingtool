#ifndef _COMMAND_LINE_PARSER_H
#define _COMMAND_LINE_PARSER_H

#include <string>
#include "boost/program_options.hpp"

struct cmdline_parser 
{
    cmdline_parser(const cmdline_parser&) = default;
    cmdline_parser(cmdline_parser&& ) = default;
    cmdline_parser& operator=(const cmdline_parser&) = default;
    cmdline_parser& operator=(cmdline_parser&&) = default;
    ~cmdline_parser() = default;

    cmdline_parser(int argc, char** argv);

private:
    boost::program_options::options_description help_{"Allowed options"};        
};

#endif
