# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmesg/ChatLML/ChatLML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmesg/ChatLML/build/bin

# Include any dependencies generated for this target.
include CMakeFiles/chatlml.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chatlml.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chatlml.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chatlml.dir/flags.make

CMakeFiles/chatlml.dir/main.cpp.o: CMakeFiles/chatlml.dir/flags.make
CMakeFiles/chatlml.dir/main.cpp.o: /home/dmesg/ChatLML/ChatLML/main.cpp
CMakeFiles/chatlml.dir/main.cpp.o: CMakeFiles/chatlml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmesg/ChatLML/build/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chatlml.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chatlml.dir/main.cpp.o -MF CMakeFiles/chatlml.dir/main.cpp.o.d -o CMakeFiles/chatlml.dir/main.cpp.o -c /home/dmesg/ChatLML/ChatLML/main.cpp

CMakeFiles/chatlml.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chatlml.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmesg/ChatLML/ChatLML/main.cpp > CMakeFiles/chatlml.dir/main.cpp.i

CMakeFiles/chatlml.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chatlml.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmesg/ChatLML/ChatLML/main.cpp -o CMakeFiles/chatlml.dir/main.cpp.s

# Object files for target chatlml
chatlml_OBJECTS = \
"CMakeFiles/chatlml.dir/main.cpp.o"

# External object files for target chatlml
chatlml_EXTERNAL_OBJECTS =

chatlml: CMakeFiles/chatlml.dir/main.cpp.o
chatlml: CMakeFiles/chatlml.dir/build.make
chatlml: /usr/lib/x86_64-linux-gnu/libfltk_images.so
chatlml: /usr/lib/x86_64-linux-gnu/libfltk_forms.so
chatlml: /usr/lib/x86_64-linux-gnu/libfltk_gl.so
chatlml: /usr/lib/x86_64-linux-gnu/libGL.so
chatlml: /usr/lib/x86_64-linux-gnu/libfltk.so
chatlml: /usr/lib/x86_64-linux-gnu/libX11.so
chatlml: /usr/lib/x86_64-linux-gnu/libm.so
chatlml: /usr/lib/x86_64-linux-gnu/libGL.so
chatlml: /usr/lib/x86_64-linux-gnu/libGLU.so
chatlml: /usr/lib/x86_64-linux-gnu/libX11.so
chatlml: /usr/lib/x86_64-linux-gnu/libm.so
chatlml: /usr/lib/x86_64-linux-gnu/libGLU.so
chatlml: CMakeFiles/chatlml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmesg/ChatLML/build/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chatlml"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chatlml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chatlml.dir/build: chatlml
.PHONY : CMakeFiles/chatlml.dir/build

CMakeFiles/chatlml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chatlml.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chatlml.dir/clean

CMakeFiles/chatlml.dir/depend:
	cd /home/dmesg/ChatLML/build/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmesg/ChatLML/ChatLML /home/dmesg/ChatLML/ChatLML /home/dmesg/ChatLML/build/bin /home/dmesg/ChatLML/build/bin /home/dmesg/ChatLML/build/bin/CMakeFiles/chatlml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chatlml.dir/depend
