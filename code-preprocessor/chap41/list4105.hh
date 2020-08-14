/** @file list4105.hh */
/** Listing 41-5. Generating Unique Identification Numbers */
int generate_id()
{
  static int counter{0};
  ++counter;
  return counter;
}
