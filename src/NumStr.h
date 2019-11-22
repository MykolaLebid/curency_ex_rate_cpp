#ifndef REAL_STRING_H
#define REAL_STRING_H
#include <string>
#include <iomanip>
#include <sstream>

namespace numstr{

template<typename REAL>
  std::string to_string_with_precision(const REAL real,
		const unsigned int precision){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << real;
    return stream.str();
  };	
}
#endif
