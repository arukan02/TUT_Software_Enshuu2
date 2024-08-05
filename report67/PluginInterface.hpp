#ifndef PLUGIN_INTERFACE_HPP
#define PLUGIN_INTERFACE_HPP

class PluginInterface {
public:
    virtual ~PluginInterface() = default;
    virtual double calculate(double weight, double height) = 0;
    virtual double calculateDesiredBMI(double weight, double height, double desiredWeight, int dietPeriod, int age, char gender, double activityLevel) = 0;
    virtual double predictDailyCalories(double weight, double height, int age, char gender, double activityLevel) = 0;
    virtual double calculateWeeklyCalorieReduction(double weight, double desiredWeight, int dietPeriod) = 0;
};

extern "C" __declspec(dllexport) PluginInterface* create();
extern "C" __declspec(dllexport) void destroy(PluginInterface*);

#endif // PLUGIN_INTERFACE_HPP
