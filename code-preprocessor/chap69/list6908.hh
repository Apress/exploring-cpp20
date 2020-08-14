/** @file list6908.hh */
/** Listing 69-8. Adding a Protected Constructor to the assignment_mixin Class Template */
// export module mixin;

/*export*/ template<class T>
class assignment_mixin {
public:
   T& operator=(T rhs)
   {
      rhs.swap(static_cast<T&>(*this));
      return static_cast<T&>(*this);
   }
protected:
  assignment_mixin() {}
};
