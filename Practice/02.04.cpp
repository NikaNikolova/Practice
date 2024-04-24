#include <iostream>
#include <string>

using namespace std;

// Abstract base class for all types of creatures
class Creature {
protected:
    string _name;
    double _mass;
    string _origin;

public:
    Creature(string name, double mass, string origin)
        : _name(name), _mass(mass), _origin(origin) {}

    virtual void feed() = 0;
    virtual void sleep() = 0;
    virtual void locomote() = 0;
    virtual void soundOff() = 0;
};

// Interfaces for swimming and flying behaviors
class SwimBehavior {
public:
    virtual void swim() = 0;
};

class FlyBehavior {
public:
    virtual void fly() = 0;
};

// Specific animal classes
class Felis : public Creature {
public:
    Felis(string name, double mass, string origin)
        : Creature(name, mass, origin) {}

    void feed() override {
        cout << _name << " munches on some delicious meat." << endl;
    }

    void sleep() override {
        cout << _name << " curls up in a cozy corner." << endl;
    }

    void locomote() override {
        cout << _name << " stealthily sneaks around." << endl;
    }

    void soundOff() override {
        cout << _name << " meows." << endl;
    }
};

class Canis : public Creature, public SwimBehavior {
public:
    Canis(string name, double mass, string origin)
        : Creature(name, mass, origin) {}

    void feed() override {
        cout << _name << " devours its meal." << endl;
    }

    void sleep() override {
        cout << _name << " lies down with a heavy sigh." << endl;
    }

    void locomote() override {
        cout << _name << " bounds joyfully." << endl;
    }

    void soundOff() override {
        cout << _name << " woofs loudly." << endl;
    }

    void swim() override {
        cout << _name << " splashes in the water." << endl;
    }
};

class Psittaciformes : public Creature, public FlyBehavior {
public:
    Psittaciformes(string name, double mass, string origin)
        : Creature(name, mass, origin) {}

    void feed() override {
        cout << _name << " nibbles on seeds and nuts." << endl;
    }

    void sleep() override {
        cout << _name << " perches quietly." << endl;
    }

    void locomote() override {
        cout << _name << " flutters from branch to branch." << endl;
    }

    void soundOff() override {
        cout << _name << " squawks intermittently." << endl;
    }

    void fly() override {
        cout << _name << " soars through the air." << endl;
    }
};

class Anatidae : public Creature, public SwimBehavior, public FlyBehavior {
public:
    Anatidae(string name, double mass, string origin)
        : Creature(name, mass, origin) {}

    void feed() override {
        cout << _name << " forages for food in the water." << endl;
    }

    void sleep() override {
        cout << _name << " rests near the edge of the lake." << endl;
    }

    void locomote() override {
        cout << _name << " waddles along the bank." << endl;
    }

    void soundOff() override {
        cout << _name << " quacks repeatedly." << endl;
    }

    void swim() override {
        cout << _name << " paddles around." << endl;
    }

    void fly() override {
        cout << _name << " takes off from the water surface." << endl;
    }
};

// Main function to demonstrate polymorphism
int main() {
    Creature* animals[] = {
        new Felis("Tabby", 4.5, "Global"),
        new Canis("Rover", 25.0, "Global"),
        new Psittaciformes("Coco", 1.0, "South America"),
        new Anatidae("Donald", 3.2, "Global")
    };

    for (auto animal : animals) {
        animal->feed();
        animal->sleep();
        animal->locomote();
        animal->soundOff();
        if (auto swimmable = dynamic_cast<SwimBehavior*>(animal))
            swimmable->swim();
        if (auto flyable = dynamic_cast<FlyBehavior*>(animal))
            flyable->fly();
    }

    for (auto animal : animals) delete animal;
    return 0;
}
