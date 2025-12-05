#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() = 0;
    virtual void move() = 0;
};

class Dog : public Animal {
public:
    void sound() { cout << "DOG SOUND IS :bhau bhau" << endl; }
    void move() { cout << "DOG MOVEMENT IS :scrad" << endl; }
};

class Bird : public Animal {
public:
    void sound() { cout << "BIRD SOUND IS :chi chi" << endl; }
    void move() { cout <<  "BIRD MOVEMENT IS :clap" << endl; }
};

int main() {
    Animal* a[2];
    a[0] = new Dog();
    a[1] = new Bird();

    for (int i = 0; i < 2; i++) {
        a[i]->sound();
        a[i]->move();
    }

    return 0;
}