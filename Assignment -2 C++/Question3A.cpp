#include <iostream>
#include <string>
using namespace std;

class Entity {
private:
    string name;
    int health;
    int level;
    string type;

public:
    // Setters
    Entity& setName(const string& name) {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health) {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level) {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type) {
        this->type = type;
        return *this;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getLevel() const {
        return level;
    }

    string getType() const {
        return type;
    }

    void displayInfo() const {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
        cout << "-------------------" << endl;
    }
};

int main() {

    Entity player, enemy, item;

    // Method chaining
    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");

    // Display
    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

    return 0;
}