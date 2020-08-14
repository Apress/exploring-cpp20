#ifndef TEST_HPP_
#define TEST_HPP_

#include <cstdlib>
#include <exception>
#include <iostream>
#include <tuple>

inline long long fail_count{0};

/// Exit the program.
/// If all tests passed, exit with a success code.
/// If any test failed, print the count of the number of failed tests,
/// and exit with a failure status code.
inline void test_exit()
{
  if (fail_count == 0)
	std::exit(0);
  else
  {
    std::cerr << "# tests failed: " << fail_count << '\n';
    std::exit(1);
  }
}

constexpr void print_stderr() {}

template<class Head, class... Rest>
inline void print_stderr(Head&& head, Rest&&... rest)
{
	std::cout << std::forward<Head>(head);
	print_stderr(std::forward<Rest>(rest)...);
}

// For internal use by the test() macro.
// Report a test failure.
template<class... Args>
inline void test_failed(char const* file, int line, Args&&... args)
{
  std::cerr << file << ", line " << line << ": test failed: ";
  print_stderr(std::forward<Args>(args)...);
  std::cerr << std::endl;
  ++fail_count;
}


template<class T>
inline void test(char const* file, unsigned long long line, T const& _condition_)
{
  if (not static_cast<bool>(_condition_))
  {
    test_failed(file, line, "Expected true");
  }
}

/// Test a condition.
/// If @p _condition_ evaluates to @c true the test passes.
/// If not, the test fails, and a message is printed to @c cerr.
/// The text of @p _condition_, plus the file name and line number are printed.
///
/// See Boost.Test for a real test framework
///
/// @param _condition_ A condition to test; the condition must be able to be converted implicitly to @c bool.
#define TEST(...) test(__FILE__, __LINE__, __VA_ARGS__)

/// Test for equality.
/// If `x == y` the test passes. Otherwise, it fails,
/// and a message is printed to @c cerr.
/// The text of @p x and @p y, plus the file name and line number, are printed.
///
/// See Boost.Test for a real test framework
///
/// @param _expected_ A value to compare
/// @param _actual_ A value to compare
template<class E, class A>
inline void test_equal(char const* file, unsigned long long line, E const& expected, A const& actual)
{
  if (not (expected == actual))
  {
    test_failed(file, line, "Expected equality\n"
      "Expected: \"", expected, "\"\n",
      "But got:  \"", actual, '"');
  }
}

#define TEST_EQUAL(...) test_equal(__FILE__, __LINE__, __VA_ARGS__)

#endif
