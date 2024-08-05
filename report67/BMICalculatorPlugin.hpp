#ifndef BMI_CALCULATOR_PLUGIN_HPP
#define BMI_CALCULATOR_PLUGIN_HPP

#include "PluginInterface.hpp"
#include "BMI.hpp"

class BMICalculatorPlugin : public PluginInterface {
public:
    double calculate(double weight, double height) override;
    double calculateDesiredBMI(double weight, double height, double desiredWeight, int dietPeriod, int age, char gender, double activityLevel) override;
    double predictDailyCalories(double weight, double height, int age, char gender, double activityLevel) override;
    double calculateWeeklyCalorieReduction(double weight, double desiredWeight, int dietPeriod) override;

private:
    BMI* bmiInstance;
};

extern "C" __declspec(dllexport) PluginInterface* create();
extern "C" __declspec(dllexport) void destroy(PluginInterface* plugin);

#endif // BMI_CALCULATOR_PLUGIN_HPP
