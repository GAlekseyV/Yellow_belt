# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Work\Projects\coursera\Yellow_belt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Work\Projects\coursera\Yellow_belt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Week_4_task_9_names_surnames_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Week_4_task_9_names_surnames_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Week_4_task_9_names_surnames_4.dir/flags.make

CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.obj: CMakeFiles/Week_4_task_9_names_surnames_4.dir/flags.make
CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.obj: ../Week_4/task_9_names_surnames_4/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Work\Projects\coursera\Yellow_belt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.obj"
	C:\Qt\Tools\mingw730_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Week_4_task_9_names_surnames_4.dir\Week_4\task_9_names_surnames_4\main.cpp.obj -c D:\Work\Projects\coursera\Yellow_belt\Week_4\task_9_names_surnames_4\main.cpp

CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.i"
	C:\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Work\Projects\coursera\Yellow_belt\Week_4\task_9_names_surnames_4\main.cpp > CMakeFiles\Week_4_task_9_names_surnames_4.dir\Week_4\task_9_names_surnames_4\main.cpp.i

CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.s"
	C:\Qt\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Work\Projects\coursera\Yellow_belt\Week_4\task_9_names_surnames_4\main.cpp -o CMakeFiles\Week_4_task_9_names_surnames_4.dir\Week_4\task_9_names_surnames_4\main.cpp.s

# Object files for target Week_4_task_9_names_surnames_4
Week_4_task_9_names_surnames_4_OBJECTS = \
"CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.obj"

# External object files for target Week_4_task_9_names_surnames_4
Week_4_task_9_names_surnames_4_EXTERNAL_OBJECTS =

Week_4_task_9_names_surnames_4.exe: CMakeFiles/Week_4_task_9_names_surnames_4.dir/Week_4/task_9_names_surnames_4/main.cpp.obj
Week_4_task_9_names_surnames_4.exe: CMakeFiles/Week_4_task_9_names_surnames_4.dir/build.make
Week_4_task_9_names_surnames_4.exe: CMakeFiles/Week_4_task_9_names_surnames_4.dir/linklibs.rsp
Week_4_task_9_names_surnames_4.exe: CMakeFiles/Week_4_task_9_names_surnames_4.dir/objects1.rsp
Week_4_task_9_names_surnames_4.exe: CMakeFiles/Week_4_task_9_names_surnames_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Work\Projects\coursera\Yellow_belt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Week_4_task_9_names_surnames_4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Week_4_task_9_names_surnames_4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Week_4_task_9_names_surnames_4.dir/build: Week_4_task_9_names_surnames_4.exe

.PHONY : CMakeFiles/Week_4_task_9_names_surnames_4.dir/build

CMakeFiles/Week_4_task_9_names_surnames_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Week_4_task_9_names_surnames_4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Week_4_task_9_names_surnames_4.dir/clean

CMakeFiles/Week_4_task_9_names_surnames_4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Work\Projects\coursera\Yellow_belt D:\Work\Projects\coursera\Yellow_belt D:\Work\Projects\coursera\Yellow_belt\cmake-build-debug D:\Work\Projects\coursera\Yellow_belt\cmake-build-debug D:\Work\Projects\coursera\Yellow_belt\cmake-build-debug\CMakeFiles\Week_4_task_9_names_surnames_4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Week_4_task_9_names_surnames_4.dir/depend

