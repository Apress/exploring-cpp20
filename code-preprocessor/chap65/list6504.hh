/** @file list6504.hh */
/** Listing 65-4. Implementing the artifact Module */
//module artifact;
#include "artifact.hpp"

#include <filesystem>
#include <memory>
#include <string>
#include <system_error>

#include "variables.hpp"

class artifact_impl
{
public:
  using file_time_type = std::filesystem::file_time_type;
  artifact_impl() : name_{}, mod_time_{file_time_type::min()}, vars_{} {}
  artifact_impl(std::string name)
  : name_{std::move(name)}, mod_time_{get_mod_time()}, vars_{}
  {}

  std::string const& name() const { return name_; }
  file_time_type mod_time() const { return mod_time_; }

  file_time_type get_mod_time()
  const
  {
    std::error_code ec;
    auto time{ std::filesystem::last_write_time(name(), ec) };
    if (ec)
        return file_time_type::min();
    else
        return time;
  }

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


artifact::artifact() : pimpl_{std::make_shared<artifact_impl>()} {}

artifact::artifact(std::string name)
: pimpl_(std::make_shared<artifact_impl>(std::move(name)))
{}

std::string const& artifact::name()
const
{
   return pimpl_->name();
}

artifact::file_time_type artifact::mod_time()
const
{
   return pimpl_->mod_time();
}

std::string artifact::expand(std::string const& str)
const
{
   return pimpl_->expand(str);
}

artifact::file_time_type artifact::get_mod_time()
const
{
   return pimpl_->get_mod_time();
}

void artifact::define(std::string const& name, std::string const& value)
{
    pimpl_->define(name, value);
}
