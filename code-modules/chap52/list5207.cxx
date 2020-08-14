/** @file list5207.cxx */
/** Listing 52-7. Trying to Mix rational Base Types */
import rational;

int main()
{
  rational<int> little{};
  rational<long> big{};
  big = little;
}
