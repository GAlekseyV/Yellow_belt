//
// Created by GAlekseyV on 21.09.2018.
//
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

class Figure{
public:
    Figure(const string& name = "figure")
    : name_(name){}
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

    const string name_;
private:

};

class Triangle : public Figure{
public:
    Triangle(double a, double b, double c)
    : Figure("TRIANGLE"), a_(a), b_(b), c_(c){}

    string Name() override {
        return name_;
    }

    double Perimeter() override {
        return a_ + b_ + c_;
    }

    double Area() override {
        double p = Perimeter() / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    double a_, b_, c_;
};

class Rect: public Figure{
public:
    Rect(double width, double height)
    : Figure("RECT"),width_(width), height_(height){}

    string Name() override {
        return name_;
    }

    double Perimeter()override{
        return 2 * (width_ + height_);
    }

    double Area() override {
        return width_ * height_;
    }

private:
    double width_, height_;
};

class Circle : public Figure{
public:
    Circle(double r)
    : Figure("CIRCLE"), r_(r){}

    string Name() override {
        return name_;
    }

    double Perimeter() override {
        return 2 * 3.14 * r_;
    }

    double Area() override {
        return 3.14 * r_ * r_;
    }

private:
    double r_;
};

shared_ptr<Figure> CreateFigure(istream& is){
    string type;
    is >> type;
    if(type == "TRIANGLE"){
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }else if(type == "RECT"){
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    }else if(type == "CIRCLE"){
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
    return {};
}

//int main() {
//    vector<shared_ptr<Figure>> figures;
//    for (string line; getline(cin, line); ) {
//        istringstream is(line);
//
//        string command;
//        is >> command;
//        if (command == "ADD") {
//            figures.push_back(CreateFigure(is));
//        } else if (command == "PRINT") {
//            for (const auto& current_figure : figures) {
//                cout << fixed << setprecision(3)
//                     << current_figure->Name() << " "
//                     << current_figure->Perimeter() << " "
//                     << current_figure->Area() << endl;
//            }
//        }
//    }
//    return 0;
//}