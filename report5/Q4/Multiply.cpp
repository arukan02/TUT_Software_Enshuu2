#include "plugin.hpp"
#include <string>

class Multiply : public PluginInterface {
public:
    virtual std::string getPluginName() override {
        return "MultiplyPlugin";
    }

    virtual double exec(double a, double b) override {
        return a * b;
    }
};

// Export functions
extern "C" PluginInterface* createPlugin() {
    return new Multiply();
}

extern "C" void destroyPlugin(PluginInterface* plugin) {
    delete plugin;
}
