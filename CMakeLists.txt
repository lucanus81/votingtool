cmake_minimum_required(VERSION 3.6)
add_definitions( -std=c++14 )

project(VotingTool)

add_subdirectory(utils)

include_directories("${PROJECT_SOURCE_DIR}/utils")
add_executable(server main.cpp)
add_executable(client main.cpp)
target_link_libraries(server CmdLineParser)
target_link_libraries(client CmdLineParser)
