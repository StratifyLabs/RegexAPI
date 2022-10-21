// Copyright 2016-2021 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md

#ifndef REGEXAPI_REGEX_REGEX_HPP_
#define REGEXAPI_REGEX_REGEX_HPP_

#include <api/api.hpp>

#include <ctre.hpp>

namespace regex {

class RegEx : public api::ExecutionContext {
public:
  template<const char * const & pattern> constexpr auto create_matcher() noexcept {
    return ctre::match<pattern>;
  }
  template<const char * const & pattern> constexpr auto create_searcher() noexcept {
    return ctre::search<pattern>;
  }

  class Expression {
  public:
    Expression() = default;
    explicit Expression(const char *value) : m_string{value} {}

    const var::String &string() const { return m_string; }

    Expression &anything() {
      m_string += ".";
      return *this;
    }
    Expression &zero_or_more() {
      m_string += "*";
      return *this;
    }
    Expression &zero_or_more_not_greedy() {
      m_string += "*?";
      return *this;
    }
    Expression &one_or_more() {
      m_string += "+";
      return *this;
    }
    Expression &one_or_more_not_greedy() {
      m_string += "+?";
      return *this;
    }
    Expression &zero_or_one() {
      m_string += "?";
      return *this;
    }
    Expression &zero_or_one_not_greedy() {
      m_string += "??";
      return *this;
    }
    Expression &start_of_line() {
      m_string += "^";
      return *this;
    }
    Expression &end_of_line() {
      m_string += "$";
      return *this;
    }
    Expression &start_of_word() {
      m_string += "\\<";
      return *this;
    }
    Expression &end_of_word() {
      m_string += "\\>";
      return *this;
    }
    Expression &start_of_string() {
      m_string += "\\A";
      return *this;
    }
    Expression &word_boundary() {
      m_string += "\\b";
      return *this;
    }
    Expression &not_word_boundary() {
      m_string += "\\B";
      return *this;
    }
    Expression &control_character() {
      m_string += "\\c";
      return *this;
    }
    Expression &white_space() {
      m_string += "\\s";
      return *this;
    }
    Expression &not_white_space() {
      m_string += "\\S";
      return *this;
    }
    Expression &digit() {
      m_string += "\\d";
      return *this;
    }
    Expression &not_digit() {
      m_string += "\\D";
      return *this;
    }

    Expression &upper() {
      m_string += "[:upper:]";
      return *this;
    }
    Expression &lower() {
      m_string += "[:lower:]";
      return *this;
    }
    Expression &letters() {
      m_string += "[:alpha:]";
      return *this;
    }
    Expression &digits_letters() {
      m_string += "[:alnum:]";
      return *this;
    }
    Expression &hexadecimal_digits() {
      m_string += "[:xdigit:]";
      return *this;
    }
    Expression &punctuation() {
      m_string += "[:punct:]";
      return *this;
    }
    Expression &space_tab() {
      m_string += "[:blank:]";
      return *this;
    }
    Expression &blank_characters() {
      m_string += "[:space:]";
      return *this;
    }
    Expression &control_characters() {
      m_string += "[:cntrl:]";
      return *this;
    }
    Expression &printed_characters() {
      m_string += "[:print:]";
      return *this;
    }
    Expression &digits_letters_underscore() {
      m_string += "[:word:]";
      return *this;
    }

    Expression &newline() {
      m_string += "\\n";
      return *this;
    }
    Expression &carriage_return() {
      m_string += "\\r";
      return *this;
    }
    Expression &tab() {
      m_string += "\\t";
      return *this;
    }
    Expression &vertical_tab() {
      m_string += "\\v";
      return *this;
    }
    Expression &form_feed() {
      m_string += "\\f";
      return *this;
    }
    Expression &alarm() {
      m_string += "\\a";
      return *this;
    }
    Expression &backspace() {
      m_string += "[\\b]";
      return *this;
    }
    Expression &escape() {
      m_string += "\\e";
      return *this;
    }

    Expression &literal(const char *value) {
      m_string += value;
      return *this;
    }

    Expression &character_class(const char *value) {
      m_string += "[";
      m_string += value;
      m_string += "]";
      return *this;
    }

    Expression &capture_group(const char *value) {
      m_string += "(";
      m_string += value;
      m_string += ")";
      return *this;
    }

    Expression &escape(char value) {
      m_string += "\\";
      m_string += value;
      return *this;
    }

    Expression &named_character(const char *name) {
      m_string += "\\N{";
      m_string += name;
      m_string += "}";
      return *this;
    }

    Expression &exactly(size_t value) {
      m_string += "{";
      m_string += var::NumberString(value);
      m_string += "}";
      return *this;
    }

    Expression &or_more(size_t value) {
      m_string += "{";
      m_string += var::NumberString(value);
      m_string += ",}";
      return *this;
    }

    Expression &inclusive_range(size_t low, size_t high) {
      m_string += "{";
      m_string += var::NumberString(low);
      m_string += ",";
      m_string += var::NumberString(high);
      m_string += ",}";
      return *this;
    }

    Expression &inclusive_range_not_greedy(size_t low, size_t high) {
      m_string += "{";
      m_string += var::NumberString(low);
      m_string += ",";
      m_string += var::NumberString(high);
      m_string += ",}?";
      return *this;
    }

  private:
    friend RegEx;
    var::String m_string;
    auto get_expression() const { return var::String{}; };
  };

  enum class IsMatch { no, yes };

  IsMatch match(const char *input, const Expression &expression) const;

  enum class IsFound { no, yes };

  IsFound search(const char *input, const Expression &expression) const;

  var::String replace(
    const char *input,
    const Expression &expression,
    const char *replace) const;

private:
};

} // namespace regex

namespace printer {
class Printer;
// Add operators to send any important debug tracing data to a printer
Printer &operator<<(Printer &printer, const regex::RegEx &a);
} // namespace printer

#endif // REGEXAPI_REGEX_REGEX_HPP_
