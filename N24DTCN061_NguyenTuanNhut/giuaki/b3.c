#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Hàm kiểm tra tính hợp lệ của cột
int kiemtra(int col, int n) {
    return col >= 1 && col <= n;
}

// Hàm chuyển đổi hai cột a và b trong ma trận
void doicot(int arr[MAX_SIZE][MAX_SIZE], int m, int n, int cotA, int cotB) {
    for (int i = 0; i < m; i++) {
        int temp = arr[i][cotA];
        arr[i][cotA] = arr[i][cotB];
        arr[i][cotB] = temp;
    }
}

// Hàm in ma trận
void inmatran(int arr[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Nhap so hang m va so cot n (m, n <= 50): ");
    scanf("%d %d");
    if (m > MAX_SIZE || n > MAX_SIZE) {
        printf("Kich thuoc ma tran vuot qua gioi han!\n");
        return 0;
    }

    int arr[MAX_SIZE][MAX_SIZE];
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int cotA, cotB;
    printf("Nhap vi tri hai cot can chuyen doi (1 <= a, b <= %d): ", n);
    scanf("%d %d", &cotA, &cotB);

    // Kiểm tra tính hợp lệ của cột
    if (!kiemtra(cotA, n) || !kiemtra(cotB, n)) {
        printf("Vi tri cot khong hop le!\n");
        return 0;
    }

    // Kiểm tra cột trùng nhau
    if (cotA == cotB) {
        printf("Cac cot truyen vao giong nhau, khong can chuyen doi.\n");
    } else {
        doicot(arr, m, n, cotA - 1, cotB - 1);
        printf("Ma tran sau khi chuyen doi hai cot:\n");
        inmatran(arr, m, n);
    }

    return 0;
}
