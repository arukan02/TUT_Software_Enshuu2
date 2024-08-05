#include "BMICalculatorPlugin.hpp"

double BMICalculatorPlugin::calculate(double weight, double height) {
    bmiInstance = new BMI(weight, height);
    double result = bmiInstance->calculate();
    delete bmiInstance;
    return result;
}

extern "C" PluginInterface* create() {
    return new BMICalculatorPlugin();
}

extern "C" void destroy(PluginInterface* plugin) {
    delete plugin;
}
