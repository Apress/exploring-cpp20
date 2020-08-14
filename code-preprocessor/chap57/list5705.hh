/** @file list5705.hh */
/** Listing 57-5. The card Class, to Represent a Playing Card */
// export module cards;
#include <iosfwd>

/// Represent a standard western playing card.
/*export*/ class card
{
public:
  using suit = char;
  static constexpr suit const spades   {4};
  static constexpr suit const hearts   {3};
  static constexpr suit const clubs    {2};
  static constexpr suit const diamonds {1};

  using rank = char;
  static constexpr rank const ace   {14};
  static constexpr rank const king  {13};
  static constexpr rank const queen {12};
  static constexpr rank const jack  {11};

  constexpr card() : rank_{0}, suit_{0} {}
  constexpr card(rank r, suit s) : rank_{r}, suit_{s} {}

  constexpr void assign(rank r, suit s);
  constexpr suit get_suit() const { return suit_; }
  constexpr rank get_rank() const { return rank_; }
private:
  rank rank_;
  suit suit_;
};

/*export*/ bool operator==(card a, card b);
/*export*/ bool operator!=(card a, card b);
/*export*/ std::ostream& operator<<(std::ostream& out, card c);
/*export*/ std::istream& operator>>(std::istream& in, card& c);

/// In some games, Aces are high. In other Aces are low. Use different
/// comparison functors depending on the game.
/*export*/ bool acehigh_less(card a, card b);
/*export*/ bool acelow_less(card a, card b);

/// Generate successive playing cards, in a well-defined order,
/// namely, 2-10, J, Q, K, A. Diamonds first, then Clubs, Hearts, and Spades.
/// Roll-over and start at the beginning again after generating 52 cards.
/*export*/ class card_generator
{
public:
  card_generator();
  card operator()();
private:
  card card_;
};
