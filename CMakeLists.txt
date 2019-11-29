cmake_minimum_required(VERSION 3.15)
project(pointers C)

set(CMAKE_C_STANDARD 99)

add_executable(pointers main.c)

add_library( bolib SHARED IMPORTED )

set_target_properties( bolib PROPERTIES IMPORTED_LOCATION /Users/oketo/CLionProjects/bolib/cmake-build-debug/libbolib.dylib)

target_link_libraries(
        # Specifies the target library.
        pointers

        # Links the target library
        bolib)