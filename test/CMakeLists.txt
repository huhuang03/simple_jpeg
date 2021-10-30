set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# how to do the var args, and you should update the live template.
function(addTest name srcs)
    add_executable(
            ${name}
            ${srcs}
    )

    target_link_libraries(
            ${name}
            gtest_main
            simple_jpg_lib
    )

    gtest_discover_tests(${name})
    target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
endfunction()

addTest(test_huffman_encoding test_huffman_encoding.cc)