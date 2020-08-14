/** @file list5707.cpp */
/** Listing 57-7. Playing High-Card with a deque */
import <algorithm>;
import <deque>;
import <iostream>;

import card;
import randomint;

int main()
{
  std::deque<card> deck(52);
  std::ranges::generate(deck, card_generator{});

  for (int i{0}; i != 10; ++i)
  {
    auto pick{deck.begin() + randomint{0, deck.size()-1}()};
    card computer_card{*pick};
    deck.erase(pick);

    std::cout << "I picked " << computer_card << '\n';

    pick = deck.begin() + randomint{0, deck.size() - 1}();
    card user_card{*pick};
    deck.erase(pick);

    std::cout << "You picked " << user_card << '\n';

    if (acehigh_less(computer_card, user_card))
      std::cout << "You win.\n";
    else
      std::cout << "I win.\n";
  }
}
