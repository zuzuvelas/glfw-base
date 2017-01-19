cmake_minimum_required(VERSION 3.6)
project(project1)

set(CMAKE_CXX_STANDARD 11)

if (WIN32)
    include_directories(lib/)
    set(CMAKE_EXE_LINKER_FLAGS -static) # Should be Windows only (probably)
    include_directories(${GLM_INCLUDE_DIRS})

    set(GLFW glfw3)
else()
    if (CMAKE_INSTALL_PREFIX MATCHES mingw)
        message("--------------------")
        message("MinGW windows target")
        message("--------------------")

        # Hack it into working
        include_directories(lib/)
        set(CMAKE_EXE_LINKER_FLAGS -static)
    else ()
        find_package(glm REQUIRED)
        include_directories(${GLM_INCLUDE_DIRS})
    endif ()

    set(GLFW glfw)
    find_package(glfw3 REQUIRED)
endif()

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp
        src/setup.cpp)
add_executable(project1 ${SOURCE_FILES})

target_link_libraries(project1 ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLFW})