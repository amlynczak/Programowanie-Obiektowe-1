#pragma once

#include <iostream>
#include <type_traits>

template<typename T>
class Length {
    friend std::ostream& operator<<(std::ostream& ostrm, const Length& a) {
        ostrm << a._val;
        return ostrm;
    }

public:
    Length(T val) : _val(val) {}

    template<typename U>
    auto operator+(const Length<U>& other) const {
        using CommonType = std::common_type_t<T, U>;
        return Length<CommonType>(_val + static_cast<CommonType>(other.getVal()));
    }

    template<typename U>
    auto operator*(const Length<U>& other) const {
        using CommonType = std::common_type_t<T, U>;
        return Length<CommonType>(_val * static_cast<CommonType>(other.getVal()));
    }

    T getVal() const {
        return _val;
    }

private:
    T _val;
};

template<typename T>
class Area {
    friend std::ostream& operator<<(std::ostream& ostrm, const Area& a) {
        ostrm << a._val;
        return ostrm;
    }

public:
    Area(T val) : _val(val) {}

    template<typename U>
    auto operator+(const Area<U>& other) const {
        using CommonType = std::common_type_t<T, U>;
        return Area<CommonType>(_val + static_cast<CommonType>(other.getVal()));
    }

    template<typename U>
    auto operator*(const Length<U>& other) const {
        using CommonType = std::common_type_t<T, U>;
        return Area<CommonType>(_val * static_cast<CommonType>(other.getVal()));
    }

    T getVal() const {
        return _val;
    }

private:
    T _val;
};

template<typename T>
class Time {
    friend std::ostream& operator<<(std::ostream& ostrm, const Time& t) {
        ostrm << t._val;
        return ostrm;
    }

public:
    Time(T val) : _val(val) {}

    Time operator+(const Time& other) const {
        return Time(_val + other._val);
    }

    Time operator-(const Time& other) const {
        return Time(_val - other._val);
    }

    template<typename U>
    T operator/(const U& scalar) const {
        return _val / scalar;
    }

    T getVal() const {
        return _val;
    }

private:
    T _val;
};

template<typename T>
class Velocity {
    friend std::ostream& operator<<(std::ostream& ostrm, const Velocity& v) {
        ostrm << v._val;
        return ostrm;
    }

public:
    Velocity(T val) : _val(val) {}

    Velocity operator+(const Velocity& other) const {
        return Velocity(_val + other._val);
    }

    Velocity operator-(const Velocity& other) const {
        return Velocity(_val - other._val);
    }

    template<typename U>
    Velocity operator/(const U& scalar) const {
        return Velocity(_val / scalar);
    }

    template<typename U>
    Time<T> operator/(const Velocity<U>& other) const {
        return Time<T>(_val / other.getVal());
    }

    T getVal() const {
        return _val;
    }

private:
    T _val;
};

template<typename T>
class Acceleration {
    friend std::ostream& operator<<(std::ostream& ostrm, const Acceleration& a) {
        ostrm << a._val;
        return ostrm;
    }

public:
    Acceleration(T val) : _val(val) {}

    Acceleration operator+(const Acceleration& other) const {
        return Acceleration(_val + other._val);
    }

    Acceleration operator-(const Acceleration& other) const {
        return Acceleration(_val - other._val);
    }

    template<typename U>
    Acceleration operator/(const U& scalar) const {
        return Acceleration(_val / scalar);
    }

    template<typename U>
    Velocity<T> operator*(const U& scalar) const {
        return Velocity<T>(_val * scalar);
    }

    template<typename U>
    T operator/(const Velocity<U>& other) const {
        return _val / other.getVal();
    }

    T getVal() const {
        return _val;
    }

private:
    T _val;
};

template<typename T>
class Weight {
    friend std::ostream& operator<<(std::ostream& ostrm, const Weight& w) {
        ostrm << w._val;
        return ostrm;
    }

public:
    Weight(T val) : _val(val) {}

    Weight operator+(const Weight& other) const {
        return Weight(_val + other._val);
    }

    template<typename U>
    Weight operator*(const U& scalar) const {
        return Weight(_val * scalar);
    }

    template<typename U>
    Area<T> operator/(const U& scalar) const {
        return Area<T>(_val / scalar);
    }

    template<typename U>
    Acceleration<T> operator/(const Area<U>& other) const {
        return Acceleration<T>(_val / other.getVal());
    }

    T getVal() const {
        return _val;
    }

private:
    T _val;
};


template<typename T> using Meter = Length<T>;

template<typename T> using SquareMeter = Area<T>;

template<typename T> using Second = Time<T>;

template<typename T> using MeterPerSecond = Velocity<T>;

template<typename T> using MeterPerSecondSquared = Acceleration<T>;

template<typename T> using Kilogram = Weight<T>;

template<typename T, typename U>
auto operator+(const Length<T>& lhs, const Length<U>& rhs) {
    using CommonType = std::common_type_t<T, U>;
    return Length<CommonType>(lhs.getVal() + static_cast<CommonType>(rhs.getVal()));
}

template<typename T, typename U>
auto operator+(const Area<T>& lhs, const Area<U>& rhs) {
    using CommonType = std::common_type_t<T, U>;
    return Area<CommonType>(lhs.getVal() + static_cast<CommonType>(rhs.getVal()));
}
