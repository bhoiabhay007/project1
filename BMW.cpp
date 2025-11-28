#include <iostream>
using namespace std;

class Abhay {
private:
    string brand;
    string model;
    int year;

public:
    Abhay(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    void display() {
        cout << "Brand: " << brand
             << ", Model: " << model
             << ", Year: " << year << endl;
    }
};

class Car : public Abhay {
private:
    int doors;

public:
    Car(string b, string m, int y, int d)
        : Abhay(b, m, y) {
        doors = d;
    }

    void display() {
        Abhay::display();
        cout << "Doors: " << doors << endl;
    }
};

class ElectricCar : public Car {
private:
    int battery;

public:
    ElectricCar(string b, string m, int y, int d, int bc)
        : Car(b, m, y, d) {
        battery = bc;
    }

    void display() {
        Car::display();
        cout << "Battery: " << battery << " kWh" << endl;
    }
};

class Bike : public Abhay {
private:
    int engineCC;

public:
    Bike(string b, string m, int y, int cc)
        : Abhay(b, m, y) {
        engineCC = cc;
    }

    void display() {
        Abhay::display();
        cout << "Engine CC: " << engineCC << endl;
    }
};

class TwoWheeler : public Bike {
public:
    TwoWheeler(string b, string m, int y, int cc, string p)
        : Bike(b, m, y, cc) {}

    void display() {
        Bike::display();
    }
};

int main() {
    string brand, model, policy;
    int year, doors, battery, cc;

    cout << "Enter Car Brand: ";
    cin >> brand;
    cout << "Enter Car Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Number of Doors: ";
    cin >> doors;

    Car c(brand, model, year, doors);

    cout << "\nEnter Electric Car Brand: ";
    cin >> brand;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Doors: ";
    cin >> doors;
    cout << "Enter Battery Capacity: ";
    cin >> battery;

    ElectricCar e(brand, model, year, doors, battery);

    cout << "\nEnter Bike Brand: ";
    cin >> brand;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Engine CC: ";
    cin >> cc;

    Bike b(brand, model, year, cc);

    cout << "\nEnter Two Wheeler Brand: ";
    cin >> brand;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Engine CC: ";
    cin >> cc;
    cout << "Enter Policy Number: ";
    cin >> policy;

    TwoWheeler tw(brand, model, year, cc, policy);

    cout << "\n--- Car Details ---\n";
    c.display();

    cout << "\n--- Electric Car Details ---\n";
    e.display();

    cout << "\n--- Bike Details ---\n";
    b.display();

    return 0;
}