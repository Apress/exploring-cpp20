template<class T>
class rational {
public:
	template<class U>
	rational<T>& operator=(rational<U> const& rhs);
	void assign(int,int) {}

	T numerator() const { return 0; }
	T denominator() const { return 1; }
};

#include "list5208.hh"

int main() {
	rational<int> r1;
	rational<long> r2;
	r1 = r2;
	r2 = r1;
	return sizeof(r2) == sizeof(r1);
}
