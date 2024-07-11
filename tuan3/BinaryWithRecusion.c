#include <stdio.h>

// Hàm đệ quy để tìm kiếm nhị phân
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // Nếu key nằm ở giữa mảng
        if (arr[mid] == key) {
            return mid;
        }

        // Nếu key nhỏ hơn phần tử giữa, tìm kiếm ở nửa trái
        if (key < arr[mid]) {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }

        // Nếu key lớn hơn phần tử giữa, tìm kiếm ở nửa phải
        return binarySearchRecursive(arr, mid + 1, high, key);
    }

    // Nếu key không tồn tại trong mảng
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binarySearchRecursive(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element %d is present at index %d\n", key, result);
    } else {
        printf("Element %d is not present in the array\n", key);
    }

    return 0;
}
