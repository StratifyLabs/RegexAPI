// Copyright 2016-2022 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md

#include <printer/Printer.hpp>
#include <var/StackString.hpp> //for NumberString

#include "regex/RegEx.hpp"

printer::Printer &printer::operator<<(Printer &printer, const regex::RegEx &a) {
  return printer;
}

regex::RegEx::StringMatch regex::RegEx::match(
  const char * input,
  const regex::RegEx::Expression &expression) {
  StringMatch result;
  result.m_is_valid = std::regex_match(input,
    result.m_value,
    expression.m_value);

  return result;
}
