#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int* removePrimes(int* arr, int& size) {
    int* newArr = new int[size]; 

    int newSize = 0;

    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) { 
            newArr[newSize] = arr[i];
            newSize++;
        }
    }

    delete[] arr;

    size = newSize;

    return newArr;
}

int main() {
    int size = 5;
    int* arr = new int[size] {2, 3, 5, 7, 10};

    int* newArr = removePrimes(arr, size);

    cout << "New array without prime numbers: ";
    for (int i = 0; i < size; ++i) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] newArr;

    return 0;
}
