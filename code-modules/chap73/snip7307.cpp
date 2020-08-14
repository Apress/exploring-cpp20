constexpr int ITERATOR_TYPE = 2;
struct pedantic_iterator {};
struct safe_iterator {};
struct fast_iterator {};
#include "list7310.hh"
#include "snip7307.hh"

static_assert(std::is_same<fast_iterator, iterator>::value);
int main() {
}
