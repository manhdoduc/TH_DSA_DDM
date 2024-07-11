#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linearSearch(int arr[], int n, int value, int *comps) {
    *comps = 0;  // Khởi tạo số bước so sánh

    for (int i = 0; i < n; i++) {
        (*comps)++;
        if (arr[i] == value) {
            return;
        }
    }
}

int main() {
    srand(time(0));

    // Kích thước của mảng
    int n = 20;

    // Mảng chứa giá trị ngẫu nhiên trong khoảng [-100, 100]
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }

    // Số lần thực hiện linear search với giá trị ngẫu nhiên từ mảng trên
    int k_values[] = {10, 20, 100, 1000, 10000};

    printf("%-6s%-12s%-15s\n", "k", "Average comps", "Frequency Table");
    
    for (int i = 0; i < sizeof(k_values) / sizeof(k_values[0]); i++) {
        int total_comps = 0;

        // Thực hiện linear search k lần với giá trị ngẫu nhiên từ mảng
        for (int j = 0; j < k_values[i]; j++) {
            int value = arr[rand() % n];
            int comps;
            linearSearch(arr, n, value, &comps);
            total_comps += comps;
        }

        // Tính trung bình cộng số bước so sánh
        double avg_comps = (double)total_comps / k_values[i];

        // In kết quả
        printf("%-6d%-12.2lf", k_values[i], avg_comps);

        // Tạo bảng tần số
        int freq_table[201] = {0};  // Mảng tần số từ -100 đến 100
        for (int j = 0; j < n; j++) {
            freq_table[arr[j] + 100]++;
        }

        // In bảng tần số
        printf("%-15s", " ");
        for (int j = 0; j < 201; j++) {
            if (freq_table[j] > 0) {
                printf("%d:%d ", j - 100, freq_table[j]);
            }
        }

        printf("\n");
    }

    return 0;
}
