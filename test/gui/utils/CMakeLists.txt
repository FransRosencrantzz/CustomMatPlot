add_library(test_utils INTERFACE)

target_sources(test_utils PRIVATE 
                          test_utils.h
                          test_macros.h)

target_include_directories(test_utils PUBLIC INTERFACE ./)