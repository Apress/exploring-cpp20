/** @file list7004.hh */
/** Listing 70-4. The mystring Class Template */
import <algorithm>;
import <string>;

template<class Char, class Storage, class Traits = std::char_traits<Char>>
class mystring {
public:
   using value_type = Char;
   using size_type = std::size_t;
   using iterator = typename Storage::iterator;
   using const_iterator = Storage::const_iterator;

   mystring() : storage_{} {}
   mystring(mystring&&) = default;
   mystring(mystring const&) = default;
   mystring(Storage const& storage) : storage_{storage} {}
   mystring(Char const* ptr, size_type size) : storage_{} {
      resize(size);
      std::copy(ptr, ptr + size, begin());
   }
 
   static constexpr size_type npos = static_cast<size_type>(-1);

   mystring& operator=(mystring const&) = default;
   mystring& operator=(mystring&&) = default;

   void swap(mystring& str) { storage_.swap(str.storage_); }

   Char operator[](size_type i) const { return *(storage_.begin() + i); }
   Char& operator[](size_type i)      { return *(storage_.begin() + i); }

   void resize(size_type size, Char value = Char()) {
     storage_.resize(size, value);
   }
   void reserve(size_type size)    { storage_.reserve(size); }
   size_type size() const noexcept { return storage_.end() - storage_.begin(); }
   size_type max_size() const noexcept { return storage_.max_size(); }
   bool empty() const noexcept     { return size() == 0; }
   void clear()                    { resize(0); }
   void push_back(Char c)          { resize(size() + 1, c); }

   Char const* data() const        { return storage_.c_str(); }
   Char const* c_str() const       { return storage_.c_str(); }

   iterator begin()              { return storage_.begin(); }
   const_iterator begin() const  { return storage_.begin(); }
   const_iterator cbegin() const { return storage_.begin(); }
   iterator end()                { return storage_.end(); }
   const_iterator end() const    { return storage_.end(); }
   const_iterator cend() const   { return storage_.end(); }

   size_type find(mystring const& s, size_type pos = 0) const {
      pos = std::min(pos, size());
      auto result{ std::search(begin() + pos, end(),
                               s.begin(), s.end(), Traits::eq) };
      if (result == end())
         return npos;
      else
         return static_cast<size_type>(result - begin());
   }
         
private:
   Storage storage_;
};

template<class Char, class Storage1, class Storage2, class Traits>
bool operator <(mystring<Char, Storage1, Traits> const& a,
                mystring<Char, Storage2, Traits> const& b)
{
   return std::lexicographical_compare(
      a.begin(), a.end(), b.begin(), b.end(), Traits::lt
   );

}

template<class Char, class Storage1, class Storage2, class Traits>
bool operator ==(mystring<Char, Storage1, Traits> const& a,
                 mystring<Char, Storage2, Traits> const& b)
{
   return std::equal(a.begin(), a.end(), b.begin(), b.end(), Traits::eq);
}
