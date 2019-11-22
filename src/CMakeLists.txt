#add_executable(cpp_main "")
add_library(currency_exchange_extractor
	 CurrencyExchangeExtractor.cpp
	    #	    HttpFactory.cpp
	    #    CurrencyExService.cpp
	    #CurlHttp.cpp)
	    )
#print_target_properties(jsoncpp_lib_static)
target_include_directories(currency_exchange_extractor
	PRIVATE
	${PROJECT_SOURCE_DIR}/src)

target_link_libraries(currency_exchange_extractor
	PRIVATE
	jsoncpp_lib_static
	#jsoncpp	
	)    
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


