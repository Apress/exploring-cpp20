/** @file list4207.cc */
/** Listing 42-7. The vital_stats Class to Record a Person’s Vital Statistics */
export module stats;
import <istream>;
import <ostream>;
export import <string>;

export class vital_stats
{
public:
  inline vital_stats() : height_{0}, weight_{0}, bmi_{0}, sex_{'?'}, name_{}
  {}

  bool read(std::istream& in, int num);
  void print(std::ostream& out, int threshold) const;

private:
  int compute_bmi() const; ///< Return BMI, based on height_ and weight_
  int height_;             ///< height in centimeters
  int weight_;             ///< weight in kilograms
  int bmi_;                ///< Body-mass index
  char sex_;               ///< 'M' for male or 'F' for female
  std::string name_;       ///< Person’s name
};
