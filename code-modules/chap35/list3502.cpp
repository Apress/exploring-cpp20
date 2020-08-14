#include "bmi.hpp"  // includes list3502.hh

/** Main program to compute BMI. */
int main()
{
  std::locale::global(std::locale{""});
  std::cout.imbue(std::locale{});
  std::cin.imbue(std::locale{});

  std::vector<record> records{};
  int threshold{};

  std::cout << "Enter threshold BMI: ";
  if (not (std::cin >> threshold))
    return EXIT_FAILURE;
  skip_line(std::cin);

  std::cout << "Enter name, height (in cm),"
               " and weight (in kg) for each person:\n";
  record rec{};
  while (rec.read(std::cin, records.size()+1))
  {
    records.emplace_back(rec);
    std::cout << "BMI = " << rec.bmi_ << '\n';
  }

  // Print the data.
  std::cout << "\n\nMale data\n";
  print_table('M', records, threshold);
  std::cout << "\nFemale data\n";
  print_table('F', records, threshold);
}
