// Copyright 2016-2021 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md

#ifndef REGEXAPI_REGEX_REGEX_HPP_
#define REGEXAPI_REGEX_REGEX_HPP_

#include <regex>

#include <api/api.hpp>


namespace regex {


class RegEx : public api::ExecutionContext {
public:

  class StringMatch {
  public:

    size_t count() const {
      return m_value.size();
    }

    var::String at(size_t offset) const {
      API_ASSERT(offset < count());
      return var::String{m_value[offset].str()};
    }

  private:
    friend RegEx;
    std::cmatch m_value;
    API_RAB(StringMatch,valid,false);
  };

  class Expression {
  public:
    explicit Expression(const char * value) : m_value{value}{}
  private:
    friend RegEx;
    std::regex m_value;
  };

  StringMatch match(var::StringView input, const Expression & expression);


private:

};

}

namespace printer {
class Printer;
//Add operators to send any important debug tracing data to a printer
Printer &operator<<(Printer &printer, const regex::RegEx &a);
} // namespace printer

#endif // REGEXAPI_REGEX_REGEX_HPP_
