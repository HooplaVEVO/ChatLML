# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/ChatLML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/ChatLML

# Include any dependencies generated for this target.
include ChatLML/CMakeFiles/chatlml.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ChatLML/CMakeFiles/chatlml.dir/compiler_depend.make

# Include the progress variables for this target.
include ChatLML/CMakeFiles/chatlml.dir/progress.make

# Include the compile flags for this target's objects.
include ChatLML/CMakeFiles/chatlml.dir/flags.make

ChatLML/CMakeFiles/chatlml.dir/main.o: ChatLML/CMakeFiles/chatlml.dir/flags.make
ChatLML/CMakeFiles/chatlml.dir/main.o: ChatLML/main.cpp
ChatLML/CMakeFiles/chatlml.dir/main.o: ChatLML/CMakeFiles/chatlml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/ChatLML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ChatLML/CMakeFiles/chatlml.dir/main.o"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ChatLML/CMakeFiles/chatlml.dir/main.o -MF CMakeFiles/chatlml.dir/main.o.d -o CMakeFiles/chatlml.dir/main.o -c /workspace/ChatLML/ChatLML/main.cpp

ChatLML/CMakeFiles/chatlml.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chatlml.dir/main.i"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/ChatLML/ChatLML/main.cpp > CMakeFiles/chatlml.dir/main.i

ChatLML/CMakeFiles/chatlml.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chatlml.dir/main.s"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/ChatLML/ChatLML/main.cpp -o CMakeFiles/chatlml.dir/main.s

ChatLML/CMakeFiles/chatlml.dir/server.o: ChatLML/CMakeFiles/chatlml.dir/flags.make
ChatLML/CMakeFiles/chatlml.dir/server.o: ChatLML/server.cpp
ChatLML/CMakeFiles/chatlml.dir/server.o: ChatLML/CMakeFiles/chatlml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/ChatLML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ChatLML/CMakeFiles/chatlml.dir/server.o"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ChatLML/CMakeFiles/chatlml.dir/server.o -MF CMakeFiles/chatlml.dir/server.o.d -o CMakeFiles/chatlml.dir/server.o -c /workspace/ChatLML/ChatLML/server.cpp

ChatLML/CMakeFiles/chatlml.dir/server.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chatlml.dir/server.i"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/ChatLML/ChatLML/server.cpp > CMakeFiles/chatlml.dir/server.i

ChatLML/CMakeFiles/chatlml.dir/server.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chatlml.dir/server.s"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/ChatLML/ChatLML/server.cpp -o CMakeFiles/chatlml.dir/server.s

ChatLML/CMakeFiles/chatlml.dir/client.o: ChatLML/CMakeFiles/chatlml.dir/flags.make
ChatLML/CMakeFiles/chatlml.dir/client.o: ChatLML/client.cpp
ChatLML/CMakeFiles/chatlml.dir/client.o: ChatLML/CMakeFiles/chatlml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/ChatLML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object ChatLML/CMakeFiles/chatlml.dir/client.o"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ChatLML/CMakeFiles/chatlml.dir/client.o -MF CMakeFiles/chatlml.dir/client.o.d -o CMakeFiles/chatlml.dir/client.o -c /workspace/ChatLML/ChatLML/client.cpp

ChatLML/CMakeFiles/chatlml.dir/client.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chatlml.dir/client.i"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/ChatLML/ChatLML/client.cpp > CMakeFiles/chatlml.dir/client.i

ChatLML/CMakeFiles/chatlml.dir/client.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chatlml.dir/client.s"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/ChatLML/ChatLML/client.cpp -o CMakeFiles/chatlml.dir/client.s

ChatLML/CMakeFiles/chatlml.dir/ChatBox.o: ChatLML/CMakeFiles/chatlml.dir/flags.make
ChatLML/CMakeFiles/chatlml.dir/ChatBox.o: ChatLML/ChatBox.cpp
ChatLML/CMakeFiles/chatlml.dir/ChatBox.o: ChatLML/CMakeFiles/chatlml.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/ChatLML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object ChatLML/CMakeFiles/chatlml.dir/ChatBox.o"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ChatLML/CMakeFiles/chatlml.dir/ChatBox.o -MF CMakeFiles/chatlml.dir/ChatBox.o.d -o CMakeFiles/chatlml.dir/ChatBox.o -c /workspace/ChatLML/ChatLML/ChatBox.cpp

ChatLML/CMakeFiles/chatlml.dir/ChatBox.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chatlml.dir/ChatBox.i"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/ChatLML/ChatLML/ChatBox.cpp > CMakeFiles/chatlml.dir/ChatBox.i

ChatLML/CMakeFiles/chatlml.dir/ChatBox.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chatlml.dir/ChatBox.s"
	cd /workspace/ChatLML/ChatLML && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/ChatLML/ChatLML/ChatBox.cpp -o CMakeFiles/chatlml.dir/ChatBox.s

# Object files for target chatlml
chatlml_OBJECTS = \
"CMakeFiles/chatlml.dir/main.o" \
"CMakeFiles/chatlml.dir/server.o" \
"CMakeFiles/chatlml.dir/client.o" \
"CMakeFiles/chatlml.dir/ChatBox.o"

# External object files for target chatlml
chatlml_EXTERNAL_OBJECTS =

ChatLML/chatlml: ChatLML/CMakeFiles/chatlml.dir/main.o
ChatLML/chatlml: ChatLML/CMakeFiles/chatlml.dir/server.o
ChatLML/chatlml: ChatLML/CMakeFiles/chatlml.dir/client.o
ChatLML/chatlml: ChatLML/CMakeFiles/chatlml.dir/ChatBox.o
ChatLML/chatlml: ChatLML/CMakeFiles/chatlml.dir/build.make
ChatLML/chatlml: ChatLML/CMakeFiles/chatlml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspace/ChatLML/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable chatlml"
	cd /workspace/ChatLML/ChatLML && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chatlml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ChatLML/CMakeFiles/chatlml.dir/build: ChatLML/chatlml
.PHONY : ChatLML/CMakeFiles/chatlml.dir/build

ChatLML/CMakeFiles/chatlml.dir/clean:
	cd /workspace/ChatLML/ChatLML && $(CMAKE_COMMAND) -P CMakeFiles/chatlml.dir/cmake_clean.cmake
.PHONY : ChatLML/CMakeFiles/chatlml.dir/clean

ChatLML/CMakeFiles/chatlml.dir/depend:
	cd /workspace/ChatLML && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/ChatLML /workspace/ChatLML/ChatLML /workspace/ChatLML /workspace/ChatLML/ChatLML /workspace/ChatLML/ChatLML/CMakeFiles/chatlml.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : ChatLML/CMakeFiles/chatlml.dir/depend

