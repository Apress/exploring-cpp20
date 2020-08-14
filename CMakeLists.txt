# CMakeLists.txt for Exploring C++ 20.

# Need a fairly new release of Cmake to get C++ 20-ish support.
cmake_minimum_required(VERSION 3.16)

# This is the first version of CMakeLists.txt, but the third
# release of the code examples, so let's call this version 3.0.
project(ExploringCpp VERSION 3.0)

# There is no reason to build the book's examples in anything
# other than Debug mode.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Debug")
endif()

# Compile using #include directives vs. modules.
set(MODULES "No" CACHE STRING
	"Set to TRUE or YES to compile using modules and import declarations. FALSE or NO compiles using #include directives.")

# Many of the listings and snippets have tests that are independent
# of the book. The tests are my way to help ensure that the
# code is more or less correct.
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

# Testing on Linux with clang++ and g++ prereleases.
# Testing on Windows with Microsoft Visual C++ pending release of support for C++ 20.
# As of 2020-05-10, modules work only with GNU 11 pre-release
# as built from the current devel/c++-modules branch.

if (MSVC)
    # Maximum warnings and treat all warnings as errors.
    # Use standard C++ exception handling.
    # Turn off extensions to the standard.
    add_compile_options(/EHsc /Za /Wall /WX)
	if (MODULES)
		add_compile_options(/experimental:modules)
		message(WARNING "Visual C++ does not fully support modules. Compilation is unlikely to succeed.")
	endif()
else()
    # Maximum warnings and treat all warnings as errors
    # Adhere strictly to language standards.
    add_compile_options(-Wall -Wextra -pedantic -Werror)
    if (MODULES)
		add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fmodules-ts")
		add_compile_options("$<$<CXX_COMPILER_ID:Clang>:-fmodules>")
		message(WARNING "${CMAKE_CXX_COMPILER_ID} does not fully support modules. Compilation is unlikely to succeed.")
    endif()
endif()


# Run a test.
# Tests have two forms: executable or text.
# An executable test is just a shell script that is run with
# the target name as the sole argument.
# A text test is the name of a text file that is the expected
# output that results when running ./${name}. The input
# to the program is ${name}.input if the file exists or
# /dev/null otherwise. The run_test script takes the name
# of the test file as an argument, and performs the indicated test.
#
# In order to test on Windows, the command processor must be
# set to a compatible shell, and compatible tools must be on the PATH.
# Recommendation is to use a Linux Subsystem or cygwin.
function(run_test name)
  add_test(NAME test_${name}
    COMMAND python3 ${DOCUMENT_DIR}/run_test.py ${name}.test ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
  )
  set_tests_properties(test_${name}
    PROPERTIES
      REQUIRED_FILES ${CMAKE_CURRENT_SOURCE_DIR}/${name}.test
    )
endfunction(run_test)

# Every chapter's CMakeLists.txt file contains mostly a series of
# example() functions calls, one per ".cpp" file.
# The first argument to example() is the name, e.g., list0401.
# Subsequent arguments can be additional dependencies or
# compile options. Detect options as strings that begin
# with "-" or "/". Generator expressions select options
# on a per-compiler basis in each CMakeLists.txt file,
# so also look for "$"
function(example name)
	set(file_args)
	set(option_args)
	foreach(arg ${ARGN})
		string(SUBSTRING ${arg} 0 1 first_char)
		if(${first_char} STREQUAL "-" OR ${first_char} STREQUAL "/" OR ${first_char} STREQUAL "$")
			list(APPEND option_args ${arg})
		else()
			list(APPEND file_args ${arg})
		endif()
	endforeach()
    add_executable(${name} ${name}.cpp ${file_args})
    target_compile_options(${name} PUBLIC ${option_args})

    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.test)
        run_test(${name})
    endif()
endfunction()

function(chapter number)
	add_subdirectory(chap${number})
endfunction()

# All the individual chapter files are subdirectories,
# which helps manage the plethora of files.
if (MODULES)
	add_subdirectory(code-modules)
else()
	add_subdirectory(code-preprocessor)
endif()
