find_package(Boost 1.59.0 COMPONENTS program_options)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(CmdLineParser CommandLineParser.cpp)
