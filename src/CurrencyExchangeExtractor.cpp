#include "CurrencyExchangeExtractor.h"
#include <NumStr.h>// numstr::to_string_with_precision

CurrencyExchange CurrencyExchangeExtractor::currencyExchangeFrom(const std::string& json) const {
   CurrencyExchange currencyEx;
   Json::Value jsonCurrencyEx{jsonCurrencyExchangeFrom(json)};
   populate(currencyEx, jsonCurrencyEx);    
   return currencyEx; 
}

Json::Value CurrencyExchangeExtractor::jsonCurrencyExchangeFrom(const std::string& json) const {
   auto currencyEx = parse(json);
   return currencyEx;
}

void CurrencyExchangeExtractor::populate(CurrencyExchange& currencyEx, Json::Value& jsonCurrencyEx) const {
  if (jsonCurrencyEx.isMember("base"))
	   currencyEx.base = getString(jsonCurrencyEx, "base");
   
  if (jsonCurrencyEx.isMember("rates")){
   	const Json::Value rates = jsonCurrencyEx["rates"];   
   	std::string exchange = *(rates.getMemberNames().begin());  
   	currencyEx.exchange = exchange;
   	currencyEx.rate = numstr::to_string_with_precision<double>
		            (rates[exchange].asDouble(),4);
   };

  if(jsonCurrencyEx.isMember("date")) 
    currencyEx.date = getString(jsonCurrencyEx, "date"); 
}
Json::Value CurrencyExchangeExtractor::parse(const std::string& json) const {
   Json::Value root;
  
   //one can use these constructions for json extraction as well   
   //Reader reader;
   //reader.parse(json, root);
   
   Json::CharReaderBuilder builder;
   Json::CharReader * reader = builder.newCharReader();
   std::string errors;
    
   reader->parse(json.c_str(), json.c_str() + json.size(),
 	          &root, &errors);
   return root; 
}

std::string CurrencyExchangeExtractor::getString(Json::Value& result, const std::string& name) const {
   return result.get(name, "").asString();
}

