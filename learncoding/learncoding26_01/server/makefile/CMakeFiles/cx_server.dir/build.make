# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/opas/workspace/unix_network_programming/Turtle/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/opas/workspace/unix_network_programming/Turtle/server/makefile

# Include any dependencies generated for this target.
include CMakeFiles/cx_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cx_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cx_server.dir/flags.make

CMakeFiles/cx_server.dir/server.c.o: CMakeFiles/cx_server.dir/flags.make
CMakeFiles/cx_server.dir/server.c.o: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/opas/workspace/unix_network_programming/Turtle/server/makefile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cx_server.dir/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cx_server.dir/server.c.o   -c /home/opas/workspace/unix_network_programming/Turtle/server/server.c

CMakeFiles/cx_server.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cx_server.dir/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/opas/workspace/unix_network_programming/Turtle/server/server.c > CMakeFiles/cx_server.dir/server.c.i

CMakeFiles/cx_server.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cx_server.dir/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/opas/workspace/unix_network_programming/Turtle/server/server.c -o CMakeFiles/cx_server.dir/server.c.s

CMakeFiles/cx_server.dir/server.c.o.requires:

.PHONY : CMakeFiles/cx_server.dir/server.c.o.requires

CMakeFiles/cx_server.dir/server.c.o.provides: CMakeFiles/cx_server.dir/server.c.o.requires
	$(MAKE) -f CMakeFiles/cx_server.dir/build.make CMakeFiles/cx_server.dir/server.c.o.provides.build
.PHONY : CMakeFiles/cx_server.dir/server.c.o.provides

CMakeFiles/cx_server.dir/server.c.o.provides.build: CMakeFiles/cx_server.dir/server.c.o


# Object files for target cx_server
cx_server_OBJECTS = \
"CMakeFiles/cx_server.dir/server.c.o"

# External object files for target cx_server
cx_server_EXTERNAL_OBJECTS =

/home/opas/workspace/unix_network_programming/Turtle/cx_server: CMakeFiles/cx_server.dir/server.c.o
/home/opas/workspace/unix_network_programming/Turtle/cx_server: CMakeFiles/cx_server.dir/build.make
/home/opas/workspace/unix_network_programming/Turtle/cx_server: CMakeFiles/cx_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/opas/workspace/unix_network_programming/Turtle/server/makefile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/opas/workspace/unix_network_programming/Turtle/cx_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cx_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cx_server.dir/build: /home/opas/workspace/unix_network_programming/Turtle/cx_server

.PHONY : CMakeFiles/cx_server.dir/build

CMakeFiles/cx_server.dir/requires: CMakeFiles/cx_server.dir/server.c.o.requires

.PHONY : CMakeFiles/cx_server.dir/requires

CMakeFiles/cx_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cx_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cx_server.dir/clean

CMakeFiles/cx_server.dir/depend:
	cd /home/opas/workspace/unix_network_programming/Turtle/server/makefile && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/opas/workspace/unix_network_programming/Turtle/server /home/opas/workspace/unix_network_programming/Turtle/server /home/opas/workspace/unix_network_programming/Turtle/server/makefile /home/opas/workspace/unix_network_programming/Turtle/server/makefile /home/opas/workspace/unix_network_programming/Turtle/server/makefile/CMakeFiles/cx_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cx_server.dir/depend

