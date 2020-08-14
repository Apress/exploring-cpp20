/** @file list3907.hh */
/** Listing 39-7. Defining work As an Abstract Class */
class work
{
public:
  work() = default;
  work(work const&) = default;
  work(std::string_view id, std::string_view title) : id_(id), title_(title) {}
  virtual ~work() {}
  std::string const& id()    const { return id_; }
  std::string const& title() const { return title_; }
  virtual void print(std::ostream& out) const = 0;
private:
  std::string id_;
  std::string title_;
};
