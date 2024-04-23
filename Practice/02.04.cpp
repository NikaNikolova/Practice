#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
    double weight;
    string continent;

public:
    Animal(string name, double weight,string continent)
        : name(name), weight(weight), continent(continent) {}

    virtual void Eat() = 0;
    virtual void Sleep() = 0;
    virtual void Move() = 0;
    virtual void MakeSound() = 0;
};

class ISwimable {
public:
    virtual void Swim() = 0;
};

class IFlyable {
public:
    virtual void Fly() = 0;
};
class Cat : public Animal {
public:
    Cat(string name, double weight, const string continent)
        : Animal(name, weight, continent) {}

    void Eat() override {
        cout << name << " eats fish" << endl;
    }

    void Sleep() override {
        cout << name << " sleeps curled up" << endl;
    }

    void Move() override {
        cout << name << " moves stealthily" << endl;
    }

    void MakeSound() override {
        cout << name << " meows" << endl;
    }
};

class Dog : public Animal, public ISwimable {
public:
    Dog(const string& _name, double _weight, const string& _continent)
        : Animal(_name, _weight, _continent) {}

    void Eat() override {
        cout << name << " eats bones" << endl;
    }

    void Sleep() override {
        cout << name << " sleeps on the floor" << endl;
    }

    void Move() override {
        cout << name << " runs around" << endl;
    }

    void MakeSound() override {
        cout << name << " barks" << endl;
    }

    void Swim() override {
        cout << name << " swims in the water" << endl;
    }
};

class Parrot : public Animal, public IFlyable {
public:
    Parrot(string name, double weight, string continent)
        : Animal(name, weight, continent) {}

    void Eat() override {
        cout << name << " eats seeds" << endl;
    }

    void Sleep() override {
        cout << name << " sleeps on a perch" << endl;
    }

    void Move() override {
        cout << name << " flies from branch to branch" << endl;
    }

    void MakeSound() override {
        cout << name << " squawks" << endl;
    }

    void Fly() override {
        cout << name << " flies in the sky" << endl;
    }
};

class Duck : public Animal, public ISwimable, public IFlyable {
public:
    Duck(string name, double weight, string continent)
        : Animal(name, weight, continent) {}

    void Eat() override {
        cout << name << " eats insects and plants" << endl;
    }

    void Sleep() override {
        cout << name << " sleeps near the water" << endl;
    }

    void Move() override {
        cout << name << " swims and flies" << endl;
    }

    void MakeSound() override {
        cout << name << " quacks" << endl;
    }

    void Swim() override {
        cout << name << " swims in the pond" << endl;
    }

    void Fly() override {
        cout << name << " flies over the water" << endl;
    }
};

int main() {
    Cat cat("Whiskers", 5.0, "Europe");
    Dog dog("Buddy", 10.0, "North America");
    Parrot parrot("Polly", 0.5, "South America");
    Duck duck("Donald", 2.0, "North America");

    cout << "-- Cat --" << endl;
    cat.Eat();
    cat.Sleep();
    cat.Move();
    cat.MakeSound();

    cout << "-- Dog --" << endl;
    dog.Eat();
    dog.Sleep();
    dog.Move();
    dog.MakeSound();
    dog.Swim();

    cout << "-- Parrot --" << endl;
    parrot.Eat();
    parrot.Sleep();
    parrot.Move();
    parrot.MakeSound();
    parrot.Fly();

    cout << "-- Duck --" << endl;
    duck.Eat();
    duck.Sleep();
    duck.Move();
    duck.MakeSound();
    duck.Swim();
    duck.Fly();

    return 0;
}