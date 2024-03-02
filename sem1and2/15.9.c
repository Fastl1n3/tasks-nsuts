#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 500001
int A[N];
void qs(int* arr, int first, int last) {
    if (first < last) {
        int left = first,
            right = last,
            middle = arr[(left + right) / 2 + 1];
        do {
            while (arr[left] < middle) 
                left++;
            while (arr[right] > middle) 
                right--;
            if (left <= right) {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(arr, first, right);
        qs(arr, left, last);
    }
}
int main() {
    FILE* f1 = fopen("input.bin", "rb");
    FILE* f2 = fopen("output.bin", "wb");
    int n;
    fread(&n, sizeof(int), 1, f1);
    for (int i = 0; i < n; i++) {
        fread(&A[i], sizeof(int), 1, f1);
    }
    qs(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        fwrite(&A[i], sizeof(int), 1, f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}