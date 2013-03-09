cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pp6calculator)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

include_directories(FileReader)
include_directories(PP6Lib)

add_subdirectory(PP6Lib)
add_subdirectory(FileReader)

add_executable(pp6calculator pp6calculator.cpp)

target_link_libraries(pp6calculator pp6lib FileReader)

install(TARGETS pp6calculator DESTINATION bin)

include(CPack)
