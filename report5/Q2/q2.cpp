#include <iostream>
#include <windows.h>

typedef double (*AddFunc)(double, double);
typedef double (*SubFunc)(double, double);

int main() {
    // Load the DLL
    HMODULE hLib = LoadLibrary("libcalc.so");
    if (!hLib) {
        std::cerr << "Failed to load DLL: " << GetLastError() << std::endl;
        return 1;
    }

    // Get the function pointers
    AddFunc my_add = (AddFunc)GetProcAddress(hLib, "my_add");
    SubFunc my_sub = (SubFunc)GetProcAddress(hLib, "my_sub");

    if (!my_add || !my_sub) {
        std::cerr << "Failed to get function address: " << GetLastError() << std::endl;
        FreeLibrary(hLib);
        return 1;
    }

    // Use the functions
    double result_add = my_add(10.0, 5.0);
    double result_sub = my_sub(10.0, 5.0);

    std::cout << "Add: " << result_add << std::endl;
    std::cout << "Sub: " << result_sub << std::endl;

    // Unload the DLL
    FreeLibrary(hLib);

    return 0;
}
