#include <iostream>
#include <cassert> // for assert
#include <cstdint> // for fixed width integers
#include <cmath> // for std::round()


class IntArray
{
private:
	int m_length{ 0 };
	int* m_array{ nullptr };

public:
	explicit IntArray(int length)
		: m_length{ length }
	{
		assert(length > 0 && "IntArray length should be a positive integer");

		m_array = new int[m_length] {};
	}

	// Copy constructor that does a deep copy
	IntArray(const IntArray& array)
		: m_length{ array.m_length }
	{
		// Allocate a new array
		m_array = new int[m_length];

		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete[] m_array;
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
	{
		for (int count{ 0 }; count < array.m_length; ++count)
		{
			out << array.m_array[count] << ' ';
		}
		return out;
	}

	int& operator[] (const int index)
	{
		assert(index >= 0);
		assert(index < m_length);
		return m_array[index];
	}

	// Assignment operator that does a deep copy
	IntArray& operator= (const IntArray& array)
	{
		if (this == &array)
			return *this;

		delete[] m_array;

		m_length = array.m_length;

		m_array = new int[m_length];

		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}

};

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

class FixedPoint2
{
private:
	std::int16_t m_base{}; // here's our non-fractional part
	std::int8_t m_decimal{}; // here's our factional part

public:
	FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0)
		: m_base{ base }, m_decimal{ decimal }
	{
		// We should handle the case where decimal is > 99 or < -99 here
		// but will leave as an exercise for the reader

		// If either (or both) of the non-fractional and fractional part of the number are negative, the number should be treated as negative
		if (m_base < 0 || m_decimal < 0)
		{
			// Make sure base is negative
			if (m_base > 0)
				m_base = -m_base;
			// Make sure decimal is negative
			if (m_decimal > 0)
				m_decimal = -m_decimal;
		}
	}

	FixedPoint2(double d):
		m_base{ static_cast<std::int16_t>(std::trunc(d)) },
		m_decimal{ static_cast<std::int8_t>(std::round(d * 100) - m_base * 100) }
	{
	}

	operator double() const
	{
		return m_base + (static_cast<double>(m_decimal) / 100);
	}

	friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
	{
		return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
	}

	FixedPoint2 operator-() const
	{
		// We need to cast, because the negative sign (-) converts our
		// narrow integers types to int.
		return {
			static_cast<std::int16_t>(-m_base),
			static_cast<std::int8_t>(-m_decimal)
		};
	}
};

// These don't require access to the internals of the class, so they can be defined outside the class
std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
	out << static_cast<double>(fp);
	return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp)
{
	double d{};
	in >> d;
	fp = FixedPoint2{ d };

	return in;
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
	return { static_cast<double>(fp1) + static_cast<double>(fp2) };
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}