/** @file list6405.hh */
/** Listing 64-5. Using a Unique Pointer For the variables Member */
export module artifact;
import <filesystem>;
import <memory>;
import <string>;
import <system_error>;

import variables;

export class artifact
{
public:
  using file_time_type = std::filesystem::file_time_type;
  artifact() : name_{}, mod_time_{file_time_type::min()}, vars_{} {}
  artifact(std::string name)
  : name_{std::move(name)}, mod_time_{get_mod_time()}, vars_{}
  {}
  artifact(artifact const&) = delete; // move-only
  artifact& operator=(artifact const&) = delete; // move-only
  artifact(artifact&&) = default;
  artifact& operator=(artifact&&) = default;
  ~artifact() = default;

  std::string const& name() const { return name_; }
  file_time_type mod_time() const { return mod_time_; }

  file_time_type get_mod_time();

  void define(std::string const& name, std::string const& value)
  {
     if (not vars_)
        vars_ = std::make_unique<variables>();
     vars_->define(name, value);
  }

  std::string expand(std::string const& input) 
  const
  {
     if (vars_)
        return vars_->expand(input);
     else
        return global_variables.expand(input);
  }

private:
  std::string name_;
  file_time_type mod_time_;
  std::unique_ptr<variables> vars_;
};
