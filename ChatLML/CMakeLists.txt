<<<<<<< HEAD

cmake_minimum_required(VERSION 3.10)
project(ChatLML)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
set(SOURCES
    main.cpp
    ChatBox.cpp
    client.cpp
    server.cpp
)

add_executable(
    chatlml

    main.cpp)
  

if(MSVC)
    add_definitions(-D_WIN32_WINNT=0x0601)
endif()
=======
add_executable(chatlml main.cpp server.cpp client.cpp ChatBox.cpp)
>>>>>>> 5c335656ccc7f003d8945cb69c6b5b1abad3e61b
