#include <format>
#include <iostream>
#include <limits>
#include <locale>

#include "stats.hpp"

/// Skip the rest of the input line.
/// @param in the input stream
void skip_line(std::istream& in)
{
  in.ignore(std::numeric_limits<int>::max(), '\n');
}

int vital_stats::compute_bmi()
const
{
   return static_cast<int>(weight_ * 10000 / (height_ * height_) + 0.5);
}

bool vital_stats::read(std::istream& in, int num)
{
  std::cout << "Name " << num << ": ";
  if (not std::getline(in, name_))
    return false;

  std::cout << "Height (cm): ";
  if (not (in >> height_))
    return false;
  skip_line(in);

  std::cout << "Weight (kg): ";
  if (not (in >> weight_))
    return false;
  skip_line(in);

  std::cout << "Sex: ";
  if (not (in >> sex_))
    return false;
  skip_line(in);
  sex_ = std::toupper(sex_, std::locale{});

  bmi_ = compute_bmi();

 return true;
}

void vital_stats::print(std::ostream& out, int threshold)
const
{
  std::format_to(std::ostreambuf_iterator<char>(out),
	"{:6}{:7}{: ^3}{:6}{} {}\n", height_, weight_, sex_, bmi_,
		(bmi_ >= threshold ? '*' : ' '), name_);
}
