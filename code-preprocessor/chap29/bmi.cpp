/** @file
 * @brief Compute body-mass index.
 */
/** @mainpage Project 1 - Bogus Metabolic Indicator
 * This program is Project 1 in <em>Exploring C++ 20</em>,
 * by Ray Lischner (Apress).
 *
 * Your task is to write a program that reads records,
 * prints the records, and computes some statistics.
 * The program should start by asking for a threshold BMI.
 * Only records with a BMI greater than or equal to the threshold will be printed.
 * Each record needs to consist of a person’s name (which may contain spaces),
 * weight in kilograms, height in centimeters (not meters),
 * and the person’s sex ('M' or 'F').
 * Let the user enter the sex in uppercase or lowercase.
 * Ask the user to enter the height in centimeters,
 * so you can compute the BMI using integers.
 * You will have to adjust the formula to allow for centimeters instead of meters.
 *
 * Print each person’s BMI immediately after reading his or her record.
 * After collecting information for everyone, print two tables—one for men,
 * one for women—based on the data.
 * Use an asterisk after the BMI rating to mark records for which the
 * number meets or exceeds the threshold.
 * After each table, print the mean (average) and median BMI.
 * (Median is the value at which half the BMI values are less than the
 * median and half are greater than the median.
 * If the user enters an even number of records,
 * take the mean of the two values in the middle.)
 * Compute individual BMI values as integers.
 * Compute the mean and median BMI values as floating-point numbers,
 * and print the mean with one place after the decimal point.
 *
 * BMI is defined as weight in kg/(height in m)<sup>2</sup>,
 * converted to a unitless number.
 *
 * Source file:
 * @author Ray Lischner
 */

#include <cstdlib>

#include <algorithm>
#include <format>
#include <iostream>
#include <istream>
#include <limits>
#include <locale>
#include <ostream>
#include <string>
#include <vector>

/** @brief Compute the Bogus Metabolic Indicator (BMI).
 * The height is in centimeters, so the computed value
 * is off by 10,000. Integer division truncates, but we
 * want to round off to nearest, so add 0.5 and then
 * truncate by casting to an integer.
 *
 * @param height The person's height in centimeters.
 * @param weight The person's weight in kilograms.
 * @return the person's BMI, rounded to an integer
 */
int compute_bmi(int height, int weight)
{
   return static_cast<int>(weight * 10000 / (height * height) + 0.5);
}

