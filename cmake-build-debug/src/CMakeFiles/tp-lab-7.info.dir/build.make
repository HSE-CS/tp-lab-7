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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\tp-lab-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\tp-lab-7\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/tp-lab-7.info.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/tp-lab-7.info.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/tp-lab-7.info.dir/flags.make

src/CMakeFiles/tp-lab-7.info.dir/main.cpp.obj: src/CMakeFiles/tp-lab-7.info.dir/flags.make
src/CMakeFiles/tp-lab-7.info.dir/main.cpp.obj: src/CMakeFiles/tp-lab-7.info.dir/includes_CXX.rsp
src/CMakeFiles/tp-lab-7.info.dir/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\tp-lab-7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/tp-lab-7.info.dir/main.cpp.obj"
	cd /d C:\tp-lab-7\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tp-lab-7.info.dir\main.cpp.obj -c C:\tp-lab-7\src\main.cpp

src/CMakeFiles/tp-lab-7.info.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tp-lab-7.info.dir/main.cpp.i"
	cd /d C:\tp-lab-7\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\tp-lab-7\src\main.cpp > CMakeFiles\tp-lab-7.info.dir\main.cpp.i

src/CMakeFiles/tp-lab-7.info.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tp-lab-7.info.dir/main.cpp.s"
	cd /d C:\tp-lab-7\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\tp-lab-7\src\main.cpp -o CMakeFiles\tp-lab-7.info.dir\main.cpp.s

# Object files for target tp-lab-7.info
tp__lab__7_info_OBJECTS = \
"CMakeFiles/tp-lab-7.info.dir/main.cpp.obj"

# External object files for target tp-lab-7.info
tp__lab__7_info_EXTERNAL_OBJECTS =

src/tp-lab-7.info.exe: src/CMakeFiles/tp-lab-7.info.dir/main.cpp.obj
src/tp-lab-7.info.exe: src/CMakeFiles/tp-lab-7.info.dir/build.make
src/tp-lab-7.info.exe: src/libtp-lab-7.dll.a
src/tp-lab-7.info.exe: src/CMakeFiles/tp-lab-7.info.dir/linklibs.rsp
src/tp-lab-7.info.exe: src/CMakeFiles/tp-lab-7.info.dir/objects1.rsp
src/tp-lab-7.info.exe: src/CMakeFiles/tp-lab-7.info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\tp-lab-7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tp-lab-7.info.exe"
	cd /d C:\tp-lab-7\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tp-lab-7.info.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/tp-lab-7.info.dir/build: src/tp-lab-7.info.exe

.PHONY : src/CMakeFiles/tp-lab-7.info.dir/build

src/CMakeFiles/tp-lab-7.info.dir/clean:
	cd /d C:\tp-lab-7\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\tp-lab-7.info.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/tp-lab-7.info.dir/clean

src/CMakeFiles/tp-lab-7.info.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\tp-lab-7 C:\tp-lab-7\src C:\tp-lab-7\cmake-build-debug C:\tp-lab-7\cmake-build-debug\src C:\tp-lab-7\cmake-build-debug\src\CMakeFiles\tp-lab-7.info.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/tp-lab-7.info.dir/depend

