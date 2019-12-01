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
	    #jsoncpp_lib_static) 

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
	    libcurl)

#head-only library 
add_library(currency_exchange_service INTERFACE)
target_include_directories(
	    currency_exchange_service
	    INTERFACE
	    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/currency_exchange>)

#Aliases for installing and packaging
add_library(currency_exchange::service ALIAS currency_exchange_service)
add_library(currency_exchange::curl_http ALIAS curl_http)
add_library(currency_exchange::extractor ALIAS 
	                                 currency_exchange_extractor)
   

