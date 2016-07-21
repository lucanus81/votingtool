cmake_minimum_required(VERSION 3.6)
add_definitions( -std=c++14 )

project(VotingTool)

add_subdirectory(utils)

include_directories("${PROJECT_SOURCE_DIR}/utils")

find_package(Boost 1.59.0 COMPONENTS program_options)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(server main.cpp)
add_executable(client main.cpp)
target_link_libraries(server CmdLineParser)
target_link_libraries(server ${Boost_LIBRARIES})

target_link_libraries(client CmdLineParser)
target_link_libraries(client ${Boost_LIBRARIES})
