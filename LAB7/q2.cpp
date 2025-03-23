#include <iostream>
using namespace std;

// Base class Shape
class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {}
    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
    double radius;
public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    void draw() const override {
        cout << "Drawing a " << color << " Circle with radius " << radius << "\n";
    }
    double calculateArea() const override {
        return 3.14159 * radius * radius;  // Approximate pi
    }
    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}
    void draw() const override {
        cout << "Drawing a " << color << " Rectangle with width " << width << " and height " << height << "\n";
    }
    double calculateArea() const override {
        return width * height;
    }
    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

// Derived class Triangle
class Triangle : public Shape {
    double base, height;
public:
    Triangle(string c, double b, double h) : Shape(c), base(b), height(h) {}
    void draw() const override {
        cout << "Drawing a " << color << " Triangle with base " << base << " and height " << height << "\n";
    }
    double calculateArea() const override {
        return 0.5 * base * height;
    }
    double calculatePerimeter() const override {
        return base + 2 * height; 
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle("Red", 5);
    shapes[1] = new Rectangle("Blue", 4, 6);
    shapes[2] = new Triangle("Green", 3, 4);

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << "\n";
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << "\n";
        delete shapes[i];
    }
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
    delete []shapes;
    return 0;
}
