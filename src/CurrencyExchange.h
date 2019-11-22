#ifndef CurrencyExchage_h
#define CurrencyExchage_h

#include <string>

struct CurrencyExchange {
   std::string base;
   std::string exchange;
   std::string rate;
   std::string date;
   std::string summaryDescription() const {
      return date + ":"  + " 1 "+ base + " = " + rate +" " + exchange;
   };
};

#endif

