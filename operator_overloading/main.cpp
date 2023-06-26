#include <iostream>
#include <numeric>

class Fraction
{
private:
  int m_numerator{0};
  int m_denominator{1};

public:
  Fraction() = default;
  Fraction(int numerator, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator}
  {
    reduce();
  }

  void print() const
  {
    std::cout << m_numerator << '/' << m_denominator << '\n';
  }

  void reduce()
  {
    int gcd { std::gcd(m_numerator, m_denominator) };
    if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
  }

  friend Fraction operator*(int integer, const Fraction& f);
  friend Fraction operator*(const Fraction& f, int integer);
  friend Fraction operator*(const Fraction& f1, const Fraction& f2);
  friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
  friend std::istream& operator>>(std::istream& in, Fraction& f);
  
  friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator!= (const Fraction& f1, const Fraction& f2);

	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);

	friend bool operator<= (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);

};

Fraction operator*(int integer, const Fraction& f)
{
  return {f.m_numerator * integer, f.m_denominator};
}

Fraction operator*(const Fraction& f, int integer)
{
  return integer * f;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
  return {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
  out << f.m_numerator << '/' << f.m_denominator;
  return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
  in >> f.m_numerator;
  // Ignore the '/' separator
	in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

  in >> f.m_denominator;

  // Since we overwrite the existing f1, we need to reduce again
	f.reduce();

  return in;
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!= (const Fraction& f1, const Fraction& f2)
{
	return !(operator==(f1, f2));
}

bool operator< (const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator);
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
	return operator<(f2, f1);
}

bool operator<= (const Fraction& f1, const Fraction& f2)
{
	return !(operator>(f1, f2));
}

bool operator>= (const Fraction& f1, const Fraction& f2)
{
	return !(operator<(f1, f2));
}

int main()
{
  Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';

  return 0;
}