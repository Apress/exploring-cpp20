/** @file snip5201.hh */
/** Code Snippet 52-1 */
class point {
public:
   point(int x, int y) : x_{x}, y_{y} {}
   int x() const { return x_; }
   int y() const { return y_; }
private:
   int x_, y_;
};
