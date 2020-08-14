/** @file list5712.cpp */
/** Listing 57-12. Playing High-Card with unordered_set */
import <algorithm>;
import <functional>;
import <iostream>;
import <iterator>;
import <unordered_set>;

import card;
import randomint;

namespace std
{
  template<>
  class hash<card>
  {
  public:
    std::size_t operator()(card a)
    const
    {
      return hash<int>{}(a.get_suit() * 64 + a.get_rank());
    }
  };
} // namespace std

int main()
{
  using cardset = std::unordered_set<card>;
  cardset deck{};
  std::generate_n(std::inserter(deck, deck.begin()), 52, card_generator{});

  for (int i(0); i != 10; ++i)
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
