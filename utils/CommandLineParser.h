#ifndef _COMMAND_LINE_PARSER_H
#define _COMMAND_LINE_PARSER_H

#include "boost/program_options.hpp"
#include <array>
#include <tuple>

struct cmdline_parser 
{
    enum class status { ok, help, error, uninitialized };

    cmdline_parser(const cmdline_parser&) = delete;
    cmdline_parser(cmdline_parser&& ) = delete;
    cmdline_parser& operator=(const cmdline_parser&) = delete;
    cmdline_parser& operator=(cmdline_parser&&) = delete;
    ~cmdline_parser() = default;

    cmdline_parser(int argc, char** argv);
    std::string cmd_line() const;
    status what() const { return parsing_status_; }

private:
    boost::program_options::options_description help_{"Allowed options"};
    status parsing_status_{status::uninitialized};

    bool is_cmd_help(boost::program_options::variables_map const& vm) const;
    bool all_options_available(boost::program_options::variables_map const& vm) const;
};

#endif
