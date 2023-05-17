#include <iostream>

namespace MonsterType {
    enum MonsterType {
      orcs,
      goblins,
      trolls,
      ogres,
      skeletons,
    }   ;
}
int main() {
    MonsterType::MonsterType trl { MonsterType::trolls };
    if (trl == MonsterType::trolls) {
        std::cout << "Ok";
    }
    return 0;
}