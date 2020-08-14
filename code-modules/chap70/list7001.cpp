/** @file list7001.cpp */
/** Listing 70-1. One Possible Implementation of std::advance */
import <deque>;
import <iostream>;
import <iterator>;
import <list>;
import <string_view>;
import <vector>;

void trace(std::string_view msg)
{
   std::cout << msg << '\n';
}

template<class Iterator, class Distance>
requires std::random_access_iterator<Iterator> and std::integral<Distance>
void advance(Iterator& iterator, Distance distance)
{
    trace("random access or contiguous advance");
    iterator += distance;
}

template<class Iterator, class Distance>
requires std::bidirectional_iterator<Iterator> and std::integral<Distance>
void advance(Iterator& iterator, Distance distance)
{
    trace("bidirectional iterator");
    for ( ; distance < 0; ++distance)
        --iterator;
    for ( ; distance > 0; --distance)
        ++iterator;
}

template<class Iterator, class Distance>
requires std::input_iterator<Iterator> and std::unsigned_integral<Distance>
void advance(Iterator& iterator, Distance distance)
{
    trace("forward or input iterator");
    for ( ; distance > 0; --distance)
        ++iterator;
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
