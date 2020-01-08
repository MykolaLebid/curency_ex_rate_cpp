add_library(currency_exchange_extractor 
	    CurrencyExchangeExtractor.cpp)
target_include_directories(
	    currency_exchange_extractor
	    PUBLIC # corresponden header needs for We're using the PUBLIC option here since this header is needed on the public interface of currency_exchange_extractor
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange>)
target_link_libraries(
	    currency_exchange_extractor
 	    PRIVATE 
	    jsoncpp)  

add_library(curl_http
	    CurlHttp.cpp)
target_include_directories(
	    curl_http
	    PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange>)
target_link_libraries(  
      	    curl_http
            PRIVATE	
	    CURL::libcurl)

add_library(currency_exchange_service
	    CurrencyExchangeService.cpp)
target_include_directories(
	    currency_exchange_service
	    PRIVATE
	    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange>)
target_link_libraries(
	       currency_exchange_service 
	       PRIVATE
	       curl_http
	       currency_exchange_extractor)
#Aliases for installing and packaging
#add_library(currency_exchange::service ALIAS currency_exchange_service)
#add_library(currency_exchange::curl_http ALIAS curl_http)
#add_library(currency_exchange::extractor ALIAS 
#	                                 currency_exchange_extractor)
   

#Installing
#message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
#set(CMAKE_MACOSX_RPATH 1)
#set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}" "${CMAKE_INSTALL_PREFIX}/lib")
#install file targets and creat target set currency_exchangeTargets
message(STATUS "install properties:")
message(STATUS "CMAKE_INSTALL_INCLUDEDIR=${CMAKE_INSTALL_INCLUDEDIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}")
message(STATUS "CMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}")
install(TARGETS 
	 currency_exchange_service 
	 curl_http 
	 currency_exchange_extractor
	EXPORT currency_exchangeTargets
      	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange)
#Set up to use libs for others 
#creat <currency_exchange>Targets.cmake
install(EXPORT currency_exchangeTargets
	FILE currency_exchangeTargets.cmake
	NAMESPACE currency_exchange::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/currency_exchange)
#
#creat <currency_exchange>Config.cmake via 
# <currency_exchange>Targets.cmake 
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../CMake/currency_exchangeConfig.cmake.in ${CMAKE_CURRENT_SOURCE_DIR}/../CMake/currency_exchangeConfig.cmake @ONLY)
	
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/../CMake/currency_exchangeConfigVersion.cmake"
	VERSION ${currency_rate_VERSION}
	COMPATIBILITY AnyNewerVersion)

install(FILES 
   "${CMAKE_CURRENT_SOURCE_DIR}/../CMake/currency_exchangeConfig.cmake"   "${CMAKE_CURRENT_SOURCE_DIR}/../CMake/currency_exchangeConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/currency_exchange)

#install(EXPORT currency_exchangeTargets
#	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/currency_exchange
#	NAMESPACE currency_exchange::
#       )
install(DIRECTORY
	${CMAKE_CURRENT_SOURCE_DIR}/
 	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange
	FILES_MATCHING
        PATTERN *.h)

#print_target_properties(currency_exchange_service)


#print_target_properties(libcurl)
#print_target_properties(curl_http)
#Exporting (there are 3 wayes to access a project from another project :1) subdirectory, 2) exported build directoies, and 3)installing)
# to use the build directory of one project in another, we need to export targets.
# exporting targets is needed for a proper install, allowing the build directory to be used as well is two added lines 
#Now, if you find_package(currency_exchange), cmake can find a build folder 
#downside: if you have imported dependencies they will need ti be imported before you find_package
#export(TARGETS  
#      	 currency_exchange_service 
#      	 curl_http 
#      	 currency_exchange_extractor
#       NAMESPACE currency_exchange::
#       FILE ${CMAKE_BINARY_DIR}/currency_exchangeTargets.cmake)
#set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
#export(PACKAGE currency_exchange)

#create a 
