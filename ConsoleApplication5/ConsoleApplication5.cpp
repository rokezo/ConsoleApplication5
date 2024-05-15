#include <iostream>

int main() {
    int m, n;
    std::cout << "Enter the size of the first array: ";
    std::cin >> m;
    std::cout << "Enter the size of the second array: ";
    std::cin >> n;

    int* a = new int[m];
    int* b = new int[n];
    int* c = new int[m]; 
    int k = 0; 

    std::cout << "Enter the elements of the first array:\n";
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    std::cout << "Enter the elements of the second array:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }


    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (k == 0 || a[i] != c[k - 1]) {
                c[k] = a[i];
                k++;
            }
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    while (i < m) {
        if (k == 0 || a[i] != c[k - 1]) {
            c[k] = a[i];
            k++;
        }
        i++;
    }

    for (int i = 0; i < k; i++) {
        std::cout << c[i] << " ";
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}