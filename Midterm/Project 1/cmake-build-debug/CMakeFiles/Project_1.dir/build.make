# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\raula\GitHub\CS151\Midterm\Project 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\raula\GitHub\CS151\Midterm\Project 1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_1.dir/flags.make

CMakeFiles/Project_1.dir/midterm_project1.cpp.obj: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/midterm_project1.cpp.obj: ../midterm_project1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\raula\GitHub\CS151\Midterm\Project 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_1.dir/midterm_project1.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project_1.dir\midterm_project1.cpp.obj -c "C:\Users\raula\GitHub\CS151\Midterm\Project 1\midterm_project1.cpp"

CMakeFiles/Project_1.dir/midterm_project1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/midterm_project1.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\raula\GitHub\CS151\Midterm\Project 1\midterm_project1.cpp" > CMakeFiles\Project_1.dir\midterm_project1.cpp.i

CMakeFiles/Project_1.dir/midterm_project1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/midterm_project1.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\raula\GitHub\CS151\Midterm\Project 1\midterm_project1.cpp" -o CMakeFiles\Project_1.dir\midterm_project1.cpp.s

# Object files for target Project_1
Project_1_OBJECTS = \
"CMakeFiles/Project_1.dir/midterm_project1.cpp.obj"

# External object files for target Project_1
Project_1_EXTERNAL_OBJECTS =

Project_1.exe: CMakeFiles/Project_1.dir/midterm_project1.cpp.obj
Project_1.exe: CMakeFiles/Project_1.dir/build.make
Project_1.exe: CMakeFiles/Project_1.dir/linklibs.rsp
Project_1.exe: CMakeFiles/Project_1.dir/objects1.rsp
Project_1.exe: CMakeFiles/Project_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\raula\GitHub\CS151\Midterm\Project 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_1.dir/build: Project_1.exe

.PHONY : CMakeFiles/Project_1.dir/build

CMakeFiles/Project_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project_1.dir/clean

CMakeFiles/Project_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\raula\GitHub\CS151\Midterm\Project 1" "C:\Users\raula\GitHub\CS151\Midterm\Project 1" "C:\Users\raula\GitHub\CS151\Midterm\Project 1\cmake-build-debug" "C:\Users\raula\GitHub\CS151\Midterm\Project 1\cmake-build-debug" "C:\Users\raula\GitHub\CS151\Midterm\Project 1\cmake-build-debug\CMakeFiles\Project_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project_1.dir/depend

