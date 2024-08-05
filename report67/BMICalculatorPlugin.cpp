#include "BMICalculatorPlugin.hpp"

double BMICalculatorPlugin::calculate(double weight, double height) {
    bmiInstance = new BMI(weight, height);
    double result = bmiInstance->calculate();
    delete bmiInstance;
    return result;
}

double BMICalculatorPlugin::calculateDesiredBMI(double weight, double height, double desiredWeight, int dietPeriod, int age, char gender, double activityLevel) {
    BMICalculator calculator(weight, height, desiredWeight, dietPeriod, age, gender, activityLevel);
    return calculator.desiredBMI();
}

double BMICalculatorPlugin::predictDailyCalories(double weight, double height, int age, char gender, double activityLevel) {
    BMICalculator calculator(weight, height, 0, 0, age, gender, activityLevel); // desiredWeightとdietPeriodはここでは不要
    return calculator.dailyCalorieConsumption();
}

double BMICalculatorPlugin::calculateWeeklyCalorieReduction(double weight, double desiredWeight, int dietPeriod) {
    BMICalculator calculator(weight, 0, desiredWeight, dietPeriod, 0, ' ', 0); // height, age, gender, activityLevelはここでは不要
    return calculator.weeklyCalorieReduction();
}

extern "C" __declspec(dllexport) PluginInterface* create() {
    return new BMICalculatorPlugin();
}

extern "C" __declspec(dllexport) void destroy(PluginInterface* plugin) {
    delete plugin;
}
