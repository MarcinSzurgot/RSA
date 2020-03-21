cmake_minimum_required(VERSION 3.12)
project(RSA)

include(FetchContent)

set(OLD_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

FetchContent_Declare(
    bignum
    GIT_REPOSITORY https://github.com/MarcinSzurgot/bignum
)

FetchContent_Populate(bignum)
add_subdirectory(
    ${bignum_SOURCE_DIR}
    ${bignum_BINARY_DIR}
)

set(CXX_ERROR_FLAGS
"-pedantic \
-Wall \
-Wcast-align \
-Wcast-qual \
-Wctor-dtor-privacy \
-Wdisabled-optimization \
-Wextra \
-Wformat=2 \
-Winit-self \
-Wlogical-op \
-Wmissing-declarations \
-Wmissing-include-dirs \
-Wnoexcept \
-Wno-unused \
-Wno-int-in-bool-context \
-Wold-style-cast \
-Woverloaded-virtual \
-Wredundant-decls \
-Wshadow \
-Wsign-conversion \
-Wsign-promo \
-Wstrict-null-sentinel \
-Wstrict-overflow=5 \
-Wundef"
)

set(CMAKE_CXX_FLAGS "${OLD_CMAKE_CXX_FLAGS} ${CXX_ERROR_FLAGS}")

add_executable(
    ${CMAKE_PROJECT_NAME} 
    main.cpp
)

set_target_properties(
    ${CMAKE_PROJECT_NAME} 
        PROPERTIES 
            CXX_STANDARD 17
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
        bignum
)