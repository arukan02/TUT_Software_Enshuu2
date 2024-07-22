#include <iostream>
#include <memory>
#include <windows.h>  // For dynamic linking on Windows
#include "plugin.hpp"

typedef PluginInterface* (*CreatePluginFunc)();
typedef void (*DestroyPluginFunc)(PluginInterface*);

int main() {
    // Load the dynamic library
    HMODULE hLib = LoadLibrary("libadd.so");
        if (!hLib) {
            std::cerr << "Failed to load library: " << GetLastError() << std::endl;
            return 1;
        }
    CreatePluginFunc createPlugin = (CreatePluginFunc)GetProcAddress(hLib, "createPlugin");
    DestroyPluginFunc destroyPlugin = (DestroyPluginFunc)GetProcAddress(hLib, "destroyPlugin");

    // Create and use the plugin
    std::unique_ptr<PluginInterface> plugin(createPlugin());
    std::cout << "Plugin Name: " << plugin->getPluginName() << std::endl;
    double result = plugin->exec(10.0, 5.0);
    std::cout << "Result: " << result << std::endl;

    // Clean up
    destroyPlugin(plugin.release());
    FreeLibrary(hLib);

    return 0;
}
