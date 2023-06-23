#include "Monster.h"
#include "Random.h"

#include <iostream>
#include <array>

namespace MonsterGenerator
{
  Monster generate()
  {
    Monster::Type type {
      static_cast<Monster::Type>(Random::get(0, Monster::Type::max_monster_types-1))
    };
    int hit_points { Random::get(1, 100) };

    static constexpr std::array s_names {
      "name1", "name2", "name3", "name4", "name5", "name6"
    };
    static constexpr std::array s_roars {
      "roar1", "roar2", "roar3", "roar4", "roar5", "roar6"
    };

    std::string_view random_name { s_names[Random::get<std::size_t>(0, s_names.size() -1)] };
    std::string_view random_roar { s_roars[Random::get<std::size_t>(0, s_roars.size() -1)] };

    return Monster { type, random_name, random_roar, hit_points };
  };
};

int main()
{
  Monster m{ MonsterGenerator::generate() };
	m.print();

  return 0;
}