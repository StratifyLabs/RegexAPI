
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
  explicit UnitTest(var::StringView name) : test::Test(name) {}

  bool execute_class_api_case() override {
    TEST_ASSERT_RESULT(execute_regex_api_case());

    return true;
  }

  bool execute_regex_api_case() {
    Printer::Object regex_object(printer(), "regex");

    {
      Printer::Object regex_object(printer(), "test");
      const auto expression = RegEx::Expression().capture_group("t.*");
      const auto input
        = {"this is the end", "the beginning", "now", "test", "go"};

      for (const auto value : input) {
        Printer::Object case_object(printer(), value);
        const auto result = RegEx().match(value, expression);
        printer().key_bool("match", result == RegEx::IsMatch::yes);
        if (value[0] == 't') {
          TEST_ASSERT(result == RegEx::IsMatch::yes);
        } else {
          TEST_ASSERT(result == RegEx::IsMatch::no);
        }
      }
    }
    {
      Printer::Object regex_object(printer(), "compileOutput");
      static constexpr auto compile_output = {
        "gcc -c -o main.o main.cpp\n",
        "make[1]: entering directory\n",
        "make[2]: entering directory\n",
        "make[12]: entering directory\n",
        "make[12]: leaving directory\n",
        "make[2]: leaving directory\n",
        "gcc -c -o main.o main.cpp\n"};

      const auto enter_directory_expression
        = RegEx::Expression(R"(make\[[0-9]+\].*\n)");

      const auto make_expression = RegEx::Expression()
                                     .literal("make\\[")
                                     .character_class("0-9")
                                     .one_or_more()
                                     .literal("\\]:")
                                     .anything()
                                     .zero_or_more()
                                     .newline();

      printer().key("expression", make_expression.string());
      for (const auto value : compile_output) {
        const auto result = RegEx().search(value, make_expression);
        TEST_ASSERT(
          value[0] == 'm' ? result == RegEx::IsFound::yes
                          : result == RegEx::IsFound::no);
      }
    }

    return true;
  }
};
