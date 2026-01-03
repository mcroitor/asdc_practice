/**
 * @file solution.cpp
 * @author Alexandr Voronin
 * @brief `максимальный элемент` task solution
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

    int *A = new int[N];
    

    for (int i = 0; i < N; i++) {
        cin >> A[i];

    }
    int Max = A[0];
    for (int i = 0; i < N; i++) {
        if (Max < A[i]) {
            Max = A[i];
        }
    }

    cout << Max << endl;

    return 0;
}