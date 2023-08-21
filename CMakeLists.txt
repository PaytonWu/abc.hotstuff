# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project ("hotstuff")

include(ExternalProject)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/secp256k1/include)
ExternalProject_Add(
        libsecp256k1
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/secp256k1
        CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/third_party/secp256k1/autogen.sh
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/third_party/secp256k1/configure --disable-shared --with-pic --enable-module-recovery
        BUILD_COMMAND make
        INSTALL_COMMAND ""
        BUILD_IN_SOURCE 1)
add_library(secp256k1 STATIC IMPORTED)
set_target_properties(
        secp256k1
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/secp256k1/.libs/libsecp256k1.a)
add_dependencies(secp256k1 libsecp256k1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/abc/include)

if (WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
