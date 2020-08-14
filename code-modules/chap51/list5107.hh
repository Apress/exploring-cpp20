/** @file list5107.hh */
/** Listing 51-7. The std::min Algorithm */
template<class T>
T min(T a, T b)
{
  if (b < a)
    return b;
  else
    return a;
}
