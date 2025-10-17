#include "calculator.h"
#include <cmath>

void Calculator::Set(Number n){
    num_ = n;
}
Number Calculator::GetNumber() const{
    return num_;
}

void Calculator::Add(Number n){
    num_ += n;
}

void Calculator::Sub(Number n){
    num_ -= n;
}

void Calculator::Div(Number n){
    num_ /= n;
}
void Calculator::Mul(Number n){
    num_ *= n;
}
void Calculator::Pow(Number n){
    num_ = pow(num_, n);
}

void Calculator::Save(){
    save_ = num_;
    has_ = true;
}
void Calculator::Load(){
    num_=save_;
}
bool Calculator::HasMem() const{
    return has_;
}
std::string  Calculator::GetNumberRepr() const{
    return std::to_string(num_);
}
