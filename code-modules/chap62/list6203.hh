/** @file list6203.hh */
/** Listing 62-3. New Definition of an Artifact */
export module artifact;
import <filesystem>;
import <string>;
import <system_error>;

export class artifact
{
public:
  using file_time_type = std::filesystem::file_time_type;
  artifact() : name_{}, mod_time_{file_time_type::min()} {}
  artifact(std::string const& name)
  : name_{name}, mod_time_{get_mod_time()}
  {}

  std::string const& name() const { return name_; }
  file_time_type mod_time() const { return mod_time_; }

  /// Builds a target.
  /// After completing the actions (not yet implemented),
  /// update the modification time.
  void build();

  /// Looks up the modification time of the artifact.
  /// Returns file_time_type::min() if the artifact does not
  /// exist (and therefore must be built) or if the time cannot
  /// be obtained for any other reason.
  file_time_type get_mod_time()
  {
    std::error_code ec;
    auto time{ std::filesystem::last_write_time(name_, ec) };
    if (ec)
        return file_time_type::min();
    else
        return time;
  }
private:
  std::string name_;
  file_time_type mod_time_;
};
