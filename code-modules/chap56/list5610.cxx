/** @file list5610.cxx */
/** Listing 56-10. Reading and Writing Tokens */
import <algorithm>;
import <iostream>;
import <iterator>;
import <string>;
import <vector>;

namespace parser
{
  class token
  {
  public:
    token() : text_{} {}
    token(std::string& s) : text_{s} {}
    token& operator=(std::string const& s) { text_ = s; return *this; }
    std::string text() const { return text_; }
  private:
    std::string text_;
  };
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

int main()
{
  using namespace parser;
  using namespace std;

  vector<token> tokens{};
  ranges::copy(ranges::istream_view<token>(std::cin), back_inserter(tokens));
  ranges::copy(tokens, ostream_iterator<token>(cout, "\n"));
}
