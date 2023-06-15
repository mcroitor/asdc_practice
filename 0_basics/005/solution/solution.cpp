/**
 * @file solution.cpp
 * @author Alexandr Voronin
 * @brief `proxy 2` task solution
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;


int main() {
    int N;
    cin >> N;

    int A[N];
    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];

    }
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    cout << sum << endl;

    return 0;
}