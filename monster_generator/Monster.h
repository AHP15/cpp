#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <string_view>

class Monster
{
public:
  enum Type
  {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,

    max_monster_types
  };

private:
  Type m_type{};
  std::string m_name{};
  std::string m_roar{};
  int m_hit_points{};
public:
  Monster(Type type, std::string_view name, std::string_view roar, int hit_points);
  void print() const;
  std::string_view getTypeString(Monster::Type type) const;
};

#endif