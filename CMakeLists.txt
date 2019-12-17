cmake_minimum_required(VERSION 3.14 FATAL_ERROR)


# CMAKE_MODULE_PATH is a CMAKE variable. It contains a list of paths 
# which could be used to search CMAKE modules by "include()" or "find_package()", but the default value is empty.
# Add cmake dir to search list
# Add funcions of CMake files from CMake directory (CMake dir to searchlist)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

include(HunterGate)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
    SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

project(currency_rate LANGUAGES C CXX)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.
	             ${PROJECT_VERSION_MINOR}.
		     ${PROJECT_VERSION_PATCH}")
set(currency_rate VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# git is required for Android builds and building third-party dependencies
find_package(Git)

#define binary and library paths according to GNU standards
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})


# We need the following external libs for project targets
# 1) curl(http client) for connection with a RESTful API 
# 2) jsoncpp to parse json messages
hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)
hunter_add_package(jsoncpp)
find_package(jsoncpp CONFIG REQUIRED)

# defines targets and add source files
add_subdirectory(src)

#add external dependencies for the testing
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
find_package(GMock CONFIG REQUIRED)
# enable testing and define tests
enable_testing()
add_subdirectory(tests)


#CPack part
#create CPackConfig.cmake
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	add_subdirectory(packaging) # include (CPack) will happen in here

endif()
if(WIN32)
	message(STATUS "WIN32 Packaging")
	set(CPACK_GENERATOR ZIP WIX)
elseif(APPLE)
	message(STATUS "APPLE Packaging")
	set(CPACK_GENERATOR TGZ productbuild)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	message(STATUS "Linux Packaging")
	set(CPACK_RMP_COMPONENT_INSTALL YES)
        message(STATUS "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")
	set(CPACK_GENERATOR TGZ RPM)
else()	
	message(STATUS "Unknown Packaging")
	set(CPACK_GENERATOR TGZ)
endif()
