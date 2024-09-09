cmake_minimum_required(VERSION 3.10)
project(moderncpp)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()
# 发现所有子目录
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
list(REMOVE_ITEM SUBDIRS "include")
list(REMOVE_ITEM SUBDIRS "cpp20")

# # Include all .hpp files in the include/ directory
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# set(LIBRARY_NAME "${PROJECT_NAME}")
# # Add source files in the lib/ directory
# file(GLOB LIBSOURCES ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp)
# # Create the library
# add_library(${LIBRARY_NAME} ${LIBSOURCES})

# 循环添加每个子目录的可执行文件
foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        message(SUBDIR: ${SUBDIR})
        # 设置可执行文件名称
        set(EXECUTABLE_NAME ${SUBDIR})

        # 添加子目录中的源文件
        file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/*.cpp)
        if (SOURCES)
            # 创建可执行文件
            add_executable(${EXECUTABLE_NAME} ${SOURCES})
            # 链接所需库(如有需要)
            target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})
        endif()
    endif()
endforeach()

add_subdirectory(cpp20)