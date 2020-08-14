/** @file list5104.cpp */
/** Listing 51-4. Mystery Function Template */
template<class T>
T add(T lhs, T rhs)
{
  return lhs(rhs);
}

int main()
{
}
