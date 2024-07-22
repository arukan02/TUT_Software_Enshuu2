#include "plugin.hpp"
#include <string>

class Subtract : public PluginInterface {
public:
    virtual std::string getPluginName() override {
        return "SubtractPlugin";
    }

    virtual double exec(double a, double b) override {
        return a - b;
    }
};

// Export functions
extern "C" PluginInterface* createPlugin() {
    return new Subtract();
}

extern "C" void destroyPlugin(PluginInterface* plugin) {
    delete plugin;
}
