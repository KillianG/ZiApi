# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/killian/TEK/3/ZiApi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/killian/TEK/3/ZiApi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ZiApi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ZiApi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZiApi.dir/flags.make

CMakeFiles/ZiApi.dir/main.cpp.o: CMakeFiles/ZiApi.dir/flags.make
CMakeFiles/ZiApi.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/killian/TEK/3/ZiApi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZiApi.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZiApi.dir/main.cpp.o -c /home/killian/TEK/3/ZiApi/main.cpp

CMakeFiles/ZiApi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZiApi.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/killian/TEK/3/ZiApi/main.cpp > CMakeFiles/ZiApi.dir/main.cpp.i

CMakeFiles/ZiApi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZiApi.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/killian/TEK/3/ZiApi/main.cpp -o CMakeFiles/ZiApi.dir/main.cpp.s

# Object files for target ZiApi
ZiApi_OBJECTS = \
"CMakeFiles/ZiApi.dir/main.cpp.o"

# External object files for target ZiApi
ZiApi_EXTERNAL_OBJECTS =

ZiApi: CMakeFiles/ZiApi.dir/main.cpp.o
ZiApi: CMakeFiles/ZiApi.dir/build.make
ZiApi: CMakeFiles/ZiApi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/killian/TEK/3/ZiApi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ZiApi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ZiApi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZiApi.dir/build: ZiApi

.PHONY : CMakeFiles/ZiApi.dir/build

CMakeFiles/ZiApi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ZiApi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ZiApi.dir/clean

CMakeFiles/ZiApi.dir/depend:
	cd /home/killian/TEK/3/ZiApi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killian/TEK/3/ZiApi /home/killian/TEK/3/ZiApi /home/killian/TEK/3/ZiApi/cmake-build-debug /home/killian/TEK/3/ZiApi/cmake-build-debug /home/killian/TEK/3/ZiApi/cmake-build-debug/CMakeFiles/ZiApi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZiApi.dir/depend

