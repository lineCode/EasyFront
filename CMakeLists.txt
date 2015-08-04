####################################################################
#
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#####################################################
# 针对项目进行的设置
# 
# 项目名称为EasyFront
# 在该cmake脚本当中引用源码根目录可以使用${EasyFront_SOURCE_DIR}变量。
# 引用生成目录可以使用${EasyFront_BINARY_DIR}目录。
PROJECT(EasyFront C CXX)

#cmake版本应在2.8以上
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0 FATAL_ERROR)

# 将工程src暴露在外面以便能够引用
INCLUDE_DIRECTORIES("${EasyFront_SOURCE_DIR}/src")

# 添加cmake模块目录
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

SET(CMAKE_BUILD_TYPE Debug) #生成debug版本

AUX_SOURCE_DIRECTORY(src src)
FILE(GLOB_RECURSE header_src src/*.h)

SET(SRC_LIST 
    ${src}
    )

SET(HEADERS
    ${header_src}
    )

if(MSVC)
    ADD_EXECUTABLE(EasyFront ${SRC_LIST} ${HEADERS})
else(MSVC)
    ADD_EXECUTABLE(EasyFront ${SRC_LIST})
endif(MSVC)


