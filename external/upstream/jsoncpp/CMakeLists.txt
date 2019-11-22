# download JsonCpp parser sources on code project repo 
# at configure time using FetchContent
include(FetchContent)
FetchContent_Declare(
	json_cpp 
	GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
	GIT_TAG        a679dde58d675e75eaf0fe31f62e833868e2f22
)
message(STATUS "fetch content of GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp 1.8.1")

# allows the project to check whether a particular dependency has already been 
# populated and also retrieve some directory details 
FetchContent_GetProperties(json_cpp)

if(NOT json_cpp_POPUTATED)
    message(STATUS "JsonCpp is populating")
    FetchContent_Populate(json_cpp) 
    
    
    message(STATUS "json_cpp_SOURCE_DIR=${json_cpp_SOURCE_DIR}")
    message(STATUS "json_cpp_BINARY_DIR=${json_cpp_BINARY_DIR}")
    # adds the targers: 
    add_subdirectory(
      ${json_cpp_SOURCE_DIR}
      ${json_cpp_BINARY_DIR}
    )
else()

    message(STATUS "json_cpp_POPUTATED=${json_cpp_POPUTATED}")
    message(STATUS "json_cpp is installed")
     
    message(STATUS "json_cpp_SOURCE_DIR=${json_cpp_SOURCE_DIR}")
    message(STATUS "json_cpp_BINARY_DIR=${json_cpp_BINARY_DIR}")
   
endif()
