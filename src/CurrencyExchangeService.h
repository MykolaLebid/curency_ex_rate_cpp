#ifndef CurrencyExchangeService_h
#define CurrencyExchangeService_h

#include <string>
#include "CurrencyExchange.h"
#include "CurrencyExchangeExtractor.h"
#include "Http.h"
#include "CurlHttp.h"
template<typename HTTP>
class CurrencyExchangeServiceTemplate {
public:
   std::string summaryDescription(
         const std::string base,
	 const std::string exchange,
	 const std::string date){
       auto request = createGetRequestUrl(base, exchange, date);
       auto response = get(request);
       return summaryDescription(response);
   };
   // mocks in tests need the reference
   HTTP& http() {
      return http_;
   }

private:
   std::string summaryDescription(const std::string& response) const{
      CurrencyExchangeExtractor extractor;
      CurrencyExchange currencyExchange = extractor.currencyExchangeFrom(response);
      
      return currencyExchange.summaryDescription();
   }

   std::string get(const std::string& url) {
      http_.initialize();
      return http_.get(url);
   }

   std::string createGetRequestUrl(		   
         const std::string base,
	 const std::string exchange,
	 const std::string date) const {
      std::string server{"https://api.ratesapi.io/api/"}; 
      return server + date +  "?" +
             keyValue("base", base) + "&" +
             keyValue("symbols", exchange);
   }

   std::string keyValue(
         const std::string& key, const std::string& value) const {
      return key + "=" + value;
   }

   HTTP http_;
};

class CurlHttp;
typedef CurrencyExchangeServiceTemplate<CurlHttp> CurrencyExchangeService;

#endif
