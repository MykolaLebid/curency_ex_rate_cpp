#include "gmock/gmock.h"
#include "CurrencyExchangeExtractor.h"
#include <string>

class ACurrencyExchangeExtractor: public testing::Test {
public:
   CurrencyExchangeExtractor extractor;
};

MATCHER(Is_Empty, "") {
   return 
      arg.base.empty() &&
      arg.exchange.empty() &&
      arg.rate.empty() &&
      arg.date.empty();
}

TEST_F(ACurrencyExchangeExtractor, ReturnsAnEmptyCurrencyExchangeOnAFailedParse) {
   auto currency_exchange = extractor.currencyExchangeFrom("not valid json");

   ASSERT_THAT(currency_exchange, Is_Empty());
}

TEST_F(ACurrencyExchangeExtractor, ReturnsPopulatedAddressForValidJsonResult) {
   auto json = R"({
         "base":"UR",
         "rates":{
            "USD":1.3121
          },
          "date":"2011-11-08"
   })";

   CurrencyExchange currencyEx = extractor.currencyExchangeFrom(json);
   ASSERT_THAT(currencyEx.base, testing::Eq("UR"));
   ASSERT_THAT(currencyEx.exchange, testing::Eq("USD"));
   ASSERT_THAT(currencyEx.rate, testing::Eq("1.3121"));
   ASSERT_THAT(currencyEx.date, testing::Eq("2011-11-08"));
}

TEST_F(ACurrencyExchangeExtractor, DefaultsNonexistentFieldsToEmpty) {
   auto json = R"({
         "base":"EUR",
         "date":"2011-11-08"
   })";
   auto currencyEx = extractor.currencyExchangeFrom(json);
   ASSERT_THAT(currencyEx.rate, testing::Eq(""));
}

