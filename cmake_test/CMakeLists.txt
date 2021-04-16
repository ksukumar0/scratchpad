cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "Tutorial")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# specify the C++ standard
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

Project(${PROJECT_NAME} VERSION 3.2)

configure_file(TutorialConfig.h.in TutorialConfig.h)

set(SOURCE_FILES 
    tutorial.cpp
    )

message(STATUS "Compiling ${PROJECT_NAME}")
list(APPEND CMAKE_MESSAGE_INDENT "  ")

message(CHECK_START "Finding ${SOURCE_FILES}")

if(EXISTS ${SOURCE_FILES})
    message(CHECK_PASS "found")
else()
    message(CHECK_FAIL "not found")
endif()

# add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           )

                       #add_subdirectory(${PROJECT_BINARY_DIR})

#message(CHECK_START "Finding my things")
#list(APPEND CMAKE_MESSAGE_INDENT "  ")
#unset(missingComponents)

#list(POP_BACK CMAKE_MESSAGE_INDENT)
#if(missingComponents)
#  message(CHECK_FAIL "missing components: ${missingComponents}")
#else()
#  message(CHECK_PASS "all components found")
#endif()
