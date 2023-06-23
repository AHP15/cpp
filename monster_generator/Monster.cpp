#include "Monster.h"

#include <iostream>

std::string_view Monster::getTypeString(Monster::Type type) const
{
  switch (type)
  {
  case Monster::Dragon: return "Dragon";
  case Monster::Goblin: return "Goblin";
  case Monster::Ogre: return "Ogre";
  case Monster::Orc: return "Orc";
  case Monster::Skeleton: return "Skeleton";
  case Monster::Troll: return "Troll";
  case Monster::Vampire: return "Vampire";
  case Monster::Zombie: return "Zombie";
  default:
    return "Unknow";
  }
}

Monster::Monster(Type type, std::string_view name, std::string_view roar, int hit_points)
  : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hit_points{ hit_points }
{}

void Monster::print() const
  {
    std::cout << m_name << " the "
              << Monster::getTypeString(m_type) << " has "
              << m_hit_points << " hit points and says "
              << m_roar << '\n';
  }