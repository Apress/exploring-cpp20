/** @file list5102.hh */
/** Listing 51-2. Writing a Function Template */
template<class T>
T absval(T x)
{
  if (x < 0)
    return -x;
  else
    return x;
}
