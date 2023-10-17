#pragma once
#include <iostream>

class Meter {
    friend std::ostream& operator<<(std::ostream& ostrm, const Meter& a) {
        ostrm << a.getValue() << " m";
        return ostrm;
    }

public:
    Meter(double val) : _val(val) {}

    double getValue() const {
        return _val;
    }

    Meter operator+(const Meter& other) const {
        return Meter(_val + other._val);
    }

    Meter operator-(const Meter& other) const {
        return Meter(_val - other._val);
    }

    Meter operator*(const Meter& other) const {
        return Meter(_val * other._val);
    }

    Meter operator/(const Meter& other) const {
        return Meter(_val / other._val);
    }

private:
    double _val;
};

class Meter2 {
    friend std::ostream& operator<<(std::ostream& ostrm, const Meter2& a) {
        ostrm << a.getValue() << " m^2";
        return ostrm;
    }

public:
    Meter2(double val) : _val(val) {};
    Meter2(Meter other){
        _val = other.getValue();
    }

    double getValue() const {
        return _val;
    }

    Meter2 operator+(const Meter2& other) const {
        return Meter2(_val + other._val);
    }

    Meter2 operator-(const Meter2& other) const {
        return Meter2(_val - other._val);
    }

    Meter2 operator*(const Meter2& other) const {
        return Meter2(_val * other._val);
    }

    Meter2 operator/(const Meter2& other) const {
        return Meter2(_val / other._val);
    }

    void operator=(const Meter2& a){
        _val = a.getValue();
    }

private:
    double _val;
};

class Meter3 {
    friend std::ostream& operator<<(std::ostream& ostrm, const Meter3& a) {
        ostrm << a.getValue() << " m^3";
        return ostrm;
    }

public:
    Meter3(double val) : _val(val) {};
    Meter3(Meter other){
        _val = other.getValue();
    }

    double getValue() const {
        return _val;
    }

    Meter3 operator-(const Meter3& other) const {
        return Meter3(_val - other._val);
    }

    Meter3 operator*(const Meter3& other) const {
        return Meter3(_val * other._val);
    }

    Meter3 operator/(const Meter3& other) const {
        return Meter3(_val / other._val);
    }

    Meter2 operator/(const Meter& other) const {
        return Meter2(_val / other.getValue());
    }

    Meter operator/(const Meter2& other)const{
        return Meter(_val/other.getValue());
    }

    void operator=(const Meter& a){
        _val = a.getValue();
    }

private:
    double _val;
};