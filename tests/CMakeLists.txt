 #add include files (.h) in target(future executabe) test_curreny_exchage 
 include_directories (${PROJECT_SOURCE_DIR}/src)
 
 add_executable(test_currency_exchange "")
 target_sources(test_currency_exchange
	PRIVATE
	MainTest.cpp
	CurrencyExchangeServiceTest.cpp	
	CurrencyExtractorTest.cpp
	# CurrencyExService.cpp
	# CurrencyExExtractor.cpp	

	# tweet.cpp
	# tweet_test.cpp

	# tweet_collection.cpp
	# tweet_collection_test.cpp
	)
target_include_directories(test_currency_exchange 
	                   PUBLIC 
			   ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(test_currency_exchange
 	PRIVATE
 	gmock_main
	currency_exchange_extractor
 )
 enable_testing()
 
 add_test(
 	NAME google_test
 	COMMAND $<TARGET_FILE:test_currency_exchange>
 )
	
