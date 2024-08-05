#ifndef BMI_HPP
#define BMI_HPP

class BMI {
public:
    BMI(double weight, double height);
    double calculate() const;

private:
    double weight;
    double height;
};

class BMICalculator {
public:
    BMICalculator(double weight, double height, double desiredWeight, int dietPeriod, int age, char gender, double activityLevel);
    double currentBMI() const;
    double desiredBMI() const;
    double dailyCalorieConsumption() const;
    double weeklyCalorieReduction() const;

private:
    double weight;
    double height;
    double desiredWeight;
    int dietPeriod;
    int age;
    char gender;
    double activityLevel; // Activity level factor
};

#endif // BMI_HPP
