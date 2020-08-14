/** @file list6906.hh */
/** Listing 69-6. The assignment_mixin Class Template */
// export module mixin;

/*export*/ template<class T>
class assignment_mixin {
public:
   T& operator=(T rhs)
   {
      rhs.swap(static_cast<T&>(*this));
      return static_cast<T&>(*this);
   }
};
