#include <iostream>
using namespace std;

class Shape {
private:
    string color;
    float area;

public:
    void setColor(string c) { color = c; }
    string getColor() { return color; }

    virtual void calculateArea() = 0;  
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) { radius = r; }
    void calculateArea() {
        cout << "Area of Circle = " << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) { length = l; width = w; }

    void calculateArea() {
        cout << "Area of Rectangle = " << length * width << endl;
    }
};

int main() {
    Circle c(5);
    Rectangle r(6, 4);

    c.calculateArea();
    r.calculateArea();
    return 0;
}