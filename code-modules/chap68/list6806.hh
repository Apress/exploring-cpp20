/** @file list6806.hh */
/** Listing 68-6. Improving the card Class with Enumerations */
export module card;

import <istream>;
import <ostream>;

export enum class suit { diamonds, clubs, hearts, spades };
export enum class rank { r2=2, r3, r4, r5, r6, r7, r8, r9, r10, jack, queen, king, ace };

export suit& operator++(suit& s)
{
   if (s == suit::spades)
      s = suit::diamonds;
  else
     s = static_cast<suit>(static_cast<int>(s) + 1);
  return s;
}

export rank operator++(rank& r)
{
   if (r == rank::ace)
      r = rank::r2;
   else
      r = static_cast<rank>(static_cast<int>(r) + 1);
   return r;
}

/// Represent a standard western playing card.
export class card
{
public:
  constexpr card() : rank_(rank::ace), suit_(suit::spades) {}
  constexpr card(rank r, suit s) : rank_{r}, suit_{s} {}

  constexpr void assign(rank r, suit s);
  constexpr suit get_suit() const { return suit_; }
  constexpr rank get_rank() const { return rank_; }
private:
  rank rank_;
  suit suit_;
};

export bool operator==(card a, card b);
export bool operator!=(card a, card b);
export std::ostream& operator<<(std::ostream& out, card c);
export std::istream& operator>>(std::istream& in, card& c);

/// In some games, Aces are high. In other Aces are low. Use different
/// comparison functors depending on the game.
export bool acehigh_compare(card a, card b);
export bool acelow_compare(card a, card b);

/// Generate successive playing cards, in a well-defined order,
/// namely, 2-10, J, Q, K, A. Diamonds first, then Clubs, Hearts, and Spades.
/// Roll-over and start at the beginning again after generating 52 cards.
export class card_generator
{
public:
  card_generator();
  card operator()();
private:
  card card_;
};
