#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000001
int A[N];
void qs(int* arr, int first, int last) {
    if (first < last) {
        int left = first, 
            right = last, 
            middle = arr[(left + right) / 2];
        do {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right) {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } 
        while (left <= right);
        qs(arr, first, right);
        qs(arr, left, last);
    }
}
int main() {
    FILE* f1 = fopen("input.txt", "r");
    FILE* f2 = fopen("output.txt", "w");
    int n;
    fscanf(f1, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d", &A[i]);
    }
    qs(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        fprintf(f2, "%d ", A[i]);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}