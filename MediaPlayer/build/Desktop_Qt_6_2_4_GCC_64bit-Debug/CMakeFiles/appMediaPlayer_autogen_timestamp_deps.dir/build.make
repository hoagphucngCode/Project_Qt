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
CMAKE_COMMAND = /home/fr/Qt/Tools/CMake/bin/cmake

# The command to remove a file.
RM = /home/fr/Qt/Tools/CMake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fr/Downloads/MediaPlayer/MediaPlayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug

# Utility rule file for appMediaPlayer_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/progress.make

CMakeFiles/appMediaPlayer_autogen_timestamp_deps: .rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp

.rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp: /home/fr/Qt/6.2.4/gcc_64/libexec/qmlcachegen
.rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp: .rcc/qmlcache/appMediaPlayer_qml_loader_file_list.rsp
.rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp: .rcc/qmake_MediaPlayer.qrc
.rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp: .rcc/appMediaPlayer_raw_qml_0.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating .rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp"
	/home/fr/Qt/6.2.4/gcc_64/libexec/qmlcachegen --resource-name qmlcache_appMediaPlayer --resource /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug/.rcc/qmake_MediaPlayer.qrc --resource /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug/.rcc/appMediaPlayer_raw_qml_0.qrc -o /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug/.rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp @/home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug/.rcc/qmlcache/appMediaPlayer_qml_loader_file_list.rsp

appMediaPlayer_autogen_timestamp_deps: .rcc/qmlcache/appMediaPlayer_qmlcache_loader.cpp
appMediaPlayer_autogen_timestamp_deps: CMakeFiles/appMediaPlayer_autogen_timestamp_deps
appMediaPlayer_autogen_timestamp_deps: CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/build.make
.PHONY : appMediaPlayer_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/build: appMediaPlayer_autogen_timestamp_deps
.PHONY : CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/build

CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/clean

CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/depend:
	cd /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fr/Downloads/MediaPlayer/MediaPlayer /home/fr/Downloads/MediaPlayer/MediaPlayer /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug /home/fr/Downloads/MediaPlayer/MediaPlayer/build/Desktop_Qt_6_2_4_GCC_64bit-Debug/CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/appMediaPlayer_autogen_timestamp_deps.dir/depend

