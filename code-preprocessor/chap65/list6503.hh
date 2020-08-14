/** @file list6503.hh */
/** Listing 65-3. Defining an artifact Pimpl Wrapper Class */
// export module artifact;
#include <filesystem>
#include <memory>
#include <string>

class artifact_impl;

/*export*/ class artifact
{
public:
  using file_time_type = std::filesystem::file_time_type;
  artifact();
  artifact(std::string name);
  artifact(artifact const&) = default;
  artifact(artifact&&) = default;
  artifact& operator=(artifact const&) = default;
  artifact& operator=(artifact&&) = default;
  ~artifact() = default;

  std::string const& name() const;
  file_time_type mod_time() const;
  std::string expand(std::string const& str) const;

  void build() const;
  file_time_type get_mod_time() const;

  void define(std::string const& name, std::string const& value);

private:
  std::shared_ptr<artifact_impl> pimpl_;
};

/*export*/ bool operator==(artifact const& lhs, artifact const& rhs) {
    return lhs.name() == rhs.name();
}

namespace std {
  template<>
  /*export*/ struct hash<artifact> : std::hash<std::string> {
    using super = std::hash<std::string>;
    std::size_t operator()(artifact const& a) const {
      return super::operator()(a.name());
    }
  };
}
