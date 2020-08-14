#ifndef CARD_HPP_
#define CARD_HPP_

#include <string_view>
using namespace std::literals::string_view_literals;

#include "list5705.hh"

bool operator==(card a, card b) {
  return a.get_suit() == b.get_suit() and a.get_rank() == b.get_rank();
}

bool operator!=(card a, card b) {
  return not(a == b);
}

constexpr void card::assign(rank r, suit s) {
  rank_ = r;
  suit_ = s;
}

constexpr std::string_view suits{ "?DCHS" };
constexpr std::string_view ranks{ "??234567890JQKA" };

std::ostream& operator<<(std::ostream& stream, card c) {
  stream << (c.get_rank() == 10 ? "10"sv : ranks.substr(c.get_rank(), 1)) << suits[c.get_suit()];
  return stream;
}

bool acehigh_less(card a, card b)
{
    return a.get_rank() < b.get_rank() or
           (a.get_rank() == b.get_rank() and a.get_suit() < b.get_suit());
}

bool acelow_less(card a, card b)
{
    return (a.get_rank() % 13) < (b.get_rank() % 13) or
           (a.get_rank() == b.get_rank() and a.get_suit() < b.get_suit());
}

card_generator::card_generator() : card_{} {}
card card_generator::operator()() {
  card::rank r{ card_.get_rank() };
  card::suit s{ card_.get_suit() };
  if (++r < 2)
    r = 2;
  else if (r > card::ace) {
    ++s;
    r = 2;
  }
  if (s < card::diamonds or s > card::spades)
    s = card::diamonds;

  card_ = card{r, s};
  return card_;
}
#endif
