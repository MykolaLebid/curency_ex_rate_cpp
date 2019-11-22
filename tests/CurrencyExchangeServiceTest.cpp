//#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Http.h"
#include "CurrencyExchangeService.h"
#include "CurrencyExchange.h"

class HttpStub: public Http {
	public:
	void initialize() override {};
	std::string get(const std::string& url) const override {
		return R"({"base":"EUR","rates":{"USD":1.3874},"date":"2010-10-08"})";	
	};
};



class TestCurrencyExchangeService: public testing::Test {
public:
	CurrencyExchangeServiceTemplate<HttpStub> currency_exchange_service;
};


TEST_F(TestCurrencyExchangeService, ReturnsCurrencyExRateForEURandUSD) {
	std::string description = currency_exchange_service.
		summaryDescription("EUR", "USD", "2010-10-08");
	ASSERT_THAT(description, testing::Eq("2010-10-08: 1 EUR = 1.3874 USD"));
}
//------------------------------------------------------------
class HttpMock: public Http {
public:
   MOCK_METHOD0(initialize, void());
   MOCK_CONST_METHOD1(get, std::string(const std::string&));
};

class ACurrencyExchangeDescriptionService: public testing::Test{
public:
	static const std::string ValidBaseCurrency;
	static const std::string ValidExchangeCurrency;
	static const std::string ValidDate;
};

class ACurrencyExchangeDescriptionService_WithHttpMock: 
	public ACurrencyExchangeDescriptionService{
public:
	CurrencyExchangeServiceTemplate<HttpMock> service;
};

TEST_F(ACurrencyExchangeDescriptionService_WithHttpMock, 
      FormatsRetrievedAddressIntoSummaryDescription) {
   EXPECT_CALL(service.http(), get(testing::_))
      .WillOnce(testing::Return(
	R"({"base":"EUR",
            "rates":{
               "USD":1.38},
             "date":"2010-10-08"})"));			      
   auto description = service.summaryDescription(
		   ValidBaseCurrency,
		   ValidExchangeCurrency, 
		   ValidDate);

   ASSERT_THAT(description, testing::Eq("2010-10-08: 1 EUR = 1.38 USD"));
}


const std::string ACurrencyExchangeDescriptionService::ValidBaseCurrency = "EUR";
const std::string ACurrencyExchangeDescriptionService::ValidExchangeCurrency = "USD";
const std::string ACurrencyExchangeDescriptionService::ValidDate = "2010-10-08";
