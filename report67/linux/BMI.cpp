#include "BMI.hpp"

BMI::BMI(double weight, double height) : weight(weight), height(height) {}

double BMI::calculate() const {
    return weight / (height * height);
}
