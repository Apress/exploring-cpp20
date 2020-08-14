/** @file list6716.cpp */
/** Listing 67-16. The find_pair Function and Test Program */
#include <bitset>
#include <iostream>

template<std::size_t N>
std::size_t find_pair(std::bitset<N> const& bitset, bool value)
{
   if (bitset.size() >= 2)
      for (std::size_t i{bitset.size()}; i-- != 1; )
         if (bitset[i] == value and bitset[i-1] == value)
            return i;
   return std::size_t(-1);
}

void test(bool condition) {
    if (not condition)
        throw std::logic_error("test failure");
}

int main()
{
   auto constexpr static not_found{static_cast<std::size_t>(-1)};
   std::bitset<0> bs0{};
   std::bitset<1> bs1{};
   std::bitset<2> bs2{};
   std::bitset<3> bs3{};
   std::bitset<100> bs100{};

   test(find_pair(bs0, false) == not_found);
   test(find_pair(bs0, true) == not_found);
   test(find_pair(bs1, false) == not_found);
   test(find_pair(bs1, true) == not_found);
   test(find_pair(bs2, false) == 1);
   test(find_pair(bs2, true) == not_found);
   bs2[0] = true;
   test(find_pair(bs2, false) == not_found);
   test(find_pair(bs2, true) == not_found);
   bs2.flip();
   test(find_pair(bs2, false) == not_found);
   test(find_pair(bs2, true) == not_found);
   bs2[0] = true;
   test(find_pair(bs2, false) == not_found);
   test(find_pair(bs2, true) == 1);
   test(find_pair(bs3, false) == 2);
   test(find_pair(bs3, true) == not_found);
   bs3[2].flip();
   test(find_pair(bs3, false) == 1);
   test(find_pair(bs3, true) == not_found);
   bs3[1].flip();
   test(find_pair(bs3, false) == not_found);
   test(find_pair(bs3, true) == 2);
   test(find_pair(bs100, false) == 99);
   test(find_pair(bs100, true) == not_found);
   bs100[50] = true;
   test(find_pair(bs100, true) == not_found);
   bs100[51] = true;
   test(find_pair(bs100, true) == 51);
   std::cout << "pass\n";
}
