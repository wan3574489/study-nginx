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
CMAKE_COMMAND = /soft/clion-2017.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /soft/clion-2017.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wanzengchuang/CLionProjects/study-nginx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Service.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Service.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Service.dir/flags.make

CMakeFiles/Service.dir/Service.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/Service.c.o: ../Service.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Service.dir/Service.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/Service.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/Service.c

CMakeFiles/Service.dir/Service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/Service.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/Service.c > CMakeFiles/Service.dir/Service.c.i

CMakeFiles/Service.dir/Service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/Service.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/Service.c -o CMakeFiles/Service.dir/Service.c.s

CMakeFiles/Service.dir/Service.c.o.requires:

.PHONY : CMakeFiles/Service.dir/Service.c.o.requires

CMakeFiles/Service.dir/Service.c.o.provides: CMakeFiles/Service.dir/Service.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/Service.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/Service.c.o.provides

CMakeFiles/Service.dir/Service.c.o.provides.build: CMakeFiles/Service.dir/Service.c.o


CMakeFiles/Service.dir/socket.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/socket.c.o: ../socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Service.dir/socket.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/socket.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/socket.c

CMakeFiles/Service.dir/socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/socket.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/socket.c > CMakeFiles/Service.dir/socket.c.i

CMakeFiles/Service.dir/socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/socket.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/socket.c -o CMakeFiles/Service.dir/socket.c.s

CMakeFiles/Service.dir/socket.c.o.requires:

.PHONY : CMakeFiles/Service.dir/socket.c.o.requires

CMakeFiles/Service.dir/socket.c.o.provides: CMakeFiles/Service.dir/socket.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/socket.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/socket.c.o.provides

CMakeFiles/Service.dir/socket.c.o.provides.build: CMakeFiles/Service.dir/socket.c.o


CMakeFiles/Service.dir/epoll.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/epoll.c.o: ../epoll.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Service.dir/epoll.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/epoll.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/epoll.c

CMakeFiles/Service.dir/epoll.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/epoll.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/epoll.c > CMakeFiles/Service.dir/epoll.c.i

CMakeFiles/Service.dir/epoll.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/epoll.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/epoll.c -o CMakeFiles/Service.dir/epoll.c.s

CMakeFiles/Service.dir/epoll.c.o.requires:

.PHONY : CMakeFiles/Service.dir/epoll.c.o.requires

CMakeFiles/Service.dir/epoll.c.o.provides: CMakeFiles/Service.dir/epoll.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/epoll.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/epoll.c.o.provides

CMakeFiles/Service.dir/epoll.c.o.provides.build: CMakeFiles/Service.dir/epoll.c.o


CMakeFiles/Service.dir/log.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/log.c.o: ../log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Service.dir/log.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/log.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/log.c

CMakeFiles/Service.dir/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/log.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/log.c > CMakeFiles/Service.dir/log.c.i

CMakeFiles/Service.dir/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/log.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/log.c -o CMakeFiles/Service.dir/log.c.s

CMakeFiles/Service.dir/log.c.o.requires:

.PHONY : CMakeFiles/Service.dir/log.c.o.requires

CMakeFiles/Service.dir/log.c.o.provides: CMakeFiles/Service.dir/log.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/log.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/log.c.o.provides

CMakeFiles/Service.dir/log.c.o.provides.build: CMakeFiles/Service.dir/log.c.o


CMakeFiles/Service.dir/cycle.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/cycle.c.o: ../cycle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Service.dir/cycle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/cycle.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/cycle.c

CMakeFiles/Service.dir/cycle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/cycle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/cycle.c > CMakeFiles/Service.dir/cycle.c.i

CMakeFiles/Service.dir/cycle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/cycle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/cycle.c -o CMakeFiles/Service.dir/cycle.c.s

CMakeFiles/Service.dir/cycle.c.o.requires:

.PHONY : CMakeFiles/Service.dir/cycle.c.o.requires

