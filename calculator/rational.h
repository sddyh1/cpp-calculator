#pragma once
#include <iostream>

#include <numeric>
#include <cstdlib>

class Rational {
public:
    Rational() = default;
    Rational(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
        if (denominator_ == 0) {
            std::abort();
        }
        Reduction();
    }
    Rational(int numerator) : numerator_(numerator), denominator_(1) {}
    Rational operator+() const {
        return *this;
    }


    Rational operator-() const {
        return Rational(-numerator_, denominator_);
    }

    Rational Inv() const {
        if (numerator_ == 0) {
            std::abort();
        }
        return Rational(denominator_, numerator_);
    }

    int GetNumerator()	const { return numerator_; }
    int GetDenominator() const { return denominator_; }

    bool operator==(const Rational & other) const {
        return static_cast<int64_t>(numerator_) * other.denominator_
               == static_cast<int64_t>(other.numerator_) * denominator_;
    }
    auto operator<=>(const Rational & other) const {
        return static_cast<int64_t>(numerator_) * other.denominator_
               <=> static_cast<int64_t>(other.numerator_) * denominator_;
    }
    Rational& operator+=(const Rational & r) {
        numerator_ = numerator_ * r.denominator_ + denominator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }
    Rational& operator-=(const Rational & r) {
        numerator_ = numerator_ * r.denominator_ - denominator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational & r) {
        numerator_ = numerator_ * r.numerator_;
        denominator_ = denominator_ * r.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational & r) {
        numerator_ = numerator_ * r.denominator_;
        denominator_ = denominator_ * r.numerator_;
        Reduction();
        return *this;
    }

private:
    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }
private:
    int numerator_ = 0;
    int denominator_ = 1;

};

inline std::istream& operator>>(std::istream& is, Rational& r) {
    int n, d = 1;
    char div;

    if (!(is >> n)) {
        return is;
    }
    if (!(is >> std::ws >> div)) {
        is.clear();
        r = Rational(n, d);
        return is;
    }
    if (div != '/') {
        is.unget();
        r = Rational(n, d);
        return is;
    }
    if (!(is >> std::ws >> d) || d == 0) {
        is.setstate(std::ios::failbit);
        return is;
    }

    r = Rational(n, d);
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational r) {
    if (r.GetDenominator() == 1) {
        os << r.GetNumerator();
    }
    else {
        os << r.GetNumerator() << " / " << r.GetDenominator();
    }
    return os;
}


inline Rational operator+(Rational lhs, const Rational& rhs) {
    lhs += rhs;
    return lhs;
}

inline Rational operator-(Rational lhs, const Rational& rhs) {
    lhs -= rhs;
    return lhs;
}

inline Rational operator*(Rational lhs, const Rational& rhs) {
    lhs *= rhs;
    return lhs;
}

inline Rational operator/(Rational lhs, const Rational& rhs) {
    lhs /= rhs;
    return lhs;
}
