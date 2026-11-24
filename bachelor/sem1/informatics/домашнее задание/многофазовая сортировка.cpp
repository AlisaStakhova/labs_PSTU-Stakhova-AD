#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    size_t i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i++]);
        }
        else {
            result.push_back(b[j++]);
        }
    }
    
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}

int main() {
   
    vector<vector<int>> f0 = { {10, 20}, {30, 40}, {50, 60} }; 
    vector<vector<int>> f1 = { {15, 25}, {35, 45} };         
    vector<vector<int>> f2 = {};                             

    cout << "Стартуем! На флешке 0: " << f0.size() << " серий, на флешке 1: " << f1.size() << " серий.\n\n";

    
    cout << "--- Шаг 1: Сливаем f0 и f1 в f2 ---" << endl;
    f2.push_back(merge(f0[0], f1[0]));
    f2.push_back(merge(f0[1], f1[1]));

    
    f0.erase(f0.begin(), f0.begin() + 2);
    f1.clear();

    
    cout << "--- Шаг 2: Сливаем остаток f0 и f2 в пустую f1 ---" << endl;
    f1.push_back(merge(f0[0], f2[0]));

    f0.clear();
    f2.erase(f2.begin());

    
    cout << "--- Шаг 3: Финальное слияние f1 и f2 в f0 ---" << endl;
    f0.push_back(merge(f1[0], f2[0]));

    f1.clear();
    f2.clear();

    
    cout << "\nГотово! Результат в f0: ";
    for (int num : f0[0]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
