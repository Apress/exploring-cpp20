/** @file list6403.hh */
/** Listing 64-3. Adding a Move Constructor to the artifact Class */
// export module artifact;
#include <filesystem>
#include <string>
#include <system_error>

#include "variables.hpp"

/*export*/ class artifact
{
public:
  using file_time_type = std::filesystem::file_time_type;
  artifact() : name_{}, mod_time_{file_time_type::min()}, vars_{} {}
  artifact(std::string name)
  : name_{std::move(name)}, mod_time_{get_mod_time()}, vars_{}
  {}
  artifact(artifact&& src) noexcept
  : name_{std::move(src.name_)},
    mod_time_{std::move(src.mod_time_)},
    vars_{std::move(src.vars_)}
  {}

  std::string const& name() const { return name_; }
  file_time_type mod_time() const { return mod_time_; }

  file_time_type get_mod_time();

  void define(std::string const& name, std::string const& value);

  std::string expand(std::string const& input) const;

private:
  std::string name_;
  file_time_type mod_time_;
  variables vars_;
};
