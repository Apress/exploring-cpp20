/** @file list7303.cpp */
/** Listing 73-3. Using a Function Parameter Pack to Print Arbitrary Values */
import <iostream>;
import <utility>;

// Forward declaration.
template<class... Args>
void print(std::ostream& stream, Args&&...);

// Print the first value in the list, then recursively
// call print() to print the rest of the list.
template<class T, class... Args>
void print_split(std::ostream& stream, T&& head, Args&& ... rest)
{
   stream << head << ' ';
   print(stream, std::forward<Args>(rest)...);
}

// End recursion when there are no more values to print.
void print_split(std::ostream&)
{}

// Print an arbitrary list of values to a stream.
template<class... Args>
void print(std::ostream& stream, Args&&... args)
{
   print_split(stream, std::forward<Args>(args)...);
}

int main()
{
   print(std::cout, 42, 'x', "hello", 3.14159, 0, '\n');
}
