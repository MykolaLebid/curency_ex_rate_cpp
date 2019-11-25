#include "CurrencyExchangeService.h"
#include "Http.h"
//#include "HttpFactory.h"
//#include <string>


//template<typename HTTP>
//std::string CurrencyExchangeServiceTemplate<HTTP>::
//     summaryDescription( const std::string base, 
//                         const std::string exchange, 
//                         const std::string date) {
//}; 
//

//string PlaceDescriptionService::summaryDescription(
//      const string& response) const {
//   AddressExtractor extractor;
//   auto address = extractor.addressFrom(response);
//   return address.summaryDescription();
//}
//
//// START:get
//string PlaceDescriptionService::get(const string& url) const {
//// START_HIGHLIGHT
//   auto http = httpFactory_->get();
//// END_HIGHLIGHT
//   http->initialize();
//   return http->get(url);
//}
//// END:get
//
//string PlaceDescriptionService::createGetRequestUrl(
//      const string& latitude, const string& longitude) const {
//   string server{"http://open.mapquestapi.com/"};
//   string document{"nominatim/v1/reverse"};
//   return server + document + "?" +
//          keyValue("format", "json") + "&" +
//          keyValue("lat", latitude) + "&" +
//          keyValue("lon", longitude);
//}
//
//string PlaceDescriptionService::keyValue(
//      const string& key, const string& value) const {
//   return key + "=" + value;
//}
//
