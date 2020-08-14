/** @file list5706.cpp */
/** Listing 57-6. Playing High-Card with array */
import <algorithm>;
import <array>;
import <iostream>;

import card;
import randomint; // Listing 45-5

int main()
{
  std::array<card, 52> deck;
  std::ranges::generate(deck, card_generator{});

  randomint picker{0, deck.size() - 1};
  for (int i{0}; i != 10; ++i)
  {
    card const& computer_card{deck.at(picker())};
    std::cout << "I picked " << computer_card << '\n';

    card const& user_card{deck.at(picker())};
    std::cout << "You picked " << user_card << '\n';

    if (acehigh_less(computer_card, user_card))
      std::cout << "You win.\n";
    else
      std::cout << "I win.\n";
  }
}
