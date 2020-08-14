/** @file list4002.cpp */
/** Listing 40-2. Defining Classes for height and weight */
#include <iostream>

/// Height in centimeters
class height
{
public:
  height(int h) : value_{h} {}
  int value() const { return value_; }
private:
  int value_;
};

/// Weight in kilograms
class weight
{
public:
  weight(int w) : value_{w} {}
  int value() const { return value_; }
private:
  int value_;
};

std::istream& operator>>(std::istream& stream, height& ht)
{
  int tmp;
  if (stream >> tmp)
    ht = height{tmp};
  return stream;
}

std::istream& operator>>(std::istream& stream, weight& wt)
{
  int tmp;
  if (stream >> tmp)
    wt = weight{tmp};
  return stream;
}

/// Body-mass index
class bmi
{
public:
  bmi() : value_{0} {}
  bmi(height h, weight w)
  : value_{(w.value() * 10000) / (h.value() * h.value())}
  {}
  int value() const { return value_; }
private:
  int value_;
};

std::ostream& operator<<(std::ostream& out, bmi x)
{
  return out << x.value();
}


int main()
{
  std::cout << "Height in centimeters: ";
  height h{0};
  std::cin >> h;

  std::cout << "Weight in kilograms: ";
  weight w{0};
  std::cin >> w;

  std::cout << "Bogus metabolic index = " << bmi(h, w) << '\n';
}
