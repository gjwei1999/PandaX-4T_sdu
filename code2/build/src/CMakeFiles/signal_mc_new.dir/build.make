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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build

# Include any dependencies generated for this target.
include src/CMakeFiles/signal_mc_new.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/signal_mc_new.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/signal_mc_new.dir/flags.make

src/CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.o: src/CMakeFiles/signal_mc_new.dir/flags.make
src/CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.o: ../src/signal_mc_new.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.o"
	cd /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.o -c /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/src/signal_mc_new.cc

src/CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.i"
	cd /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/src/signal_mc_new.cc > CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.i

src/CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.s"
	cd /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/src/signal_mc_new.cc -o CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.s

# Object files for target signal_mc_new
signal_mc_new_OBJECTS = \
"CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.o"

# External object files for target signal_mc_new
signal_mc_new_EXTERNAL_OBJECTS =

src/signal_mc_new: src/CMakeFiles/signal_mc_new.dir/signal_mc_new.cc.o
src/signal_mc_new: src/CMakeFiles/signal_mc_new.dir/build.make
src/signal_mc_new: src/libpandax-quanta.a
src/signal_mc_new: src/libdet-sim.a
src/signal_mc_new: /Applications/root_v6.22.06/lib/libCore.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libImt.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libRIO.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libNet.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libHist.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libGraf.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libGraf3d.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libGpad.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libROOTDataFrame.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libTree.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libTreePlayer.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libRint.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libPostscript.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libMatrix.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libPhysics.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libMathCore.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libThread.so
src/signal_mc_new: /Applications/root_v6.22.06/lib/libMultiProc.so
src/signal_mc_new: src/CMakeFiles/signal_mc_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable signal_mc_new"
	cd /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/signal_mc_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/signal_mc_new.dir/build: src/signal_mc_new

.PHONY : src/CMakeFiles/signal_mc_new.dir/build

src/CMakeFiles/signal_mc_new.dir/clean:
	cd /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/signal_mc_new.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/signal_mc_new.dir/clean

src/CMakeFiles/signal_mc_new.dir/depend:
	cd /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2 /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/src /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src /Users/jiaweiguo/Documents/GitHub/SNEW_PandaX/code2/build/src/CMakeFiles/signal_mc_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/signal_mc_new.dir/depend

