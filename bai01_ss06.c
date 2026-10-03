#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50
#define DON_GIA_PHAT 5000

int main(void)
{
    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;

    int chon;
    int c;
    int i;

    do
    {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");

        if (scanf("%d", &chon) != 1)
        {
            chon = -1; /* nhap khong phai so */
        }
        /* Lam sach bo dem ban phim */
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (chon)
        {
        case 1:
            printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
            printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
            printf("--------------------------------------------------\n");
            for (i = 0; i < soLuong; i++)
            {
                int tienPhat = ngayQuaHan[i] * DON_GIA_PHAT;
                printf("%d | %s | %d ngay | %d VND\n",
                       i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
            }
            printf("--------------------------------------------------\n");
            printf("Tong so phieu: %d\n", soLuong);
            break;

        case 2:
            if (soLuong >= MAX_PHIEU)
            {
                printf("Loi: Danh sach phieu muon da day, khong the them!\n");
            }
            else
            {
                char maMoi[20];
                int trung = 0;

                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maMoi);
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                for (i = 0; i < soLuong; i++)
                {
                    if (strcmp(maPhieu[i], maMoi) == 0)
                    {
                        trung = 1;
                        break;
                    }
                }

                if (trung)
                {
                    printf("Loi: Ma phieu muon '%s' da ton tai!\n", maMoi);
                }
                else
                {
                    strcpy(maPhieu[soLuong], maMoi);
                    ngayQuaHan[soLuong] = 0;
                    soLuong++;
                    printf("Them moi thanh cong phieu muon '%s' (so ngay qua han = 0).\n", maMoi);
                }
            }
            break;

        case 3:
        {
            char maTim[20];
            int viTri = -1;

            printf("Nhap ma phieu muon can cap nhat: ");
            scanf("%19s", maTim);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            for (i = 0; i < soLuong; i++)
            {
                if (strcmp(maPhieu[i], maTim) == 0)
                {
                    viTri = i;
                    break;
                }
            }

            if (viTri == -1)
            {
                printf("Khong tim thay phieu muon '%s'!\n", maTim);
            }
            else
            {
                int ngayMoi;
                printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTim, viTri);

                for (;;)
                {
                    printf("Nhap so ngay qua han moi: ");
                    if (scanf("%d", &ngayMoi) != 1)
                    {
                        printf("Loi: Vui long nhap mot so nguyen!\n");
                    }
                    else if (ngayMoi < 0)
                    {
                        printf("Loi: So ngay qua han phai >= 0, vui long nhap lai!\n");
                    }
                    else
                    {
                        while ((c = getchar()) != '\n' && c != EOF)
                            ;
                        break;
                    }
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                }

                ngayQuaHan[viTri] = ngayMoi;
                printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n",
                       maPhieu[viTri], ngayMoi);
            }
            break;
        }

        case 0:
            printf("Cam on ban da su dung he thong LIBRARY_WMS. Tam biet!\n");
            break;

        default:
            printf("Lua chon khong hop le, vui long chon lai!\n");
            break;
        }
    } while (chon != 0);

    return 0;
}
