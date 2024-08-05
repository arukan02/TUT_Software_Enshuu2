#include <iostream>
#include <dlfcn.h>
#include "PluginInterface.hpp"

int main() {
    void* handle = dlopen("./libbmicalc.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }

    // Load the symbols
    create_t* create_plugin = (create_t*) dlsym(handle, "create");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    destroy_t* destroy_plugin = (destroy_t*) dlsym(handle, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        dlclose(handle);
        return 1;
    }

    // Create an instance of the plugin
    PluginInterface* plugin = create_plugin();

    double weight, height;
    std::cout << "Enter weight (kg): ";
    std::cin >> weight;
    std::cout << "Enter height (m): ";
    std::cin >> height;

    double bmi = plugin->calculate(weight, height);
    std::cout << "Your BMI is: " << bmi << '\n';

    // Destroy the plugin instance
    destroy_plugin(plugin);

    // Close the library
    dlclose(handle);
    return 0;
}
