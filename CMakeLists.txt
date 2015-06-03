cmake_minimum_required(VERSION 3.2)
project(JettisonedJoysticks)

# Ensure SDL2 can be found normally, regardless of OS.
# Note: custom setup of the SDL2 variable may be required.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${JettisonedJoysticks_SOURCE_DIR}/CMake/Modules")

# Ensure no in-source build.
# http://stackoverflow.com/q/1208681/445373
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif()

# Set SDL2 set up.
find_package(SDL2 REQUIRED)

add_subdirectory(src)

