/** @file list6903.hh */
/** Listing 69-3. The Hashable Interface in C++ */
class Hashable
{
public:
   virtual ~Hashable();
   virtual unsigned long hash() const = 0;
   virtual bool equalTo(Hashable const&) const = 0;
};
