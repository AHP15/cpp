#include <string>
#include <iostream>
#include <array>
#include <random>
#include <cstdlib>
#include <ctime>


auto getRandomNumber(int min, int max)
{
  static std::mt19937 mt{};
	std::uniform_int_distribution die{ min, max };
  return die(mt);
};

class Creature
{
protected:
  std::string m_name{};
  char m_symbol{};
  int m_amount_of_health{};
  int m_amount_of_damage{};
  int m_amount_of_gold{};
public:
  Creature(std::string_view name, char symbol, int health, int damage, int gold)
    :m_name{name}, m_symbol{symbol}, m_amount_of_health{health}, m_amount_of_damage{damage}, m_amount_of_gold{gold}
  {}

  const std::string& getName() const { return m_name; }
  char getSymbol()             const { return m_symbol; }
  int getHealth()      const { return m_amount_of_health; }
  int getDamage()      const { return m_amount_of_damage; }
  int getGold()        const { return m_amount_of_gold; }
  bool isDead()                const { return m_amount_of_health <= 0; }

  void reduceHealth(int value){ m_amount_of_health-= value; }
  void addGold(int value) { m_amount_of_gold+= value; }
};

class Player: public Creature
{
private:
  static constexpr int max_level { 20 };
  int m_level{ 1 };
public:
  Player(std::string_view name)
    :Creature{ name, '@', 10, 1, 0}
  {}

  int getLevel() const { return m_level; }

  bool hasWon() const { return m_level >= max_level; }

  void levelUp()
  {
    ++m_level;
    ++m_amount_of_damage;
  }

  void attackMonster(Monster& monster)
  {
    std::string_view monster_name { monster.getName() };
    while(true)
    {
      monster.reduceHealth(m_amount_of_damage);
      std::cout << "You hit the " << monster_name
              << " for " << m_amount_of_damage << " damage\n";
      
      if(monster.isDead())
      {
        levelUp();
        addGold(monster.getGold());
        std::cout << "You killed the " << monster_name;
        std::cout << "You are now level " << m_level << '\n';
        std::cout << "You found " << m_amount_of_gold << " Gold\n";
        break;
      }

      if(isDead()){
        std::cout << "You died at level "
                  << m_level << " and with "
                  << getGold() << " Gold\n";
        std::cout << "Too bad you can’t take it with you!\n";
      }
    }
  }

  void fightMonster(Monster& monster)
  {
    std::cout << "You have encountered a " << monster.getSymbol() << '\n';
    std::cout << "(R)un or (F)ight: ";
    char dicision{};
    std::cin >> dicision;

    if(dicision == 'r'){
      int random { static_cast<int>(getRandomNumber(1, 2)) };
      
      if(random == 2){
        std::cout << "You failed to flee\n";
        monster.attackPlayer(*this);
      }
      else
      {
        std::cout << "You successfully fled\n";
      }
      return;
    }

    attackMonster(monster);
  }
};

class Monster: public Creature
{
public:
  enum class Type
  {
    dragon,
    orc,
    slime,

    max_types
  };
  static Monster getRandomMonster()
  {
    auto random { getRandomNumber(0, static_cast<int>(Type::max_types) - 1) };
    return Monster { static_cast<Type>(random) };
  }
private:
  static const Creature& getDefaultCreature(Type type)
  {
    static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
    { 
      { "dragon", 'D', 20, 4, 100 },
      { "orc", 'o', 4, 2, 25 },
      { "slime", 's', 1, 1, 10 } }
    };

    return monsterData.at(static_cast<std::size_t>(type));
  }
public:
  Monster(Type type)
    :Creature { getDefaultCreature(type) }
  {}

  void attackPlayer(Player& player)
  {
    player.reduceHealth(getDamage());
    std::cout << "The " << getName() << " hit you for"
              << getDamage() << " damage\n";
    player.fightMonster(*this);
  }
};

int main()
{
  std::cout << "Enter your name: ";
  std::string playerName;
  std::cin >> playerName;

  Player player{ playerName };
  std::cout << "Welcome, " << player.getName() << '\n';

  

  // If the player isn't dead and hasn't won yet, the game continues
  while (!player.isDead() && !player.hasWon())
  {
    Monster monster { Monster::getRandomMonster() };
    player.fightMonster(monster);
  }

  // At this point, the player is either dead or has won
  if (player.isDead())
  {
    std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  }
  else
  {
    std::cout << "You won the game with " << player.getGold() << " gold!\n";
  }
  return 0;
};