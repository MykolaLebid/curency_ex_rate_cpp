
#set(CURL_INCLUDE_DIR "${CMAKE_BINARY_DIR}/_deps/curl-src/include")
#include_directories(CURL_INCLUDE_DIR)
#message(STATUS "set CURL_INCLUDE_DIR=${CURL_INCLUDE_DIR}")

# download Google Test sources on code project repo 
# at configure time using FetchContent
include(FetchContent)
FetchContent_Declare(
	curl 
	GIT_REPOSITORY https://github.com/curl/curl.git
	GIT_TAG 2e9b725f67d49a9d7a1f053fe52dd4920c9ab1ad # curl-7.67.0
)
message(STATUS "fetch content of GIT_REPOSITORY https://github.com/curl/curl.git")

# allows the project to check whether a particular dependency has already been 
# populated and also retrieve some directory details 
FetchContent_GetProperties(curl)

if(NOT curl_POPUTATED)
    message(STATUS "curl is populating")
    FetchContent_Populate(curl) 
    
    
    message(STATUS "curl_SOURCE_DIR=${curl_SOURCE_DIR}")
    message(STATUS "curl_BINARY_DIR=${curl_BINARY_DIR}")
    # adds the targers: 
    add_subdirectory(
      ${curl_SOURCE_DIR}
      ${curl_BINARY_DIR}
    )
else()

    message(STATUS "curl_POPUTATED=${curl_POPUTATED}")
    message(STATUS "curl is installed")
     
    message(STATUS "curl_SOURCE_DIR=${curl_SOURCE_DIR}")
    message(STATUS "curl_BINARY_DIR=${curl_BINARY_DIR}")
   
endif()
