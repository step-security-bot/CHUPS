# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.19.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.19.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arthur/Desktop/CHUPS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arthur/Desktop/CHUPS/build

# Include any dependencies generated for this target.
include CMakeFiles/CHUPS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CHUPS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CHUPS.dir/flags.make

CMakeFiles/CHUPS.dir/src/main.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CHUPS.dir/src/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/main.c.o -c /Users/arthur/Desktop/CHUPS/src/main.c

CMakeFiles/CHUPS.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/main.c > CMakeFiles/CHUPS.dir/src/main.c.i

CMakeFiles/CHUPS.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/main.c -o CMakeFiles/CHUPS.dir/src/main.c.s

CMakeFiles/CHUPS.dir/src/textcolor.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/textcolor.c.o: ../src/textcolor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CHUPS.dir/src/textcolor.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/textcolor.c.o -c /Users/arthur/Desktop/CHUPS/src/textcolor.c

CMakeFiles/CHUPS.dir/src/textcolor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/textcolor.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/textcolor.c > CMakeFiles/CHUPS.dir/src/textcolor.c.i

CMakeFiles/CHUPS.dir/src/textcolor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/textcolor.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/textcolor.c -o CMakeFiles/CHUPS.dir/src/textcolor.c.s

CMakeFiles/CHUPS.dir/src/common.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/common.c.o: ../src/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CHUPS.dir/src/common.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/common.c.o -c /Users/arthur/Desktop/CHUPS/src/common.c

CMakeFiles/CHUPS.dir/src/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/common.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/common.c > CMakeFiles/CHUPS.dir/src/common.c.i

CMakeFiles/CHUPS.dir/src/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/common.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/common.c -o CMakeFiles/CHUPS.dir/src/common.c.s

CMakeFiles/CHUPS.dir/src/host.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/host.c.o: ../src/host.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/CHUPS.dir/src/host.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/host.c.o -c /Users/arthur/Desktop/CHUPS/src/host.c

CMakeFiles/CHUPS.dir/src/host.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/host.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/host.c > CMakeFiles/CHUPS.dir/src/host.c.i

CMakeFiles/CHUPS.dir/src/host.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/host.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/host.c -o CMakeFiles/CHUPS.dir/src/host.c.s

CMakeFiles/CHUPS.dir/src/synack.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/synack.c.o: ../src/synack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/CHUPS.dir/src/synack.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/synack.c.o -c /Users/arthur/Desktop/CHUPS/src/synack.c

CMakeFiles/CHUPS.dir/src/synack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/synack.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/synack.c > CMakeFiles/CHUPS.dir/src/synack.c.i

CMakeFiles/CHUPS.dir/src/synack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/synack.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/synack.c -o CMakeFiles/CHUPS.dir/src/synack.c.s

CMakeFiles/CHUPS.dir/src/menu.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/menu.c.o: ../src/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/CHUPS.dir/src/menu.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/menu.c.o -c /Users/arthur/Desktop/CHUPS/src/menu.c

CMakeFiles/CHUPS.dir/src/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/menu.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/menu.c > CMakeFiles/CHUPS.dir/src/menu.c.i

CMakeFiles/CHUPS.dir/src/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/menu.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/menu.c -o CMakeFiles/CHUPS.dir/src/menu.c.s

CMakeFiles/CHUPS.dir/src/file.c.o: CMakeFiles/CHUPS.dir/flags.make
CMakeFiles/CHUPS.dir/src/file.c.o: ../src/file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/CHUPS.dir/src/file.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CHUPS.dir/src/file.c.o -c /Users/arthur/Desktop/CHUPS/src/file.c

CMakeFiles/CHUPS.dir/src/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CHUPS.dir/src/file.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/arthur/Desktop/CHUPS/src/file.c > CMakeFiles/CHUPS.dir/src/file.c.i

CMakeFiles/CHUPS.dir/src/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CHUPS.dir/src/file.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/arthur/Desktop/CHUPS/src/file.c -o CMakeFiles/CHUPS.dir/src/file.c.s

# Object files for target CHUPS
CHUPS_OBJECTS = \
"CMakeFiles/CHUPS.dir/src/main.c.o" \
"CMakeFiles/CHUPS.dir/src/textcolor.c.o" \
"CMakeFiles/CHUPS.dir/src/common.c.o" \
"CMakeFiles/CHUPS.dir/src/host.c.o" \
"CMakeFiles/CHUPS.dir/src/synack.c.o" \
"CMakeFiles/CHUPS.dir/src/menu.c.o" \
"CMakeFiles/CHUPS.dir/src/file.c.o"

# External object files for target CHUPS
CHUPS_EXTERNAL_OBJECTS =

bin/CHUPS: CMakeFiles/CHUPS.dir/src/main.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/src/textcolor.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/src/common.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/src/host.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/src/synack.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/src/menu.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/src/file.c.o
bin/CHUPS: CMakeFiles/CHUPS.dir/build.make
bin/CHUPS: CMakeFiles/CHUPS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arthur/Desktop/CHUPS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable bin/CHUPS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CHUPS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CHUPS.dir/build: bin/CHUPS

.PHONY : CMakeFiles/CHUPS.dir/build

CMakeFiles/CHUPS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CHUPS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CHUPS.dir/clean

CMakeFiles/CHUPS.dir/depend:
	cd /Users/arthur/Desktop/CHUPS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arthur/Desktop/CHUPS /Users/arthur/Desktop/CHUPS /Users/arthur/Desktop/CHUPS/build /Users/arthur/Desktop/CHUPS/build /Users/arthur/Desktop/CHUPS/build/CMakeFiles/CHUPS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CHUPS.dir/depend

