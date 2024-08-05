#include <iostream>
#include <windows.h>
#include "PluginInterface.hpp"

typedef PluginInterface* (*create_t)();
typedef void (*destroy_t)(PluginInterface*);

int main() {
    HINSTANCE handle = LoadLibrary(TEXT("bmicalc.dll"));
    if (!handle) {
        std::cerr << "ライブラリを開けません\n";
        return 1;
    }

    create_t create_plugin = (create_t) GetProcAddress(handle, "create");
    if (!create_plugin) {
        std::cerr << "シンボル 'create' を読み込めません\n";
        FreeLibrary(handle);
        return 1;
    }

    destroy_t destroy_plugin = (destroy_t) GetProcAddress(handle, "destroy");
    if (!destroy_plugin) {
        std::cerr << "シンボル 'destroy' を読み込めません\n";
        FreeLibrary(handle);
        return 1;
    }

    PluginInterface* plugin = create_plugin();

    double weight, height, desiredWeight, activityLevel;
    int dietPeriod, age;
    char gender;

    std::cout << "現在の体重 (kg) を入力してください: ";
    std::cin >> weight;
    std::cout << "身長 (m) を入力してください: ";
    std::cin >> height;
    std::cout << "目標体重 (kg) を入力してください: ";
    std::cin >> desiredWeight;
    std::cout << "ダイエット期間 (日) を入力してください: ";
    std::cin >> dietPeriod;
    std::cout << "年齢を入力してください: ";
    std::cin >> age;
    std::cout << "性別を入力してください (M または F): ";
    std::cin >> gender;
    std::cout << "活動レベルを入力してください (1.2: Sedentary, 1.375: Lightly active, 1.55: Moderately active, 1.725: Very active, 1.9: Super active): ";
    std::cin >> activityLevel;

    double bmi = plugin->calculate(weight, height);
    double desiredBMI = plugin->calculateDesiredBMI(weight, height, desiredWeight, dietPeriod, age, gender, activityLevel);
    double dailyCalories = plugin->predictDailyCalories(weight, height, age, gender, activityLevel);
    double weeklyCalorieReduction = plugin->calculateWeeklyCalorieReduction(weight, desiredWeight, dietPeriod);

    std::cout << "\n現在のBMIは: " << bmi << '\n';
    std::cout << "目標のBMIは: " << desiredBMI << '\n';
    std::cout << "予測される現在の1日の消費カロリーは: " << dailyCalories << " kcal\n";
    std::cout << "週ごとの必要なカロリー減少量は: " << weeklyCalorieReduction << " kcal\n";

    destroy_plugin(plugin);
    FreeLibrary(handle);
    return 0;
}
