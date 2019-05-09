#include <iostream>
#include <sstream>
#include <cmath>

class Rectangle : public Figure {
    double a, b;
public:
    Rectangle(): a(0), b(0) {}
    virtual double get_square() const {
        return a * b;
    }
    static Rectangle* make(const std::string &tmp_str) {
        Rectangle *tmp_obj = new Rectangle();
        std::stringstream ss(tmp_str);
        ss >> tmp_obj->a >> tmp_obj->b;
        return tmp_obj;
    }
};

class Square : public Figure {
    double a;
public:
    Square(): a(0) {}
    virtual double get_square() const {
        return a * a;
    }
    static Square* make(const std::string &tmp_str) {
        Square *tmp_obj = new Square();
        tmp_obj->a = std::stod(tmp_str);
        return tmp_obj;
    }
};

class Circle : public Figure {
    double r;
public:
    Circle(): r(0) {}
    virtual double get_square() const {
        return M_PI * r * r;
    }
    static Circle* make(const std::string &tmp_str) {
        Circle *tmp_obj = new Circle();
        tmp_obj->r= std::stod(tmp_str);
        return tmp_obj;
    }
};