#include <string_view>
#include <iostream>

enum class MonsterType {
  ogre, dragon, orc, spider,slime
};

std::string_view getMonsterType(MonsterType mType) {
  using enum MonsterType;

  switch(mType) {
    case ogre: return "ogre";
    case dragon: return "dragon";
    case orc: return "orc";
    case spider: return "spider";
    case slime: return "slime";
    default: return "???";
  }
}

struct Monster {
  MonsterType type {};
  std::string_view name {};
  int healthAmount {};
};

void printMonster(Monster& mtr) {
  std::cout << "This " << getMonsterType(mtr.type) << " is named " << mtr.name << " and has " << mtr.healthAmount << " hearth\n";
}


int main(){
  Monster m1 { MonsterType::ogre, "Torg", 145 };
  Monster m2 { MonsterType::slime, "Blurp", 23 };

  printMonster(m1);
  printMonster(m2);
  return 0;
}