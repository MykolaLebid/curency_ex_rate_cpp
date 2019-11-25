#include<gmock/gmock.h>

#include<string>
#include<CurrencyExchange.h>
TEST(TestCurrencyExchangeStructure, SimpleTest){
	CurrencyExchange currecyEx;
	currecyEx.base="EUR";
        currecyEx.exchange= "USD";
	currecyEx.rate= "0.5";
	currecyEx.date= "12-12-21";
	std::string description = currecyEx.summaryDescription();

	ASSERT_THAT(description, testing::Eq("12-12-21: 1 EUR = 0.5 USD"));
};
