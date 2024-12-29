#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    printf("Nhap so luong ma sinh vien can kiem tra: ");
    scanf("%d", &n);
    char msv_id[11];
    char valid_ids[n][11];
    int valid_count = 0;

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Nhap ma sinh vien thu %d: ", i + 1);
            scanf("%s", msv_id);
            if (strlen(msv_id) != 10) {
                printf("Khong hop le: Ma sinh vien phai co 10 ky tu.\n");
                continue;
            }
            if (msv_id[0] != 'N') {
                printf("Khong hop le: Ma sinh vien phai bat dau bang ky tu 'N'.\n");
                continue;
            }
            if (!isdigit(msv_id[1]) || !isdigit(msv_id[2])) {
                printf("Khong hop le: Hai ky tu tiep theo phai la so (vi du: '24').\n");
                continue;
            }
            int valid = 1;
            for (int j = 3; j <= 6; j++) {
                if (!isalpha(msv_id[j])) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Khong hop le: Bon ky tu o giua phai la chu cai (vi du: 'DTCN').\n");
                continue;
            }
            for (int j = 7; j <= 9; j++) {
                if (!isdigit(msv_id[j])) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Khong hop le: Ba ky tu cuoi phai la so (vi du: '012').\n");
                continue;
            }
            strcpy(valid_ids[valid_count++], msv_id);
            printf("Ma sinh vien %s hop le.\n", msv_id);
            break;
        }
    }

    printf("\nDanh sach ma sinh vien hop le:\n");
    for (int i = 0; i < valid_count; i++) {
        printf("%s\n", valid_ids[i]);
    }

    return 0;
}