/** @file list3801.cpp */
/** Listing 38-1. Defining a Derived Class */
#include <iostream>
#include <string>
#include <string_view>

class work
{
public:
  work() = default;
  work(work const&) = default;
  work(std::string_view id, std::string_view title) : id_{id}, title_{title} {}
  std::string const& id()    const { return id_; }
  std::string const& title() const { return title_; }
private:
  std::string id_;
  std::string title_;
};

class book : public work
{
public:
  book() : work{}, author_{}, pubyear_{} {}
  book(book const&) = default;
  book(std::string_view id, std::string_view title, std::string_view author,
       int pubyear)
  : work{id, title}, author_{author}, pubyear_{pubyear}
  {}
  std::string const& author() const { return author_; }
  int pubyear()               const { return pubyear_; }
private:
  std::string author_;
  int pubyear_; ///< year of publication
};

class periodical : public work
{
public:
  periodical() : work{}, volume_{0}, number_{0}, date_{} {}
  periodical(periodical const&) = default;
  periodical(std::string_view id, std::string_view title, int volume,
             int number,
 std::string_view date)
  : work{id, title}, volume_{volume}, number_{number}, date_{date}
  {}
  int volume()              const { return volume_; }
  int number()              const { return number_; }
  std::string const& date() const { return date_; }
private:
  int volume_;       ///< volume number
  int number_;       ///< issue number
  std::string date_; ///< publication date
};

int main()
{
    book b{"1", "Exploring C++ 20", "Ray Lischner", 2020};
    periodical p{"2", "The C++ Times", 1, 1, "Jan 1, 2020"};
    std::cout << b.title() << '\n' <<
                 p.title() << '\n';
}
