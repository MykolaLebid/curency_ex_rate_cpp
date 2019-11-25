add_library(currency_exchange_extractor
	    CurrencyExchangeExtractor.cpp)
target_include_directories(
	    currency_exchange_extractor
	    PRIVATE
	    ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(
	    currency_exchange_extractor
 	    PRIVATE #jsoncpp    
	    jsoncpp_lib_static) 

add_library(curl_http
	    CurlHttp.cpp)
target_include_directories(
	    curl_http
	    PRIVATE
	    ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(  
      	    curl_http
            PRIVATE	
	    libcurl)
	    	
    #add_library(currency_exchange_service 
    #	    CurrencyExchangeService.cpp)
    #target_include_directories(
    #	    currency_exchange_service
    #	    PRIVATE
    #	    ${PROJECT_SOURCE_DIR}/src)


#target_sources(cpp_main
#  PRIVATE
#  main.cpp
#)
#if (TARGET libcurl)
#  target_link_libraries(cpp_main
#    PRIVATE
#    libcurl
#  )
#else()
#  message(STATUS "taget libcurl isn't exists")	
#endif()

