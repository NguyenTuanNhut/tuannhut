#include <stdio.h>
#include <stdbool.h>


bool kiemtra(int so) {
    if (so < 2) return false;
    for (int i = 2; i * i <= so; i++) {
        if (so % i == 0) return false;
    }
    return true;
}


void max2mang(int arr[][50], int m, int n, int *row, int *col, int *value) {
    int max1 = -1e9, max2 = -1e9;
    *row = *col = -1;

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          
            if (arr[i][j] > max1) {
                max2 = max1;
                max1 = arr[i][j];
            } else if (arr[i][j] > max2 && arr[i][j] != max1) {
                max2 = arr[i][j];
            }
        }
    }

   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == max2) {
                *row = i;
                *col = j;
                *value = max2;
                return;
            }
        }
    }
}


int main() {
    int m, n;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &m, &n);

    
    if (m <= 0 || m > 50 || n <= 0 || n > 50) {
        printf("Kich thuoc mang khong hop le!\n");
        return 1;
    }

    int arr[50][50];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Mang vua nhap:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

 
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (kiemtra(arr[i][j])) {
                tong += arr[i][j];
            }
        }
    }
    if (tong == 0) {
        printf("Mang khong co so nguyen to.\n");
    } else {
        printf("Tong cac so nguyen to: %d\n", tong);
    }

   
    int maxhang = -1, maxdem = 0;
    for (int i = 0; i < m; i++) {
        int dem = 0; 
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 == 0) {
                dem++;
            }
        }
        if (dem > maxdem) { 
            maxdem = dem;
            maxhang = i;
        }
    }
    if (maxdem == 0) {
        printf("Khong co hang nao co so chan.\n");
    } else {
        printf("Hang co nhieu so chan nhat la hang: %d\n", maxhang + 1);
    }

    
    int row, col, value;
    max2mang(arr, m, n, &row, &col, &value);
    if (value == -1e9) {
        printf("Mang khong co phan tu lon thu 2.\n");
    } else {
        printf("Phan tu lon thu 2 la %d o vi tri (%d, %d)\n", value, row + 1, col + 1);
    }

    return 0;
}
