cmake_minimum_required(VERSION 3.1)
option(TNN_OPENVINO_ENABLE "with openvino lib" OFF)
option(TNN_OPENVINO_LIB_PATH "openvino lib path" "")
option(TNN_DEMO_WITH_OPENCV "with opencv" OFF)

set(CMAKE_CXX_STANDARD 11)
set(TNN_CPU_ENABLE ON)

if (TNN_DEMO_WITH_OPENCV)
    find_package(OpenCV 4 REQUIRED)
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /w")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -std=c++11 -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -pthread -fPIC")
endif()
include_directories(${CMAKE_CURRENT_LIST_DIR}/base
                    ${CMAKE_CURRENT_LIST_DIR}/utils)

file(GLOB_RECURSE BASE_SRC
                    "${CMAKE_CURRENT_LIST_DIR}/base/*.cc")

file(GLOB_RECURSE UTIL_SRC
                   "${CMAKE_CURRENT_LIST_DIR}/utils/*.cc")


if (TNN_DEMO_WITH_OPENCV)
    add_definitions(-D_OPENCV_)
endif()

add_executable(demo_x86_imageclassify TNNImageClassify.cc ${BASE_SRC} ${UTIL_SRC})
target_link_libraries(demo_x86_imageclassify TNN)

