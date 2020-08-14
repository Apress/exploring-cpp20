#include <sstream>
#include <string>
#include <string_view>
#include <gtest/gtest.h>

#include "parse.hpp"

using namespace std::literals;

TEST(ParseTest, test_number)
{
  std::istringstream in{"1\n3.14159\n1.23e45\n45.67e+8\n"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> 1\n> 3.14159\n> 1.23e+45\n> 4.567e+09\n> "sv, out.str());
}

TEST(ParseTest, test_negative)
{
  std::istringstream in{"-1\n-3.14159\n-1.23e-45\n-34.56e-7\n"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> -1\n> -3.14159\n> -1.23e-45\n> -3.456e-06\n> "sv, out.str());
}

TEST(ParseTest, test_add)
{
  std::istringstream in{"1 + 2\n1 + 2 + 3"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> 3\n> 6\n> "sv, out.str());
}

TEST(ParseTest, test_subtract)
{
  std::istringstream in{"1 - 2\n5 - 1 - 2"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> -1\n> 2\n> "sv, out.str());
}

TEST(ParseTest, test_multiply)
{
  std::istringstream in{"1 * 2\n5 * 2 * 1.5"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> 2\n> 15\n> "sv, out.str());
}

TEST(ParseTest, test_divide)
{
  std::istringstream in{"1.0 / 2\n10.0 / 2 / 2"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> 0.5\n> 2.5\n> "sv, out.str());
}

TEST(ParseTest, test_mix)
{
  std::istringstream in{" 1.5 * 2 + 3 / 1.5 - (10 - 3) + 2 * -1"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> -4\n> "sv, out.str());
}

TEST(ParseTest, test_var)
{
  std::istringstream in{" def half = 1.0 / 2\ndef one=1.0\n one + half"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> > > 1.5\n> "sv, out.str());
}

TEST(ParseTest, test_predefined_vars)
{
  std::istringstream in{" pi - e"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> 0.423311\n> "sv, out.str());
}

TEST(ParseTest, test_function)
{
  std::istringstream in{"def times(a, b) = a * b\ntimes(2, 3)\n"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> > 6\n> "sv, out.str());
}

TEST(ParseTest, test_error1)
{
  std::istringstream in{"1+++2"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> syntax error: expected a primary, got +\n> "sv, out.str());
}

TEST(ParseTest, test_error2)
{
  std::istringstream in{"1..2"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> syntax error: expected digit after decimal point, got '.'\n> "sv, out.str());
}

TEST(ParseTest, test_error3)
{
  std::istringstream in{"1 @ 2"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> syntax error: expected digit, got '@'\n> "sv, out.str());
}

TEST(ParseTest, test_error4)
{
  std::istringstream in{"(1 + 2"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> syntax error: expected ')', got end of line\n> "sv, out.str());
}

TEST(ParseTest, test_error5)
{
  std::istringstream in{"pi(2)"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> wrong number of arguments in call to pi(), expected 0, got 1\n> "sv, out.str());
}

TEST(ParseTest, test_error6)
{
  std::istringstream in{"def times(a, b) = a * b\ntimes(2)"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> > wrong number of arguments in call to times(), expected 2, got 1\n> "sv, out.str());
}

TEST(ParseTest, test_error7)
{
  std::istringstream in{"def times(a, b) = a * b\ndivide(2, 3)"s};
  std::ostringstream out;
  parse_loop(in, out);
  EXPECT_EQ("> > unknown function: divide\n> "sv, out.str());
}
