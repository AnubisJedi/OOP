# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /workspaces/OOP/lr7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/OOP/lr7/build

# Include any dependencies generated for this target.
include CMakeFiles/lab_7_lib_NPC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab_7_lib_NPC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_7_lib_NPC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_7_lib_NPC.dir/flags.make

CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o: CMakeFiles/lab_7_lib_NPC.dir/flags.make
CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o: /workspaces/OOP/lr7/src/NPC.cpp
CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o: CMakeFiles/lab_7_lib_NPC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/OOP/lr7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o -MF CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o.d -o CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o -c /workspaces/OOP/lr7/src/NPC.cpp

CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/OOP/lr7/src/NPC.cpp > CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.i

CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/OOP/lr7/src/NPC.cpp -o CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.s

# Object files for target lab_7_lib_NPC
lab_7_lib_NPC_OBJECTS = \
"CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o"

# External object files for target lab_7_lib_NPC
lab_7_lib_NPC_EXTERNAL_OBJECTS =

liblab_7_lib_NPC.a: CMakeFiles/lab_7_lib_NPC.dir/src/NPC.cpp.o
liblab_7_lib_NPC.a: CMakeFiles/lab_7_lib_NPC.dir/build.make
liblab_7_lib_NPC.a: CMakeFiles/lab_7_lib_NPC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/OOP/lr7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab_7_lib_NPC.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab_7_lib_NPC.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_7_lib_NPC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_7_lib_NPC.dir/build: liblab_7_lib_NPC.a
.PHONY : CMakeFiles/lab_7_lib_NPC.dir/build

CMakeFiles/lab_7_lib_NPC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_7_lib_NPC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_7_lib_NPC.dir/clean

CMakeFiles/lab_7_lib_NPC.dir/depend:
	cd /workspaces/OOP/lr7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/OOP/lr7 /workspaces/OOP/lr7 /workspaces/OOP/lr7/build /workspaces/OOP/lr7/build /workspaces/OOP/lr7/build/CMakeFiles/lab_7_lib_NPC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_7_lib_NPC.dir/depend

