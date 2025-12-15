
#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template<typename Number>
class Calculator{
public:
    std::optional<Error> Add(Number n){
        num_ += n;
        return std::nullopt;
    }
    std::optional<Error> Sub(Number n){
        num_ -= n;
        return std::nullopt;
    }
    std::optional<Error> Div(Number n){
        if constexpr(std::is_integral_v<Number> || std::is_same_v<Number, Rational>){
            if(n == 0){
                return "Division by zero";
            }
        }
        num_ /= n;
        return std::nullopt;
    }
    std::optional<Error> Mul(Number n){
        num_ *= n;
        return std::nullopt;
    }
    std::optional<Error> Pow(Number n){
        if constexpr(std::is_integral_v<Number>){
            if(n == 0 && num_ == 0){
                    return "Zero power to zero";
            }
            if(n < 0){
                return "Integer negative power";
            }
            num_ = IntegerPow(num_, n);
            return std::nullopt;
        }

        if constexpr(std::is_same_v<Number,Rational>){
            if(n == 0 && num_ == 0){
                return "Zero power to zero";
            }
            if(n.GetDenominator() != 1){
                return "Fractional power is not supported";
            }
            num_ = ::Pow(num_, n);
            return std::nullopt;
        }
        else{
            num_ = std::pow(num_, n);
            return std::nullopt;
        }
    }

    void Set(Number n){
        num_ = n;
    }

    Number GetNumber()const{
        return num_;
    }

    void Negate(Number n) {
        num_ = -num_;
    }

    void Save() {
        mem_ = num_;
    }

    void Load() {
        if (mem_.has_value()) {
            num_ = mem_.value();
        }
    }

    void ClearMemory() {
        mem_ = std::nullopt;
    }

    bool GetHasMem() const {
        return mem_.has_value();
    }


private:
    Number num_ = 0;
    std::optional<Number> mem_;
};
