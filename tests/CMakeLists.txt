add_executable(blake3-wide_tests test_core.cpp)
target_link_libraries(blake3-wide_tests PRIVATE work)
target_include_directories(blake3-wide_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND blake3-wide_tests)