CMakeFiles/Service.dir/cycle.c.o.provides: CMakeFiles/Service.dir/cycle.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/cycle.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/cycle.c.o.provides

CMakeFiles/Service.dir/cycle.c.o.provides.build: CMakeFiles/Service.dir/cycle.c.o


CMakeFiles/Service.dir/process.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/process.c.o: ../process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Service.dir/process.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/process.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/process.c

CMakeFiles/Service.dir/process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/process.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/process.c > CMakeFiles/Service.dir/process.c.i

CMakeFiles/Service.dir/process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/process.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/process.c -o CMakeFiles/Service.dir/process.c.s

CMakeFiles/Service.dir/process.c.o.requires:

.PHONY : CMakeFiles/Service.dir/process.c.o.requires

CMakeFiles/Service.dir/process.c.o.provides: CMakeFiles/Service.dir/process.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/process.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/process.c.o.provides

CMakeFiles/Service.dir/process.c.o.provides.build: CMakeFiles/Service.dir/process.c.o


CMakeFiles/Service.dir/m_signals.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/m_signals.c.o: ../m_signals.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Service.dir/m_signals.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/m_signals.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/m_signals.c

CMakeFiles/Service.dir/m_signals.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/m_signals.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/m_signals.c > CMakeFiles/Service.dir/m_signals.c.i

CMakeFiles/Service.dir/m_signals.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/m_signals.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/m_signals.c -o CMakeFiles/Service.dir/m_signals.c.s

CMakeFiles/Service.dir/m_signals.c.o.requires:

.PHONY : CMakeFiles/Service.dir/m_signals.c.o.requires

CMakeFiles/Service.dir/m_signals.c.o.provides: CMakeFiles/Service.dir/m_signals.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/m_signals.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/m_signals.c.o.provides

CMakeFiles/Service.dir/m_signals.c.o.provides.build: CMakeFiles/Service.dir/m_signals.c.o


CMakeFiles/Service.dir/m_event.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/m_event.c.o: ../m_event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Service.dir/m_event.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/m_event.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/m_event.c

CMakeFiles/Service.dir/m_event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/m_event.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/m_event.c > CMakeFiles/Service.dir/m_event.c.i

CMakeFiles/Service.dir/m_event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/m_event.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/m_event.c -o CMakeFiles/Service.dir/m_event.c.s

CMakeFiles/Service.dir/m_event.c.o.requires:

.PHONY : CMakeFiles/Service.dir/m_event.c.o.requires

CMakeFiles/Service.dir/m_event.c.o.provides: CMakeFiles/Service.dir/m_event.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/m_event.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/m_event.c.o.provides

CMakeFiles/Service.dir/m_event.c.o.provides.build: CMakeFiles/Service.dir/m_event.c.o


CMakeFiles/Service.dir/m_shmem.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/m_shmem.c.o: ../m_shmem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Service.dir/m_shmem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/m_shmem.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/m_shmem.c

CMakeFiles/Service.dir/m_shmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/m_shmem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/m_shmem.c > CMakeFiles/Service.dir/m_shmem.c.i

CMakeFiles/Service.dir/m_shmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/m_shmem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/m_shmem.c -o CMakeFiles/Service.dir/m_shmem.c.s

CMakeFiles/Service.dir/m_shmem.c.o.requires:

.PHONY : CMakeFiles/Service.dir/m_shmem.c.o.requires

CMakeFiles/Service.dir/m_shmem.c.o.provides: CMakeFiles/Service.dir/m_shmem.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/m_shmem.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/m_shmem.c.o.provides

CMakeFiles/Service.dir/m_shmem.c.o.provides.build: CMakeFiles/Service.dir/m_shmem.c.o


CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o: ../lib/hashtable/hashtable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/lib/hashtable/hashtable.c

CMakeFiles/Service.dir/lib/hashtable/hashtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/lib/hashtable/hashtable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/lib/hashtable/hashtable.c > CMakeFiles/Service.dir/lib/hashtable/hashtable.c.i

