#define ARTIFACT_LISTING "list6405.hh"
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

#include "list6308.hh"
