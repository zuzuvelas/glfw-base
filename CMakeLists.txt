cmake_minimum_required(VERSION 3.6)
project(project1)

set(CMAKE_CXX_STANDARD 11)

#include_directories(lib)

find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp
        src/setup.cpp)
add_executable(project1 ${SOURCE_FILES})

target_link_libraries(project1 ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} glfw)