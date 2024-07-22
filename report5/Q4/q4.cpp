#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <filesystem>
#include <windows.h>  // For dynamic linking on Windows
#include "plugin.hpp"

namespace fs = std::filesystem;

typedef PluginInterface* (*CreatePluginFunc)();
typedef void (*DestroyPluginFunc)(PluginInterface*);

int main() {
    std::vector<std::unique_ptr<PluginInterface>> plugins;
    std::vector<void*> handles;

    // Scan the plugin directory
    for (const auto& entry : fs::directory_iterator(".")) {
        std::string path = entry.path().string();
        
        HMODULE hLib = LoadLibrary(path.c_str());
            if (!hLib) {
            std::cerr << "Failed to load DLL: " << GetLastError() << std::endl;
            continue;
        }
        CreatePluginFunc createPlugin = (CreatePluginFunc)GetProcAddress(hLib, "createPlugin");
        DestroyPluginFunc destroyPlugin = (DestroyPluginFunc)GetProcAddress(hLib, "destroyPlugin");
        

        // Create and store the plugin
        plugins.emplace_back(createPlugin());
    }

    // Use the plugins
    for (const auto& plugin : plugins) {
        std::cout << "Plugin Name: " << plugin->getPluginName() << std::endl;
        double result = plugin->exec(10.0, 5.0);
        std::cout << "Result: " << result << std::endl;
    }

    // Clean up
    for (size_t i = 0; i < plugins.size(); ++i) {
        DestroyPluginFunc destroyPlugin = (DestroyPluginFunc)GetProcAddress((HMODULE)handles[i], "destroyPlugin");
        destroyPlugin(plugins[i].release());
        FreeLibrary((HMODULE)handles[i]);
    }

    return 0;
}
