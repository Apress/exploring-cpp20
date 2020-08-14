/** @file list4703.cpp */
/** Listing 47-3. Computing Scores By Using Views */
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::cout << "Enter the scores: ";
    std::vector<int> scores{};
    std::ranges::copy(std::ranges::istream_view<int>(std::cin),
        std::back_inserter(scores));
    std::ranges::sort(scores);
    auto drop_high{ scores | std::ranges::views::take(scores.size() - 1) };
    auto remaining_scores{ drop_high | std::ranges::views::drop(1) };

    int sum{0};
    int count{0};
    for (int score : remaining_scores)
    {
        ++count;
        sum += score;
    }
    std::cout << "mean score is " << sum / count << '\n';
}
