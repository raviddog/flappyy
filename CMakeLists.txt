cmake_minimum_required (VERSION 3.16)
project (flappyy)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(OUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(IN_RES_DIR ./res)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

add_library(engine STATIC engine/engine_gl.cpp engine/engine.cpp engine/glad.c engine/stb_image.cpp engine/debug.cpp)
target_include_directories(engine PUBLIC ./engine)
set_property(TARGET engine PROPERTY CXX_STANDARD 17)
set_property(TARGET engine PROPERTY CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_include_directories(engine PUBLIC    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/um"
                                                "C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/shared"
                                                "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.18362.0/um/x64")
    target_link_libraries(engine winmm.lib)
endif()
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(UNIX)
        target_link_libraries(engine -lglfw)
    endif()
    if(WIN32)
        target_link_libraries(engine -lmingw32 -lglfw3)
    endif()
endif()


add_executable(flappyy source/main.cpp source/game.cpp)
target_include_directories(flappyy PUBLIC .)
target_link_libraries(flappyy engine)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(WIN32)
        target_link_libraries(flappyy -Wl,-subsystem,console)
    endif()
    if(UNIX)
        target_link_libraries(flappyy -Wl,-subsystem -ldl)
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT flappyy)
    set_property(TARGET flappyy PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()


add_custom_command(TARGET flappyy PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/res" $<TARGET_FILE_DIR:flappyy>)