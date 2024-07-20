#include <iostream>

int &get(int *arr, int idx) { 
    return arr[idx]; 
}

int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;  // Assign the value of i to ia[i]

    // Optional: Print the array to verify the values
    for (int i = 0; i != 10; ++i)
        std::cout << ia[i] << " ";
    std::cout << std::endl;

    return 0;
}