CMakeFiles/Service.dir/lib/hashtable/hashtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/lib/hashtable/hashtable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/lib/hashtable/hashtable.c -o CMakeFiles/Service.dir/lib/hashtable/hashtable.c.s

CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.requires:

.PHONY : CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.requires

CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.provides: CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.provides

CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.provides.build: CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o


CMakeFiles/Service.dir/lib/hashtable/murmur.c.o: CMakeFiles/Service.dir/flags.make
CMakeFiles/Service.dir/lib/hashtable/murmur.c.o: ../lib/hashtable/murmur.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Service.dir/lib/hashtable/murmur.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Service.dir/lib/hashtable/murmur.c.o   -c /home/wanzengchuang/CLionProjects/study-nginx/lib/hashtable/murmur.c

CMakeFiles/Service.dir/lib/hashtable/murmur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Service.dir/lib/hashtable/murmur.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wanzengchuang/CLionProjects/study-nginx/lib/hashtable/murmur.c > CMakeFiles/Service.dir/lib/hashtable/murmur.c.i

CMakeFiles/Service.dir/lib/hashtable/murmur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Service.dir/lib/hashtable/murmur.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wanzengchuang/CLionProjects/study-nginx/lib/hashtable/murmur.c -o CMakeFiles/Service.dir/lib/hashtable/murmur.c.s

CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.requires:

.PHONY : CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.requires

CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.provides: CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.requires
	$(MAKE) -f CMakeFiles/Service.dir/build.make CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.provides.build
.PHONY : CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.provides

CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.provides.build: CMakeFiles/Service.dir/lib/hashtable/murmur.c.o


# Object files for target Service
Service_OBJECTS = \
"CMakeFiles/Service.dir/Service.c.o" \
"CMakeFiles/Service.dir/socket.c.o" \
"CMakeFiles/Service.dir/epoll.c.o" \
"CMakeFiles/Service.dir/log.c.o" \
"CMakeFiles/Service.dir/cycle.c.o" \
"CMakeFiles/Service.dir/process.c.o" \
"CMakeFiles/Service.dir/m_signals.c.o" \
"CMakeFiles/Service.dir/m_event.c.o" \
"CMakeFiles/Service.dir/m_shmem.c.o" \
"CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o" \
"CMakeFiles/Service.dir/lib/hashtable/murmur.c.o"

# External object files for target Service
Service_EXTERNAL_OBJECTS =

Service: CMakeFiles/Service.dir/Service.c.o
Service: CMakeFiles/Service.dir/socket.c.o
Service: CMakeFiles/Service.dir/epoll.c.o
Service: CMakeFiles/Service.dir/log.c.o
Service: CMakeFiles/Service.dir/cycle.c.o
Service: CMakeFiles/Service.dir/process.c.o
Service: CMakeFiles/Service.dir/m_signals.c.o
Service: CMakeFiles/Service.dir/m_event.c.o
Service: CMakeFiles/Service.dir/m_shmem.c.o
Service: CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o
Service: CMakeFiles/Service.dir/lib/hashtable/murmur.c.o
Service: CMakeFiles/Service.dir/build.make
Service: libzlog_s.a
Service: CMakeFiles/Service.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable Service"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Service.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Service.dir/build: Service

.PHONY : CMakeFiles/Service.dir/build

CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/Service.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/socket.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/epoll.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/log.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/cycle.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/process.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/m_signals.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/m_event.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/m_shmem.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/lib/hashtable/hashtable.c.o.requires
CMakeFiles/Service.dir/requires: CMakeFiles/Service.dir/lib/hashtable/murmur.c.o.requires

.PHONY : CMakeFiles/Service.dir/requires

CMakeFiles/Service.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Service.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Service.dir/clean

CMakeFiles/Service.dir/depend:
	cd /home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanzengchuang/CLionProjects/study-nginx /home/wanzengchuang/CLionProjects/study-nginx /home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug /home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug /home/wanzengchuang/CLionProjects/study-nginx/cmake-build-debug/CMakeFiles/Service.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Service.dir/depend

