/** @file snip5104.hh */
/** Code Snippet 51-4 */
rational absval(rational x)
{
  if (x < 0)
    return -x;
  else
    return x;
}
