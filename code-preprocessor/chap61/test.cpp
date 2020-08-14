/** @file test.cpp */
#include <iostream>
#include <locale>
#include <sstream>
#include <stdexcept>
#include <string_view>

#include "test.hpp"
#include "currency.hpp"

using currency4 = currency<long,4>;
using currency3 = currency<long,3>;
using currency2 = currency<long,2>;

void test_locale_independent(std::locale const& locale)
{
  currency2 c1{locale};
  TEST_EQUAL(0, c1.value().value());
  currency2 c2(1L, locale);
  TEST_EQUAL(100, c2.value().value());
  currency2 c3(3, 1416, locale);
  TEST_EQUAL(314, c3.value().value());
  currency2 c4(6, 275, locale);
  TEST_EQUAL(628, c4.value().value());
  currency2 c5(5, 279, locale);
  TEST_EQUAL(528, c5.value().value());
  TEST_EQUAL(c1 + c4, c3 + c3);
  TEST(c3 + c3 <= c1 + c4);
  TEST(c3 + c3 >= c1 + c4);
  TEST(c1 < c2);
  TEST(c1 <= c2);
  TEST(c1 != c2);
  TEST(c2 > c1);
  TEST(c2 >= c1);
  TEST(c2 != c1);
  TEST_EQUAL(currency2{0, 50, locale}, c2 / 2L);

  TEST_EQUAL(c2, c4 - c5);
  TEST_EQUAL(c4, c3 * 2L);
  TEST_EQUAL(c3, c4 / 2L);
  c5 += c2;
  TEST_EQUAL(c4, c5);
  c5 /= 2L;
  TEST_EQUAL(c5, c3);
  c3 *= 2L;
  TEST_EQUAL(c4, c3);
  c3 -= c5;
  TEST_EQUAL(c5, c3);

  TEST_EQUAL(c1 - c4, -c4);
  TEST_EQUAL(c4, -(-c4));
  TEST_EQUAL(--c4 + c2, c3 + c5);
  TEST_EQUAL(c4 + c2, c3 + c5);
  TEST_EQUAL(c4-- + c2, c3 + c5);
  TEST_EQUAL(c4 + c2 + c2, c3 + c5);
  TEST_EQUAL(++c4 + c2, c3 + c5);
  TEST_EQUAL(c4 + c2, c3 + c5);
  TEST_EQUAL(c4++ + c2, c3 + c5);
  TEST_EQUAL(c4, c3 + c5);

  c2 *= 2L;
  TEST_EQUAL(rational<long>(314, 100), c4 / c2);
  TEST_EQUAL(c5, c4 /= 2L);
  TEST_EQUAL(c5, c4);

  TEST_EQUAL(3, c4.integer());
  c4 += currency2{-1,8};
  TEST_EQUAL(currency2{2.06}, c4);
  TEST_EQUAL(2, c4.integer());
  TEST_EQUAL(2, c4.round());
  c4 += c2 / 2L;
  TEST_EQUAL(3, c4.round());

  TEST_EQUAL(3, c3.integer());
  TEST_EQUAL(-3, (-c3).integer());
  TEST_EQUAL(14, c3.fraction());
  TEST_EQUAL(14, (-c3).fraction());

  TEST_EQUAL(7L, currency4{7,4999}.round());
  TEST_EQUAL(8L, currency4{7,5000}.round());
  TEST_EQUAL(8L, currency4{7,5001}.round());
  TEST_EQUAL(7L, currency4{7,4999}.round());
  TEST_EQUAL(8L, currency4{8,5000}.round());
  TEST_EQUAL(9L, currency4{8,5001}.round());

  TEST_EQUAL(currency4{123,2346}, currency4{123,2345500});
  TEST_EQUAL(currency4{123,2346}, currency4{123,2345501});
  TEST_EQUAL(currency4{123,2345}, currency4{123,2345499});
  TEST_EQUAL(currency4{123,2346}, currency4{123,2346500});
  TEST_EQUAL(currency4{123,2347}, currency4{123,2346501});
  TEST_EQUAL(currency4{123,2346}, currency4{123,2346499});
  TEST_EQUAL(currency4{123,2346}, currency4{123,2346400});
  TEST_EQUAL(currency4{123,2347}, currency4{123,2346600});

  TEST_EQUAL(-31416L, currency4{-3.14159265}.value().value());
  TEST_EQUAL(1234568L, currency4{123,456789}.value().value());
  TEST_EQUAL(1230004L, currency4{123,4}.value().value());
  TEST_EQUAL(-101111L, currency4{-10,1111}.value().value());

  TEST_EQUAL(currency2{31, 59}, currency2{31.59265});
  TEST_EQUAL(currency2{31, 60}, currency2{31.595});

  bool okay{false};
  try {
    currency2 c7{1, -1};
  } catch (std::invalid_argument const& ex) {
    okay = true;
  } catch (std::exception const& ex) {
    std::cerr << "wrong exception: " << ex.what() << '\n';
  }
  TEST(okay);
}

template<class T, int N>
void test_locale_specific(currency<T,N> c1, std::string_view string)
{
  using currency_t = currency<T,N>;
  TEST_EQUAL(string, c1.to_string());
  std::cerr << "locale: " << c1.locale().name() << ", c1=" << c1 << '\n';

  std::ostringstream out;
  out.imbue(c1.locale());
  out << std::showbase << c1 << " error";

  currency_t c2{c1.locale()};
  std::istringstream in(out.str());
  in.imbue(c1.locale());
  TEST(in >> c2);
  TEST_EQUAL(c1, c2);

  c2 = currency_t{1,2};
  c2.locale(c1.locale());
  TEST(not (in >> c2));
  TEST_EQUAL(currency_t{1,2,c1.locale()}, c2);
}

int main()
{
  test_locale_independent(std::locale{});
  test_locale_independent(std::locale{"en_US"});
  test_locale_independent(std::locale{"fr_FR"});

  test_locale_specific(currency2{1234567,  0, std::locale{}}, "1234567");
  test_locale_specific(currency2{1234567, 89, std::locale{"en_US"}}, "$1,234,567.89");
  test_locale_specific(currency2{1234567, 89, std::locale{"fr_FR.utf8"}}, "1 234 567,89 \u20ac");
  test_locale_specific(currency2{1234567, 89, std::locale{"de_DE.utf8"}}, "1.234.567,89 \u20ac");

  test_locale_specific(currency4{1234567,    0, std::locale{}}, "1234567");
  test_locale_specific(currency4{1234567, 8900, std::locale{"en_US"}}, "$1,234,567.89");
  test_locale_specific(currency4{1234567, 8900, std::locale{"fr_FR.utf8"}}, "1 234 567,89 \u20ac");
  test_locale_specific(currency4{1234567, 8900, std::locale{"de_DE.utf8"}}, "1.234.567,89 \u20ac");

  test_exit();
}
