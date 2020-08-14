/** @file list5605.hh */
/** Listing 56-5. Coping with Conflicting Names */
#include <cmath>
#include <numeric>
#include <vector>

namespace stats {
  // Really bad name for a functor to compute sum of squares,
  // for use in determining standard deviation.
  class std
  {
  public:
    std(double mean) : mean_{mean} {}
    double operator()(double acc, double x)
    const
    {
      return acc + square(x - mean_);
    }
    double square(double x) const { return x * x; }
  private:
    double mean_;
  };

  // Really bad name for a function in the stats namespace.
  // It computes standard deviation.
  double stats(::std::vector<double> const& data)
  {
    double std{0.0}; // Really, really bad name for a local variable
    if (not data.empty())
    {
      double sum{::std::accumulate(data.begin(), data.end(), 0.0)};
      double mean{sum / data.size()};
      double sumsq{::std::accumulate(data.begin(), data.end(), 0.0,
                   stats::std(mean))};
      double variance{sumsq / data.size() - mean * mean};
      std = ::std::sqrt(variance);
    }
    return std;
  }
}
