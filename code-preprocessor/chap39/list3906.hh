/** @file list3906.hh */
/** Listing 39-6. Adding a print Member Function to the movie Class */
class movie : public work
{
public:
  movie() : work{}, runtime_{0} {}
  movie(movie const&) = default;
  movie(std::string_view id, std::string_view title, int runtime)
  : work{id, title}, runtime_{runtime}
  {}
  int runtime() const { return runtime_; }
  void print(std::ostream& out)
  const override
  {
    out << title() << " (" << runtime() << " min)";
  }
private:
  int runtime_; ///< running length in minutes
};
