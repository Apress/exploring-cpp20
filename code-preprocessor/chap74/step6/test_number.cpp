#include <sstream>
#include <string>
#include <string_view>
#include <gtest/gtest.h>

#include "calc_error.hpp"
#include "number.hpp"

using namespace std::literals;

TEST(NumberTest, test_basics)
{
  number n{1L};
  EXPECT_EQ("1", n.to_string());
  number m{2.0};
  EXPECT_EQ("2", m.to_string());
  m = n;
  EXPECT_EQ("1", m.to_string());
  number x{number{n}};
  EXPECT_EQ("1", x.to_string());
}

TEST(NumberTest, test_library)
{
  number i{1}, f{2.0}, v;
  std::stringstream stream;
  i.save(stream);
  f.save(stream);
  v.save(stream);

  number n1(stream);
  number n2(stream);
  number n3(stream);

  EXPECT_EQ(number{1}, n1);
  EXPECT_EQ(number{2}, n2);
  EXPECT_EQ("",  n3.to_string());
}

TEST(NumberTest, test_compare)
{
  EXPECT_TRUE(number{1} < number{2});
  EXPECT_TRUE(number{1} <= number{2});
  EXPECT_TRUE(number{1} != number{2});
  EXPECT_TRUE(number{2} > number{1});
  EXPECT_TRUE(number{2} >= number{1});
  EXPECT_TRUE(number{2} != number{1});
  EXPECT_TRUE(number{1} == number{1});
  EXPECT_TRUE(not (number{1} != number{1}));
  EXPECT_TRUE(not (number{1} > number{2}));
  EXPECT_TRUE(not (number{1} >= number{2}));
  EXPECT_TRUE(not (number{1} == number{2}));
  EXPECT_TRUE(not (number{2} < number{1}));
  EXPECT_TRUE(not (number{2} <= number{1}));
  EXPECT_TRUE(not (number{2} == number{1}));

  EXPECT_TRUE(number{1} < number{1.5});
  EXPECT_TRUE(number{1} <= number{1.5});
  EXPECT_TRUE(number{1} != number{1.5});
  EXPECT_TRUE(number{1.5} > number{1});
  EXPECT_TRUE(number{1.5} >= number{1});
  EXPECT_TRUE(number{1.5} != number{1});
  EXPECT_TRUE(number{1.0} == number{1});
}

TEST(NumberTest, test_add)
{
  number a{1.0}, b{2}, c;
  c = a + b;
  EXPECT_EQ(number{3}, c);
}

TEST(NumberTest, test_subtract)
{
  number a{2.0}, b{1}, c;
  c = a - b;
  EXPECT_EQ(number{1}, c);
}

TEST(NumberTest, test_multiply)
{
  number a{2.0}, b{3}, c;
  c = a * b;
  EXPECT_EQ(number{6}, c);
}

TEST(NumberTest, test_divide)
{
  number a{5}, b{2}, c;
  c = a / b;
  EXPECT_EQ(number{rational<long>{5, 2}}, c);
  a = number{5.0};
  c = a / b;
  EXPECT_EQ(number{2.5}, c);
  EXPECT_THROW(a / number{0}, calc_error);
}

TEST(NumberTest, test_rational)
{
  number half{rational<long>{1, 2}};
  number a{half};
  a = a * number{2};
  EXPECT_EQ(number{1}, a);
  a = a / number{3};
  a = a * number{3};
  EXPECT_EQ(number{1}, a);
  a = a - half;
  EXPECT_EQ(half, a);
  a = half + a;
  EXPECT_EQ(number{1}, a);
}
