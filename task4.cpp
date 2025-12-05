#include <iostream>
using namespace std;

class Shape {
public:
    virtual void display(){ }
};

class Circle : public Shape {
public:
    void display(){
        cout<<"This is Circle"<<endl;
    }
};

class Rectangle : public Shape {
public:
    void display(){
        cout<<"This is Rectangle"<<endl;
    }
};

int main(){
    Shape* s[2];
    s[0] = new Circle();
    s[1] = new Rectangle();

    for(int i=0 ; i<2 ; i++)
        s[i]->display();
}