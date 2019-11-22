#ifndef CurrencyExchangeExtractor_h
#define CurrencyExchangeExtractor_h

#include <json/reader.h>
#include <json/value.h>

#include "CurrencyExchange.h"

class CurrencyExchangeExtractor {
public:
	CurrencyExchange currencyExchangeFrom(const std::string& json) const;
private:
   Json::Value jsonCurrencyExchangeFrom(const std::string& json) const;
   void populate(CurrencyExchange& currency, Json::Value& jsonCurrencyEx) const;
   Json::Value parse(const std::string& json) const;
   std::string getString(Json::Value& result, const std::string& name) const;
};

#endif
