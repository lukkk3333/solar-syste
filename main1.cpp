#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Planet {
protected:
    double _mass;
    double _radius;
    double _distanceFromSun;
    string _name;
public:   
    Planet(double mass, double radius, double distanceFromSun, string name) 
        : _mass(mass), _radius(radius), _distanceFromSun(distanceFromSun), _name(name) {}

    double volume() const {
        return (4.0 / 3.0) * M_PI * pow(_radius, 3);
    }

    virtual void print() const {
        cout << "Planet Name: " << _name << endl;
        cout << "Mass: " << _mass << " kg" << endl;
        cout << "Radius: " << _radius << " km" << endl;
        cout << "Distance from Sun: " << _distanceFromSun << " km" << endl;
    }
};

class GasGiant : public Planet {
public:
    GasGiant(double mass, double radius, double distanceFromSun, string name, string gas, bool ring)
        : Planet(mass, radius, distanceFromSun, name), _gas(gas), _ring(ring) {}

    void atmosphereComposition() const {
        cout << "Atmosphere Composition: " << _gas << endl;
    }

    bool hasRings() const {
        return _ring;
    }

    void print() const override {
        Planet::print(); // Call the base class print
        cout << "Atmosphere: " << _gas << endl;
        cout << "Has Rings: " << (_ring ? "Yes" : "No") << endl << endl;
    }

protected:
    string _gas;
    bool _ring;
};

int main() {
    int userInput = 0;
    cout << "Enter a number between 1 and 8 to print a planet's details, or 0 to print all planets:" << endl;
    cout << "1. Jupiter\n2. Mercury\n3. Venus\n4. Earth\n5. Mars\n6. Saturn\n7. Uranus\n8. Neptune\nChoice: ";
    cin >> userInput;

    if (userInput == 1) {
        GasGiant jupiter(1898e24, 43441.0, 4.89e10, "Jupiter", "Helium & Hydrogen", false);
        jupiter.print();
    } else if (userInput == 2) {
        GasGiant mercury(3.302e23, 2439.7, 5.79e10, "Mercury", "Oxygen, Sodium and Hydrogen", false);
        mercury.print();
    } else if (userInput == 3) {
        GasGiant venus(4.867e24, 6051.8, 1.08e11, "Venus", "Carbon Dioxide and Nitrogen", false);
        venus.print();
    } else if (userInput == 4) {
        GasGiant earth(5.972e24, 6371.0, 1.496e11, "Earth", "Nitrogen and Oxygen", false);
        earth.print();
    } else if (userInput == 5) {
        GasGiant mars(0.64171e10, 3389.5, 2.279e8, "Mars", "Carbon Dioxide", false);
        mars.print();
    } else if (userInput == 6) {
        GasGiant saturn(568.32e24, 44423.07, 1.4e9, "Saturn", "Hydrogen & Helium", false);
        saturn.print();
    } else if (userInput == 7) {
        GasGiant uranus(8.68e25, 25362, 2.87e9, "Uranus", "Hydrogen, Helium, and Methane", true);
        uranus.print();
    } else if (userInput == 8) {
        GasGiant neptune(1.02e26, 24622.0, 4.5e9, "Neptune", "Hydrogen, Helium, and Methane", true);
        neptune.print();
    } else if (userInput == 0) {
        GasGiant jupiter(1898e24, 43441.0, 4.89e10, "Jupiter", "Helium & Hydrogen", false);
        jupiter.print();
        GasGiant mercury(3.302e23, 2439.7, 5.79e10, "Mercury", "Oxygen, Sodium and Hydrogen", false);
        mercury.print();
        GasGiant venus(4.867e24, 6051.8, 1.08e11, "Venus", "Carbon Dioxide and Nitrogen", false);
        venus.print();
        GasGiant earth(5.972e24, 6371.0, 1.496e11, "Earth", "Nitrogen and Oxygen", false);
        earth.print();
        GasGiant mars(0.64171e10, 3389.5, 2.279e8, "Mars", "Carbon Dioxide", false);
        mars.print();
        GasGiant saturn(568.32e24, 44423.07, 1.4e9, "Saturn", "Hydrogen & Helium", false);
        saturn.print();
        GasGiant uranus(8.68e25, 25362, 2.87e9, "Uranus", "Hydrogen, Helium, and Methane", true);
        uranus.print();
        GasGiant neptune(1.02e26, 24622.0, 4.5e9, "Neptune", "Hydrogen, Helium, and Methane", true);
        neptune.print();
    } else {
        cout << "Invalid input." << endl;
    }

    return 0;
}