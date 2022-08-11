
#include <cstdio>

#include <fs/File.hpp>
#include <printer/Printer.hpp>
#include <test/Test.hpp>
#include <var/StackString.hpp>

#include "regex/RegEx.hpp"

using namespace regex;
using namespace printer;
using namespace var;

class UnitTest : public test::Test {
public:
  UnitTest(var::StringView name) : test::Test(name) {}

  bool execute_class_api_case() {
    TEST_ASSERT_RESULT(execute_regex_api_case());

    return true;
  }

  bool execute_regex_api_case() {
    Printer::Object regex_object(printer(), "regex");

    const auto expression = RegEx::Expression("t.*");
    const auto input
      = {"this is the end", "the beginning", "now", "test", "go"};

    for (const auto value : input) {
      Printer::Object case_object(printer(), value);
      const auto result = RegEx().match(value, expression);
      printer().key_bool("match", result.is_valid());
      if (value[0] == 't') {
        TEST_ASSERT(result.is_valid());
        TEST_ASSERT(result.count() == 1);
        printer().key("result", result.at(0));
      } else {
        TEST_ASSERT(!result.is_valid());
        TEST_ASSERT(result.count() == 0);
        printer().key("result", "<none>");
      }
    }

    return true;
  }
};
