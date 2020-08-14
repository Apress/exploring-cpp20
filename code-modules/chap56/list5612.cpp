/** @file list5612.cpp */
/** Listing 56-12. Counting Occurrences of Tokens */
import <algorithm>;
import <iostream>;
import <iterator>;
import <map>;
import <string>;
import <string_view>;

namespace parser
{
  class token
  {
  public:
    token() : text_{} {}
    token(std::string_view s) : text_{s} {}
    token& operator=(std::string_view s) { text_ = s; return *this; }
    std::string text() const { return text_; }
  private:
    std::string text_;
  };

  // To store tokens in a map.
  bool operator<(token const& a, token const& b)
  {
    return a.text() < b.text();
  }

  std::istream& operator>>(std::istream& in, parser::token& tok)
  {
    std::string str{};
    if (in >> str)
      tok = str;
    return in;
  }

  std::ostream& operator<<(std::ostream& out, parser::token const& tok)
  {
    out << tok.text();
    return out;
  }

  std::ostream& operator<<(std::ostream& out,
                           std::pair<const token, long> const& count)
  {
    out << count.first.text() << '\t' << count.second << '\n';
    return out;
  }
}

int main()
{
  using namespace parser;
  using namespace std;

  map<token, long> tokens{};
  token tok{};
  while (cin >> tok)
     ++tokens[tok];
  ranges::copy(tokens,
       ostream_iterator<pair<const token, long>>(cout));
}
