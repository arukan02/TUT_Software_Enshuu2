#include "plugin.hpp"
#include <string>

class Divide : public PluginInterface {
public:
    virtual std::string getPluginName() override {
        return "DividePlugin";
    }

    virtual double exec(double a, double b) override {
        return a / b;
    }
};

// Export functions
extern "C" PluginInterface* createPlugin() {
    return new Divide();
}

extern "C" void destroyPlugin(PluginInterface* plugin) {
    delete plugin;
}
