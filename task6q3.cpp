#include <iostream>
using namespace std;

class Position {
protected:
    float x, y, z;
public:
    Position(float x, float y, float z) : x(x), y(y), z(z) {}
    void displayPosition() {
        cout << "Position -> X: " << x
             << " | Y: " << y
             << " | Z: " << z << endl;
    }
};

class Health {
protected:
    int health;
public:
    Health(int h) : health(h) {}
    void displayHealth() {
        cout << "Health: " << health << " HP" << endl;
    }
};


class Character : public Position, public Health {
    string name;
public:
    Character(string n, float x, float y, float z, int h)
        : Position(x, y, z), Health(h), name(n) {}

    void display() {
        cout << "=== Character: " << name << " ===" << endl;
        displayPosition();
        displayHealth();
    }
};

int main() {
    Character hero("Aragorn", 10.5, 3.2, 7.8, 250);
    hero.display();
    return 0;
}
