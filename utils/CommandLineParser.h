#ifndef _COMMAND_LINE_PARSER_H
#define _COMMAND_LINE_PARSER_H

#include "boost/program_options.hpp"
#include <array>

struct cmdline_parser 
{
    cmdline_parser(const cmdline_parser&) = delete;
    cmdline_parser(cmdline_parser&& ) = delete;
    cmdline_parser& operator=(const cmdline_parser&) = delete;
    cmdline_parser& operator=(cmdline_parser&&) = delete;
    ~cmdline_parser() = default;

    cmdline_parser(int argc, char** argv);
    std::string cmd_line() const;
    bool is_cmd_help() const { return help_required_; }

private:
    boost::program_options::options_description help_{"Allowed options"};
    bool help_required_{ false };

    bool is_cmd_help(boost::program_options::variables_map const& vm) const;
    bool all_options_available(boost::program_options::variables_map const& vm) const;

    struct cmdline_options 
    {
        enum class options { help, hostname, port, username, password };

        static std::string to_string(cmdline_options::options op) {
            static const std::array<std::string, 5> option_names{ "help", "hostname", "port", "username", "password" };
            return option_names[static_cast<std::size_t>(op)];
        }
    };
};

#endif
