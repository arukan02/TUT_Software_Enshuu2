#include "BMI.hpp"

BMI::BMI(double weight, double height) : weight(weight), height(height) {}

double BMI::calculate() const {
    return weight / (height * height);
}

BMICalculator::BMICalculator(double weight, double height, double desiredWeight, int dietPeriod, int age, char gender, double activityLevel)
    : weight(weight), height(height), desiredWeight(desiredWeight), dietPeriod(dietPeriod), age(age), gender(gender), activityLevel(activityLevel) {}

double BMICalculator::currentBMI() const {
    BMI bmi(weight, height);
    return bmi.calculate();
}

double BMICalculator::desiredBMI() const {
    BMI bmi(desiredWeight, height);
    return bmi.calculate();
}

double BMICalculator::dailyCalorieConsumption() const {
    double bmr;
    if (gender == 'M') {
        bmr = 10 * weight + 6.25 * height * 100 - 5 * age + 5;
    } else if (gender == 'F') {
        bmr = 10 * weight + 6.25 * height * 100 - 5 * age - 161;
    } else {
        // Handle invalid gender input
        return 0;
    }
    return bmr * activityLevel; // Activity level factor
}

double BMICalculator::weeklyCalorieReduction() const {
    double totalCaloriesToLose = (weight - desiredWeight) * 7700; // 1kgの体重減少に必要なカロリーは7700 kcal
    return totalCaloriesToLose / (dietPeriod / 7.0); // 週あたりのカロリー減少量
}
