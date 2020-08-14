/** @file list4205.cc */
/** Listing 42-5. Defining the rational Class In a Module Interface */
// export module rat3;
/*export*/ class rational
{
public:
  inline rational(int num) : numerator_{num}, denominator_{1} {}
  inline rational(rational const&) = default;
  inline rational(int num, int den)
  : numerator_{num}, denominator_{den}
  {
    reduce();
  }
  void assign(int num, int den);
  inline int numerator() const           { return numerator_; }
  inline int denominator() const         { return denominator_; }
  rational& operator=(int num);
private:
  void reduce();
  int numerator_;
  int denominator_;
};
