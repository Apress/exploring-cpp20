/** @file list7008.hh */
/** Listing 70-8. Input Function for mystring */
template<class Char, class Storage, class Traits>
std::basic_istream<Char, Traits>&
  operator>>(std::basic_istream<Char, Traits>& stream,
             mystring<Char, Storage, Traits>& string)
{
   typename std::basic_istream<Char, Traits>::sentry sentry{stream};
   if (sentry)
   {
      std::ctype<Char> const& ctype(
         std::use_facet<std::ctype<Char>>(stream.getloc()) );
      std::ios_base::iostate state{ std::ios_base::goodbit };
      std::size_t max_chars{ string.max_size() };
      if (stream.width() != 0 and std::size_t(stream.width()) < max_chars)
         max_chars = stream.width();
      string.clear();
      while (max_chars-- != 0) {
         typename Traits::int_type c{ stream.rdbuf()->sgetc() };
         if (Traits::eq_int_type(Traits::eof(), c)) {
            state |= std::ios_base::eofbit;
            break; // is_eof
         }
         else if (ctype.is(ctype.space, Traits::to_char_type(c)))
            break;
         else {
            string.push_back(Traits::to_char_type(c));
            stream.rdbuf()->sbumpc();
         }
      }
      if (string.empty())
         state |= std::ios_base::failbit;
      stream.setstate(state);
      stream.width(0);
   }
   return stream;
}
