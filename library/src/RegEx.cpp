// Copyright 2016-2022 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md

#include <printer/Printer.hpp>
#include <var/StackString.hpp> //for NumberString

#include "regex/RegEx.hpp"

printer::Printer &printer::operator<<(Printer &printer, const regex::RegEx &a) {
  return printer;
}

regex::RegEx::IsMatch regex::RegEx::match(
  const char *input,
  const regex::RegEx::Expression &expression) const {
  return IsMatch::no;
}

regex::RegEx::IsFound regex::RegEx::search(
  const char *input,
  const regex::RegEx::Expression &expression) const {
  return IsFound::no;
}

var::String regex::RegEx::replace(
  const char *input,
  const regex::RegEx::Expression &expression,
  const char *replace) const {
  return var::String{};
}
