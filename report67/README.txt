Compile the dynamic library:
g++ -shared -o bmicalc.dll BMI.cpp BMICalculatorPlugin.cpp -Wl,--out-implib,bmicalc.lib

Compile the main application:
g++ -o BMICalculator main.cpp -L. -lbmicalc

Run the application:
BMICalculator.exe