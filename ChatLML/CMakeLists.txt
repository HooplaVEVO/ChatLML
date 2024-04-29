
cmake_minimum_required(VERSION 3.10)
project(ChatLML)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
set(SOURCES
    main.cpp
    ChatBox.cpp
    client.cpp
    server.cpp
)

add_executable(
    chatlml

    main.cpp)

add_executable(
    chatbox_test

    ChatBox.cpp)
target_link_libraries(chatlml ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(chatbox_test ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})

if(MSVC)
    add_definitions(-D_WIN32_WINNT=0x0601)
endif()
