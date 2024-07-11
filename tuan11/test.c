#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void oddEven(int a[], int n) {
    // Sắp xếp mảng theo thứ tự tăng dần
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    // Di chuyển các số lẻ về phía sau
    int oddIndex = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] % 2 != 0) {
            swap(&a[i], &a[oddIndex--]);
        }
    }

    // Chèn '0' nếu có hai số liên tiếp cùng loại
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] % 2 == a[i + 1] % 2) {
            int j = i + 1;
            while (j < n - 1 && a[j] % 2 == a[j + 1] % 2) {
                ++j;
            }
            for (int k = j; k > i; --k) {
                a[k] = a[k - 1];
            }
            a[i + 1] = 0;
        }
    }

    // Hiển thị mảng sau khi biến đổi
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
    }
}

int main() {
    const int n = 6;
    int arr[] = {1, 9, 7, 5, 2, 4};
    printf("ĐẦU VÀO: ");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("ĐẦU RA: ");
    oddEven(arr, n);
    return 0;
}
