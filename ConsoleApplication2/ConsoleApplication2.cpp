#include <iostream>

using namespace std;

int* allocateMemory(int size) {
    int* arr = new int[size];
    return arr;
}

void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* arr) {
    delete[] arr;
}

void appendElement(int*& arr, int& size, int element) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    delete[] arr;
    arr = newArr;
    size++;
}

void insertElementAtIndex(int*& arr, int& size, int index, int element) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    newArr[index] = element;
    for (int i = index + 1; i < size + 1; ++i) {
        newArr[i] = arr[i - 1];
    }
    delete[] arr;
    arr = newArr;
    size++;
}

void deleteElementAtIndex(int*& arr, int& size, int index) {
    int* newArr = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = index; i < size - 1; ++i) {
        newArr[i] = arr[i + 1];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

int main() {
    int* arr;
    int size = 0;

    arr = allocateMemory(5);

    initializeArray(arr, 5);

    appendElement(arr, size, 10);
    appendElement(arr, size, 20);
    appendElement(arr, size, 30);

    insertElementAtIndex(arr, size, 1, 15);

    deleteElementAtIndex(arr, size, 2);

    printArray(arr, size);

    deleteArray(arr);

    return 0;
}