/** @brief Skip the rest of the input line. */
void skip_line()
{
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

/** @brief Get a single person's record.
 * Store the name, height, weight, and sex in the supplied vectors.
 * @param names array of persons' full names
 * @param heights array of height in centimeters
 * @param weights array of weight in kilograms
 * @param sexes array of persons' sex: 'M' means male and 'F' means female
 * @return true to continue reading records or false to stop
 */
bool get_record(std::vector<std::string>& names,
                std::vector<int>& heights,
                std::vector<int>& weights,
                std::vector<char>& sexes)
{
   std::string name;
   int height{0};
   int weight{0};
   char sex{'?'};

  std::cout << "Name " << names.size()+1 << ": ";
  if (not std::getline(std::cin, name))
    return false;

  // Enforce minimal sanity check on the height, which must be
  // between 10 and 300 cm, or baby- to giant-size.
  int const min_height{10};
  int const max_height{300};
  std::cout << "Height (cm): ";
  if (not (std::cin >> height))
    return false;
  skip_line();
  if (height < min_height or height > max_height)
  {
    std::cout << "Invalid height. Aborting.\n";
    return false;
  }

  // Enforce minimal sanity check on the weight, which must
  // be between premature-baby and giant size.
  const int min_weight{1};
  const int max_weight{500};
  std::cout << "Weight (kg): ";
  if (not (std::cin >> weight))
    return false;
  skip_line();
  if (weight < min_weight or weight > max_weight)
  {
    std::cout << "Invalid weight. Aborting.\n";
    return false;
  }

  std::cout << "Sex (M, F, etc.): ";
  if (not (std::cin >> sex))
    return false;
  skip_line();
  sex = std::toupper(sex, std::locale{});
  if (not std::isalpha(sex, std::locale{}))
  {
    std::cout << "Invalid sex. Must be a letter. Aborting.\n";
    return false;
  }

  // All information has now been collected, so
  // append it all to the respective vectors.
  names.emplace_back(name);
  heights.emplace_back(height);
  weights.emplace_back(weight);
  sexes.emplace_back(sex);

  return true;
}

/** @brief Print a table.
 * Print a table of height, weight, sex, BMI, and name.
 * Print only records for which sex matches @p sex.
 * At the end of each table, print the mean and median BMI.
 *
 * @param sex the sex to match
 * @param heights the array of heights
 * @param weights the array of weights
 * @param bmis the array of BMIs
 * @param sexes the array of sexes
 * @param names the array of names
 * @param threshold print only elements for which BMI > this
 */
void print_table(char sex,
                 std::vector<int>         const& heights,
                 std::vector<int>         const& weights,
                 std::vector<int>         const& bmis,
                 std::vector<char>        const& sexes,
                 std::vector<std::string> const& names,
                 int                      threshold)
{
  std::cout << "Ht(cm) Wt(kg) Sex  BMI  Name\n";

  float bmi_sum{0};
  long int bmi_count{0};
  std::vector<int> tmpbmis; // store only the BMIs that are printed
                            // to compute the median
  for (std::vector<int>::size_type i(0); i != heights.size(); ++i)
    if (sexes.at(i) == sex)
    {
      bmi_sum = bmi_sum + bmis.at(i);
      ++bmi_count;
      tmpbmis.push_back(bmis.at(i));
      std::cout << std::format("{:6}{:7}{:3}{:6}\n",
			heights.at(i), weights.at(i), sexes.at(i), bmis.at(i));
      if (bmis.at(i) >= threshold)
        std::cout << '*';
      else
        std::cout << ' ';
      std::cout << ' ' << names.at(i) << '\n';
    }

  // If the vectors are not empty, print basic statistics.
  if (bmi_count != 0)
  {
    std::cout << std::format("Mean BMI = {:.1f}\n", bmi_sum / bmi_count);

    // Median BMI is trickier. The easy way is to sort the
    // array and pick out the middle item or items.
    // There is also a standard algorithm that lets you determine
    // the median in linear time, but the book has not discussed it.
    std::sort(tmpbmis.begin(), tmpbmis.end());
    std::cout << "Median BMI = ";
    // Index of median item.
    int i(tmpbmis.size() / 2);
    if (tmpbmis.size() % 2 == 0)
      std::cout << (tmpbmis.at(i) + tmpbmis.at(i-1)) / 2.0 << '\n';
    else
      std::cout << tmpbmis.at(i) << '\n';
  }
}

/** @brief Main program to compute BMI. */
int main()
{
  std::locale::global(std::locale(""));
  std::cout.imbue(std::locale());
  std::cin.imbue(std::locale());

  std::vector<std::string> names;
  std::vector<int>         heights;
  std::vector<int>         weights;
  std::vector<char>        sexes;
  std::vector<int>         bmis;
  int threshold;

  std::cout << "Enter threshold BMI: ";
  if (not (std::cin >> threshold))
    return EXIT_FAILURE;
  skip_line();

  std::cout << "Enter name, height (in cm),"
               " and weight (in kg) for each person:\n";
  while (get_record(names, heights, weights, sexes))
  {
    int bmi(compute_bmi(heights.back(), weights.back()));
    bmis.push_back(bmi);
    std::cout << "BMI = " << bmi << '\n';
  }

  // Print the data.
  std::cout << "\n\nMale data\n";
  print_table('M', heights, weights, bmis, sexes, names, threshold);
  std::cout << "\nFemale data\n";
  print_table('F', heights, weights, bmis, sexes, names, threshold);
}
