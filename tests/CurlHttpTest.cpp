#include "gmock/gmock.h"
#include <string>
#include "CurlHttp.h"


TEST(Http, WriteCallback) {
   std::string buffer("123456789012");
   std::size_t size(12);
   std::size_t numberOfMembers(1);
   CurlHttp::writeCallback("123456789012", size, numberOfMembers, NULL);
   ASSERT_THAT(CurlHttp::Response(), testing::Eq("123456789012"));
}

TEST(HttpIntegration, /*DISABLED_*/Get) {
   CurlHttp http;
   http.initialize();
   auto response = http.get
	  ("https://api.ratesapi.io/api/latest?base=EUR&symbols=USD");
   ASSERT_THAT(response, testing::HasSubstr("EUR"));
}

