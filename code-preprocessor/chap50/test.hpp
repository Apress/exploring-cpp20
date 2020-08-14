#ifndef TEST_HPP_
#define TEST_HPP_

#include <cstdlib>
#include <exception>
#include <iostream>
#include <tuple>

long long fail_count{0};

/// Exit the program.
/// If all tests passed, exit with a success code.
/// If any test failed, print the count of the number of failed tests,
/// and exit with a failure status code.
void test_exit()
{
  if (fail_count == 0)
	std::exit(0);
  else
  {
    std::cerr << "# tests failed: " << fail_count << '\n';
    std::exit(1);
  }
}

void print_stderr() {}

template<class Head, class... Rest>
void print_stderr(Head&& head, Rest&&... rest)
{
	std::cout << std::forward<Head>(head);
	print_stderr(std::forward<Rest>(rest)...);
}

// For internal use by the test() macro.
// Report a test failure.
template<class... Args>
inline void test_failed(Args&&... args)
{
  std::cerr << "test failed: ";
  print_stderr(std::forward<Args>(args)...);
  std::cerr << std::endl;
  ++fail_count;
}


/// Test a condition.
/// If @p _condition_ evaluates to @c true the test passes.
/// If not, the test fails, and a message is printed to @c cerr.
/// The text of @p _condition_, plus the file name and line number are printed.
///
/// See Boost.Test for a real test framework
///
/// @param _condition_ A condition to test; the condition must be able to be converted implicitly to @c bool.
template<class T>
void test(T const& _condition_)
{
  if (not static_cast<bool>(_condition_))
  {
    test_failed("FAIL Boolean test");
  }
}

/// Test for equality.
/// If `x == y` the test passes. Otherwise, it fails,
/// and a message is printed to @c cerr.
/// The text of @p x and @p y, plus the file name and line number, are printed.
///
/// See Boost.Test for a real test framework
///
/// @param _actual_ A value to compare
/// @param _expected_ A value to compare
template<class A, class E>
inline void test_equal(A const& actual, E const& expected)
{
  if (expected != actual)
  {
    test_failed("FAIL Equality test\n"
      "Expected: ", expected,
      "But got:  ", actual);
  }
}

#endif
