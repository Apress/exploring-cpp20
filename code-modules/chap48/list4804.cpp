/** @file list4804.cpp */
/** Listing 48-4. Nested Exceptions */
import <exception>;
import <fstream>;
import <iomanip>;
import <iostream>;
import <stdexcept>;

void print_exception(const std::exception& e, int level =  0)
{
  std::cerr << std::setw(level) << ' ' << "exception: " << e.what() << '\n';
  try {
    std::rethrow_if_nested(e);
  } catch(const std::exception& e) {
    // caught a nested exception
    print_exception(e, level+1);
  } catch(...) {}
}

int main()
{
  std::string const filename{ "nonexistent file" };
  std::ifstream file;
  file.exceptions(std::ios_base::failbit);
  try
  {
    file.open(filename);
  }
  catch (std::ios_base::failure const&)  {
    std::throw_with_nested(std::runtime_error{"Cannot open: " + filename});
  }
  catch (...)
  {
    file.close();
    throw;
  }
}
