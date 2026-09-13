add_library(work STATIC work.cpp)
target_include_directories(work PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(blake3-wide main.cpp)
target_link_libraries(blake3-wide PRIVATE work)
