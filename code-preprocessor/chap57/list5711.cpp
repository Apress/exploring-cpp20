/** @file list5711.cpp */
/** Listing 57-11. Playing High-Card Using an Explicit Specialization of std::less */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>

#include "card.hpp"
#include "randomint.hpp"

namespace std
{
  template<>
  class less<card>
  {
  public:
    bool operator()(card a, card b) const { return acehigh_less(a, b); }
  };
}

int main()
{
  using cardset = std::set<card>;
  cardset deck{};
  std::generate_n(std::inserter(deck, deck.begin()), 52, card_generator{});

  for (int i{0}; i != 10; ++i)
  {
    auto pick{deck.begin()};
    std::advance(pick, randomint{0, deck.size() - 1}());
    card computer_card{*pick};
    deck.erase(pick);

    std::cout << "I picked " << computer_card << '\n';

    pick = deck.begin();
    std::advance(pick, randomint{0, deck.size() - 1}());
    card user_card{*pick};
    deck.erase(pick);

    std::cout << "You picked " << user_card << '\n';

    if (acehigh_less(computer_card, user_card))
      std::cout << "You win.\n";
    else
      std::cout << "I win.\n";
  }
}
