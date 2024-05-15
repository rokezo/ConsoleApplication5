#include <iostream>

int main() {
    int m, n;
    std::cout << "Enter the size of the first array: ";
    std::cin >> m;
    std::cout << "Enter the size of the second array: ";
    std::cin >> n;

    int a[m];
    int b[n];
    int c[m + n];
    int k = 0;

    std::cout << "Enter the elements of the first array:\n";
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    std::cout << "Enter the elements of the second array:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    // sort a and b
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

    int i = 0, j = 0, l = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (l == 0 || a[i] != c[l - 1]) {
                c[l] = a[i];
                l++;
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
        if (l == 0 || a[i] != c[l - 1]) {
            c[l] = a[i];
            l++;
        }
        i++;
    }

    for (int i = 0; i < l; i++) {
        std::cout << c[i] << " ";
    }

    return 0;
}