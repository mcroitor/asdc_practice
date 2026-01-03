/**
 * @file solution.cpp
 * @author Alexandr Voronin
 * @brief `минимум двух чисел` task solution
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cin >> a >> b;

    int minNumber = min(a, b);
    cout << minNumber << endl;

    return 0;
}