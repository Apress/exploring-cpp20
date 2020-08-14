/** @file list3603.hh */
/** Listing 36-3. The point Class Defined with the class Keyword */
class point
{
public:
  point() : r_{0.0}, angle_{0.0} {}

  double x() const { return distance() * std::cos(angle()); }
  double y() const { return distance() * std::sin(angle()); }

  double angle()    const { return angle_; }
  double distance() const { return r_; }

//   ... other member functions omitted for brevity ...

#include "list3603.inc0"

private:
  double r_;
  double angle_;
};
