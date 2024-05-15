#include <iostream>

void splitArray(int* staticArr, int size, int*& positiveArr, int& positiveSize, int*& negativeArr, int& negativeSize, int*& zeroArr, int& zeroSize) {
    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; ++i) {
        if (staticArr[i] > 0) {
            positiveSize++;
        }
        else if (staticArr[i] < 0) {
            negativeSize++;
        }
        else {
            zeroSize++;
        }
    }

    positiveArr = new int[positiveSize];
    negativeArr = new int[negativeSize];
    zeroArr = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (staticArr[i] > 0) {
            positiveArr[posIndex++] = staticArr[i];
        }
        else if (staticArr[i] < 0) {
            negativeArr[negIndex++] = staticArr[i];
        }
        else {
            zeroArr[zeroIndex++] = staticArr[i];
        }
    }
}

int main() {
    const int size = 10;
    int staticArr[size] = { -2, 3, 0, -5, 7, 0, -10, 8, 0, -4 };
    int* positiveArr;
    int positiveSize;
    int* negativeArr;
    int negativeSize;
    int* zeroArr;
    int zeroSize;

    splitArray(staticArr, size, positiveArr, positiveSize, negativeArr, negativeSize, zeroArr, zeroSize);

    std::cout << "Positive elements: ";
    for (int i = 0; i < positiveSize; ++i) {
        std::cout << positiveArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Negative elements: ";
    for (int i = 0; i < negativeSize; ++i) {
        std::cout << negativeArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Zero elements: ";
    for (int i = 0; i < zeroSize; ++i) {
        std::cout << zeroArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] positiveArr;
    delete[] negativeArr;
    delete[] zeroArr;

    return 0;
}
