#include <iostream>
#include <array>
#include <cassert>

class IntPair
{
public:
    int x {};
    int y {};

    void set(int value1, int value2)
    {
        x = value1;
        y = value2;
    }

    void print() {
        std::cout << "Pair(" << x << ", " << y << ")\n";
    }
};

class DateClass // members are private by default
{
	int m_month {}; // private by default, can only be accessed by other members
	int m_day {}; // private by default, can only be accessed by other members
	int m_year {}; // private by default, can only be accessed by other members

public:
	void setDate(int month, int day, int year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}

	void print()
	{
		std::cout << m_month << '/' << m_day << '/' << m_year;
	}

	// Note the addition of this function
	void copyFrom(const DateClass& d)
	{
		// Note that we can access the private members of d directly
		m_month = d.m_month;
		m_day = d.m_day;
		m_year = d.m_year;
	}
};

class SimpleStack
{
private:
    std::array<int, 10> arr {};
    std::size_t size { 0 };
public:
    void reset()
    {
        size = 0;
    }

    bool push(int value)
    {
        if(size >= arr.size()) return false;
        arr[size] = value;
        ++size;
        return true;
    }

    int pop()
    {
        assert(size > 0);
        return arr[size--];
    }

    void print() {
        std::cout << "( ";
        for(std::size_t i {0}; i < size; ++i)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << ")\n";
    }
};

int main()
{
    IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

    DateClass date;
	date.setDate(10, 14, 2020); // okay, because setDate() is public

	DateClass copy {};
	copy.copyFrom(date); // okay, because copyFrom() is public
	copy.print();
	std::cout << '\n';

    SimpleStack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}