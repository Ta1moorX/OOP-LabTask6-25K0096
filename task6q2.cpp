#include <iostream>
#include <string>
using namespace std;


class Character {
protected:
    int health, damage;
public:
    Character(int h, int d) : health(h), damage(d) {}
    void display() {
        cout << "Health: " << health << " | Damage: " << damage << endl;
    }
};


class Enemy : public Character {
    string type;
public:
    Enemy(int h, int d, string t) : Character(h, d), type(t) {}
    void display() {
        cout << "[Enemy - " << type << "] ";
        Character::display();
    }
};

class Player : public Character {
    string name;
public:
    Player(int h, int d, string n) : Character(h, d), name(n) {}
    void display() {
        cout << "[Player - " << name << "] ";
        Character::display();
    }
};

class Wizard : public Player {
    int magicPower;
    string spells;
public:
    Wizard(int h, int d, string n, int mp, string s)
        : Player(h, d, n), magicPower(mp), spells(s) {}

    void display() {
        Player::display();
        cout << "  Magic Power: " << magicPower
             << " | Spells: "    << spells << endl;
    }
};

int main() {
    Wizard w(200, 85, "Gandalf", 150, "Fireball, Teleport, Freeze");
    cout << "=== Wizard Stats ===" << endl;
    w.display();
    return 0;
}
