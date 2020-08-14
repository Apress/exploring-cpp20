#define ARTIFACT_LISTING "list6403.hh"
#define VARIABLES_LISTING "list6305.hh"

#include "artifact.hpp"

artifact::file_time_type artifact::get_mod_time()
  {
    std::error_code ec;
    auto time{ std::filesystem::last_write_time(name_, ec) };
    if (ec)
        return file_time_type::min();
    else
        return time;
  }

  void artifact::define(std::string const& name, std::string const& value)
  {
    vars_.define(name, value);
  }

  std::string artifact::expand(std::string const& input)
  const
  {
    return vars_.expand(input);
  }

#include "list6308.hh"
