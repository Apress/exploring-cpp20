/** @file list7005.hh */
/** Listing 70-5. The vector_storage Class Template */
#include <vector>

template<class Char>
class vector_storage {
public:
   using size_type = std::size_t;
   using value_type = Char;
   using iterator = std::vector<Char>::iterator;
   using const_iterator = std::vector<Char>::const_iterator;

   vector_storage() : string_{1, Char{}} {}

   void swap(vector_storage& storage) { string_.swap(storage.string_); }
   size_type max_size() const { return string_.max_size() - 1; }
   void reserve(size_type size) { string_.reserve(size + 1); }
   void resize(size_type newsize, value_type value) {
      // if the string grows, overwrite the null character, then resize
      if (newsize >= string_.size()) {
         string_[string_.size() - 1] = value;
         string_.resize(newsize + 1, value);
      }
      else
         string_.resize(newsize + 1);
      string_[string_.size() - 1] = Char{};
   }
   Char const* c_str() const { return &string_[0]; }

   iterator begin()             { return string_.begin(); }
   const_iterator begin() const { return string_.begin(); }
   // Skip over the trailing null character at the end of the vector
   iterator end()               { return string_.end() - 1; }
   const_iterator end() const   { return string_.end() - 1; }

private:
   std::vector<Char> string_;
};
