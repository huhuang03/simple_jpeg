add_library(simple_jpeg_lib huffman_encoding.cc)
add_executable(simple_jpeg main.cc huffman_encoding.cc)