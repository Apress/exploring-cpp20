#ifndef CARD_HPP_
#define CARD_HPP_

#include <string_view>
using namespace std::literals::string_view_literals;

#include "list6806.hh"

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

constexpr std::string_view suits{ "DCHS" };
constexpr std::string_view ranks{ "??23456789?JQKA" };

std::ostream& operator<<(std::ostream& stream, card c) {
  std::string text;
  if (c.get_rank() == rank::r10)
      text += "10";
  else
      text += ranks.substr(static_cast<int>(c.get_rank()), 1);
  text += suits[static_cast<int>(c.get_suit())];
  stream << text;
  return stream;
}

std::istream& operator>>(std::istream& stream, card& c) {
	if (std::string token; stream >> token) {
		if (auto sindex = suits.find(token.at(0)); sindex == std::string::npos)
			stream.setstate(stream.failbit);
		else {
		    suit s{ static_cast<suit>(sindex) };
		    token.erase(0);
		    if (token == "10")
				c.assign(rank::r10, s);
			else if (auto rindex = ranks.find(token.at(0)); rindex == std::string::npos or ranks[rindex] == '?')
				stream.setstate(stream.failbit);
			else
				c.assign(static_cast<rank>(rindex), s);
		}
	}
	return stream;
}

bool acehigh_less(card a, card b)
{
    return a.get_rank() < b.get_rank() or
           (a.get_rank() == b.get_rank() and a.get_suit() < b.get_suit());
}

bool acelow_less(card a, card b)
{
    return (static_cast<int>(a.get_rank()) % 13) < (static_cast<int>(b.get_rank()) % 13) or
           (a.get_rank() == b.get_rank() and a.get_suit() < b.get_suit());
}

card_generator::card_generator() : card_{} {}

card card_generator::operator()() {
  rank r{ card_.get_rank() };
  suit s{ card_.get_suit() };
  card_.assign(++r, ++s);
  return card_;
}
#endif
