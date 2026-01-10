# Generic Stack - header only library
add_library(generic_stack INTERFACE)

target_include_directories(generic_stack
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Tests
add_executable(generic_stack_test
    tst/generic_stack_test.cpp
)

target_link_libraries(generic_stack_test
    PRIVATE
        generic_stack
        test_utils
)

add_test(
    NAME generic_stack_test
    COMMAND generic_stack_test
)




