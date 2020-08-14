/** @file list7002.cpp */
/** Listing 70-2. Implementing std::advance With Type Traits */
import <deque>;
import <iostream>;
import <iterator>;
import <list>;
import <string_view>;
import <type_traits>;
import <vector>;

void trace(std::string_view msg)
{
   std::cout << msg << '\n';
}

template<class Iterator, class Distance>
requires std::input_iterator<Iterator> and std::integral<Distance>
void advance(Iterator& iterator, Distance distance)
{
  using tag = std::iterator_traits<Iterator>::iterator_category;
  if constexpr(std::is_base_of<std::random_access_iterator_tag, tag>::value)
  {
    trace("random access+ iterator");
    iterator += distance;
  }
  else {
    trace("input+ iterator");
    if constexpr(std::is_base_of<std::bidirectional_iterator_tag,tag>::value)
    {
      while (distance++ < 0)
        --iterator;
    }
    while (distance-- > 0)
        ++iterator;
  }
}

template<class Iterator, class Distance>
void test(std::string_view label, Iterator iterator, Distance distance)
{
    advance(iterator, distance);
    std::cout << label << *iterator << '\n';
}

int main()
{
    std::deque<int> deque{ 1, 2, 3 };
    test("deque: ", deque.end(), -2);

    std::list<int> list{ 1, 2, 3 };
    test("list: ", list.end(), -2);

    std::vector<int> vector{ 1, 2, 3};
    test("vector: ", vector.end(), -2);
    
    test("istream: ", std::istream_iterator<int>{}, 2);
}
