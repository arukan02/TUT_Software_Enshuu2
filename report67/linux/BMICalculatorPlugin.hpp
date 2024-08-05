#ifndef BMI_CALCULATOR_PLUGIN_HPP
#define BMI_CALCULATOR_PLUGIN_HPP

#include "PluginInterface.hpp"
#include "BMI.hpp"

class BMICalculatorPlugin : public PluginInterface {
public:
    double calculate(double weight, double height) override;

private:
    BMI* bmiInstance;
};

extern "C" PluginInterface* create();
extern "C" void destroy(PluginInterface* plugin);

#endif // BMI_CALCULATOR_PLUGIN_HPP
