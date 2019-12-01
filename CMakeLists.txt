cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(currency_rate LANGUAGES C CXX)
set(currency_rate VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#define binary and library paths according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set(RELATIVE_PATH relDir
	${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_INSTALL_BINDIR}
	${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_INSTALL_RPATH $ORIGIN $ORIGIN/${relDir})

#add funcions of CMake files from  CMake directory 
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
include(TargetProperties)

# contains an "external" library we will link to
add_subdirectory(external)

# defines targets and sources
add_subdirectory(src)

# enable testing and define tests
enable_testing()
add_subdirectory(tests)

#installing
install(TARGETS currency_exchange_service 
	        curl_http 
	        currency_exchange_extractor
	EXPORT currency_exchange
      	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
	                                   currency_exchange
	)
install(EXPORT currency_exchange
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/currency_exchange
	NAMESPACE currency_exchange::
       )
install(DIRECTORY
	${CMAKE_CURRENT_SOURCE_DIR}/src/
 	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange
	FILES_MATCHING
	PATTERN *.h)
#CPack part
#create CPackConfig.cmake
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	add_subdirectory(packaging) # include (CPack) will happen in here

endif()
if(WIN32)
	set(CPACK_GENERATOR ZIP WIX)
elseif(APPLE)
	set(CPACK_GENERATOR TGZ productbuild)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(CPACK_RMP_COMPONENT_INSTALL YES)
        message(STATUS "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")
	set(CPACK_GENERATOR TGZ RPM)
else()
	set(CPACK_GENERATOR TGZ)
endif()
