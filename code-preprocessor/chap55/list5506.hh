/** @file list5506.hh */
/** Listing 55-6. Defining the store Function Template */
#include <algorithm>
#include <concepts>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

template<class Range>
concept can_reserve =
        std::ranges::sized_range<Range> and
        requires(Range r) {
            r.reserve(0);
        };

template<class Container>
concept can_insert_back =
    requires(Container c) {
        std::back_inserter(c);
    };

template<can_insert_back Container>
class store_t
{
public:
    using container_type = Container;
    using value_type = std::ranges::range_value_t<container_type>;
    store_t(container_type& output) : output_{output} {}

    template<can_reserve Range>
    Container& operator()(Range const& input) const {
        output_.reserve(std::ranges::size(output_)+std::ranges::size(input));
        std::ranges::copy(input, std::back_inserter(output_));
        return output_;
    }

    template<class Range>
    requires (not can_reserve<Range>)
    Container& operator()(Range const& input) const {
        std::ranges::copy(input, std::back_inserter(output_));
        return output_;
    }
private:
    container_type& output_;
};

template<class T>
store_t<T> store(T& container) { return store_t<T>(container); }

template<class In, class Out>
Out& operator|(In range, store_t<Out> const& storer)
{
    return storer(std::forward<In>(range));
}

int main() {
   std::vector<std::string> strings{ "this" " is ", "a", " test", ".\n" };
   std::string str;
   std::ranges::views::join(strings) | store(str);
   std::cout << str;
}
