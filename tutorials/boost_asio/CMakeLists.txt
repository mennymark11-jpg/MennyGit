add_library(beginer_ex INTERFACE)

target_include_directories(beginer_ex   
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Tests
add_executable(beginer_ex_test
    src/beginer_ex.cpp
    tst/beginer_ex_test.cpp
)

target_link_libraries(beginer_ex_test
    PRIVATE
        beginer_ex
        test_utils
)

add_test(
    NAME beginer_ex_test
    COMMAND beginer_ex_test
)




