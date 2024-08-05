#ifndef PLUGIN_INTERFACE_HPP
#define PLUGIN_INTERFACE_HPP

class PluginInterface {
public:
    virtual ~PluginInterface() = default;
    virtual double calculate(double weight, double height) = 0;
};

extern "C" PluginInterface* create();
extern "C" void destroy(PluginInterface*);

#endif // PLUGIN_INTERFACE_HPP
