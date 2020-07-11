cmake_minimum_required(VERSION 3.1)
project(Metal-Shape-Solid)

IF (WIN32)
    # If you want to link SFML statically
    set(SFML_STATIC_LIBRARIES TRUE)

    # In most cases better set in the CMake cache
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")

    find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
ENDIF()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Add more as needed
include_directories(${PROJECT_SOURCE_DIR}/includes)

# C++ 17 standard
set(CMAKE_CXX_STANDARD 17)

# Include all .cpp and .h in src and include directories respectively
file(GLOB
        SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp
        INCLUDE_FILES ${PROJECT_SOURCE_DIR}/src/*.h
        )

add_executable(Metal-Shape-Solid
        ${SRC_FILES}
        ${INCLUDE_FILES}
        )

target_link_libraries(Metal-Shape-Solid sfml-main sfml-graphics sfml-window sfml-system sfml-audio sfml-network)