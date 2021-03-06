#include "utils/CommandLineParser.h"

#include <iostream>

int main(int argc, char** argv)
{
    cmdline_parser parser{argc, argv};
    switch (parser.what()) 
    {
        case cmdline_parser::status::help:
            std::cout <<parser.cmd_line() <<std::endl;
            return -1;
        case cmdline_parser::status::error:
            return -1;
        default:
            break;
    }

    std::cout
        <<"Hostname: " <<parser.hostname() <<"\n"
        <<"    Port: " <<parser.port() <<"\n" 
        <<"Username: " <<parser.username() <<"\n"
        <<"Password: " <<parser.password() <<"\n";

    return 0;
}
