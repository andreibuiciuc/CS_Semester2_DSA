# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\DSA\Lab1-DSA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\DSA\Lab1-DSA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Lab1_DSA.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Lab1_DSA.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Lab1_DSA.dir\flags.make

CMakeFiles\Lab1_DSA.dir\App.cpp.obj: CMakeFiles\Lab1_DSA.dir\flags.make
CMakeFiles\Lab1_DSA.dir\App.cpp.obj: ..\App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab1_DSA.dir/App.cpp.obj"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab1_DSA.dir\App.cpp.obj /FdCMakeFiles\Lab1_DSA.dir\ /FS -c D:\DSA\Lab1-DSA\App.cpp
<<

CMakeFiles\Lab1_DSA.dir\App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1_DSA.dir/App.cpp.i"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" > CMakeFiles\Lab1_DSA.dir\App.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DSA\Lab1-DSA\App.cpp
<<

CMakeFiles\Lab1_DSA.dir\App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1_DSA.dir/App.cpp.s"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab1_DSA.dir\App.cpp.s /c D:\DSA\Lab1-DSA\App.cpp
<<

CMakeFiles\Lab1_DSA.dir\Bag.cpp.obj: CMakeFiles\Lab1_DSA.dir\flags.make
CMakeFiles\Lab1_DSA.dir\Bag.cpp.obj: ..\Bag.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab1_DSA.dir/Bag.cpp.obj"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab1_DSA.dir\Bag.cpp.obj /FdCMakeFiles\Lab1_DSA.dir\ /FS -c D:\DSA\Lab1-DSA\Bag.cpp
<<

CMakeFiles\Lab1_DSA.dir\Bag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1_DSA.dir/Bag.cpp.i"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" > CMakeFiles\Lab1_DSA.dir\Bag.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DSA\Lab1-DSA\Bag.cpp
<<

CMakeFiles\Lab1_DSA.dir\Bag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1_DSA.dir/Bag.cpp.s"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab1_DSA.dir\Bag.cpp.s /c D:\DSA\Lab1-DSA\Bag.cpp
<<

CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.obj: CMakeFiles\Lab1_DSA.dir\flags.make
CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.obj: ..\BagIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab1_DSA.dir/BagIterator.cpp.obj"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab1_DSA.dir\BagIterator.cpp.obj /FdCMakeFiles\Lab1_DSA.dir\ /FS -c D:\DSA\Lab1-DSA\BagIterator.cpp
<<

CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1_DSA.dir/BagIterator.cpp.i"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" > CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DSA\Lab1-DSA\BagIterator.cpp
<<

CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1_DSA.dir/BagIterator.cpp.s"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab1_DSA.dir\BagIterator.cpp.s /c D:\DSA\Lab1-DSA\BagIterator.cpp
<<

CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.obj: CMakeFiles\Lab1_DSA.dir\flags.make
CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.obj: ..\ExtendedTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab1_DSA.dir/ExtendedTest.cpp.obj"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.obj /FdCMakeFiles\Lab1_DSA.dir\ /FS -c D:\DSA\Lab1-DSA\ExtendedTest.cpp
<<

CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1_DSA.dir/ExtendedTest.cpp.i"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" > CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DSA\Lab1-DSA\ExtendedTest.cpp
<<

CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1_DSA.dir/ExtendedTest.cpp.s"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.s /c D:\DSA\Lab1-DSA\ExtendedTest.cpp
<<

CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.obj: CMakeFiles\Lab1_DSA.dir\flags.make
CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.obj: ..\ShortTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Lab1_DSA.dir/ShortTest.cpp.obj"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Lab1_DSA.dir\ShortTest.cpp.obj /FdCMakeFiles\Lab1_DSA.dir\ /FS -c D:\DSA\Lab1-DSA\ShortTest.cpp
<<

CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1_DSA.dir/ShortTest.cpp.i"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" > CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\DSA\Lab1-DSA\ShortTest.cpp
<<

CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1_DSA.dir/ShortTest.cpp.s"
	"D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Lab1_DSA.dir\ShortTest.cpp.s /c D:\DSA\Lab1-DSA\ShortTest.cpp
<<

# Object files for target Lab1_DSA
Lab1_DSA_OBJECTS = \
"CMakeFiles\Lab1_DSA.dir\App.cpp.obj" \
"CMakeFiles\Lab1_DSA.dir\Bag.cpp.obj" \
"CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.obj" \
"CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.obj" \
"CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.obj"

# External object files for target Lab1_DSA
Lab1_DSA_EXTERNAL_OBJECTS =

Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\App.cpp.obj
Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\Bag.cpp.obj
Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\BagIterator.cpp.obj
Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\ExtendedTest.cpp.obj
Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\ShortTest.cpp.obj
Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\build.make
Lab1_DSA.exe: CMakeFiles\Lab1_DSA.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Lab1_DSA.exe"
	"D:\CLion\CLion\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Lab1_DSA.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- "D:\Programming\Visual Studio Community\VC\Tools\MSVC\14.26.28801\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\Lab1_DSA.dir\objects1.rsp @<<
 /out:Lab1_DSA.exe /implib:Lab1_DSA.lib /pdb:D:\DSA\Lab1-DSA\cmake-build-debug\Lab1_DSA.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Lab1_DSA.dir\build: Lab1_DSA.exe

.PHONY : CMakeFiles\Lab1_DSA.dir\build

CMakeFiles\Lab1_DSA.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab1_DSA.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Lab1_DSA.dir\clean

CMakeFiles\Lab1_DSA.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\DSA\Lab1-DSA D:\DSA\Lab1-DSA D:\DSA\Lab1-DSA\cmake-build-debug D:\DSA\Lab1-DSA\cmake-build-debug D:\DSA\Lab1-DSA\cmake-build-debug\CMakeFiles\Lab1_DSA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Lab1_DSA.dir\depend
