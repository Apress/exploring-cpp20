/** @file snip5202.hh */
/** Code Snippet 52-2 */
class point {
public:
   point(double x, double y) : x_{x}, y_{y} {}
   double x() const { return x_; }
   double y() const { return y_; }
private:
   double x_, y_;
};
