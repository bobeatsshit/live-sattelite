cmake_minimum_required(VERSION 3.10)

# Set the policy to use GLVND by default
if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

project(sattelitegui)

set(CMAKE_CXX_STANDARD 17)

# Set the CMAKE_PREFIX_PATH to include vcpkg installed packages
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows" ${CMAKE_PREFIX_PATH})

add_executable(sattelitegui main.cpp apicaller.h
        apicaller.cpp)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(CURL REQUIRED)

target_link_libraries(sattelitegui PRIVATE imgui::imgui glfw GLEW::GLEW CURL::libcurl ${OPENGL_LIBRARIES})

set(IMGUI_SOURCES
        ${CMAKE_SOURCE_DIR}/imgui.cpp
        ${CMAKE_SOURCE_DIR}/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/imgui_widgets.cpp
        ${CMAKE_SOURCE_DIR}/imgui_demo.cpp
        ${CMAKE_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

target_sources(sattelitegui PRIVATE ${IMGUI_SOURCES})