cmake_minimum_required (VERSION 3.16)
project (flappyy)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(OUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(IN_RES_DIR ./res)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

add_subdirectory(engine)

add_executable(flappyy source/main.cpp source/game.cpp)
target_include_directories(flappyy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(flappyy engine)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(WIN32)
        if(CMAKE_BUILD_TYPE STREQUAL "Debug")
            target_link_libraries(flappyy -Wl,-subsystem,console)
        else()
            target_link_libraries(flappyy -Wl,-subsystem,windows)
        endif()
        
    endif()
    if(UNIX)
        target_link_libraries(flappyy -ldl)
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT flappyy)
    set_property(TARGET flappyy PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()


add_custom_command(TARGET flappyy PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/res" $<TARGET_FILE_DIR:flappyy>)