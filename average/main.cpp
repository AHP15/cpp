#include <iostream>
#include <cstdint>

class Average
{
private:
  std::int32_t m_sum{};
  std::int8_t m_length{};
public:
  Average(std::int32_t sum = 0, std::int8_t length = 0)
    :m_sum{sum}, m_length{length}
  {};

  Average operator+=(int integer)
  {
    m_sum += integer;
    ++m_length;
    return *this;
  };

  friend std::ostream& operator<<(std::ostream& out, const Average& avg)
  {
    out << static_cast<double>(avg.m_sum) / avg.m_length;
    return out;
  };
};

int main()
{
  Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';
  return 0;
};