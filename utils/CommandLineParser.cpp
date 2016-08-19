#include "CommandLineParser.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <exception>

cmdline_parser::cmdline_parser(int argc, char** argv)
{
    namespace po = boost::program_options;

    help_.add_options()
        (cmdline_options::to_string(cmdline_options::options::help).c_str(), 
            "This help message")
        (cmdline_options::to_string(cmdline_options::options::hostname).c_str(), 
            po::value<std::string>(), 
            "Server hostname we connect to")
        (cmdline_options::to_string(cmdline_options::options::port).c_str(), 
            po::value<unsigned short>(), 
            "Server port we connect to")
        (cmdline_options::to_string(cmdline_options::options::username).c_str(), 
            po::value<std::string>(), 
            "Username - case sensitive")
        (cmdline_options::to_string(cmdline_options::options::password).c_str(), 
            po::value<std::string>(), 
            "Password - case sensitive");

    po::variables_map vm;
    try 
    {
        po::store(po::parse_command_line(argc, argv, help_), vm);
        po::notify(vm);
    }
    catch (const po::error& ex)
    {
        std::cerr <<"Error: " <<ex.what() <<"\n";
        parsing_status_ = status::error;
    }
    
    if (what() != status::error)
        parsing_status_ = is_cmd_help(vm) ? status::help : status::ok;
}

bool cmdline_parser::all_options_available(boost::program_options::variables_map const& vm) const
{
    constexpr std::array<cmdline_options::options, 4> opts{
        cmdline_options::options::hostname, cmdline_options::options::port, 
        cmdline_options::options::username, cmdline_options::options::password};
    
    return std::none_of(opts.cbegin(), opts.cend(), 
        [&vm](auto opt) {
            return 0 == vm.count(cmdline_options::to_string(opt));
        });
}

/*
 * @note: we show the help when
 * - we select the --help option, or
 * - we do not select any option (empty command line), or
 * - when we have an invalid combination of options.
 */
bool cmdline_parser::is_cmd_help(boost::program_options::variables_map const& vm) const
{
    return 0 == vm.size() || 
        1 == vm.count(cmdline_options::to_string(cmdline_options::options::help)) ||
        !all_options_available(vm);
}

std::string cmdline_parser::cmd_line() const
{
    std::ostringstream full_command_line;
    help_.print(full_command_line);

    return full_command_line.str();
}


