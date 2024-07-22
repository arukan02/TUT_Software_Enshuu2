#include "plugin.hpp"
#include <string>

class Add : public PluginInterface {
public:
    virtual std::string getPluginName() override {
        return "AddPlugin";
    }

    virtual double exec(double a, double b) override {
        return a + b;
    }
};

// Export function to create an instance of Add
extern "C" PluginInterface* createPlugin() {
    return new Add();
}

// Export function to destroy an instance of Add
extern "C" void destroyPlugin(PluginInterface* plugin) {
    delete plugin;
}
