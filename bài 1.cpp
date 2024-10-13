#include<stdio.h>
// Tao ham sap xep 
void sapxep(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; 
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j; 
            }
        }
        if (min != i) {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}
int main(){
    int ncolor;// so mau sac
    printf("Nhap so mau sac : ");
    scanf("%d", &ncolor);
    // Tao 1 mang chua cac mau sac vua nhap
    int a[ncolor];
    //Dinh danh cac mau sac voi cac chi so nhu sau : red = 0; white = 1; blue = 2;
    printf("\nNhap chi so cua cac mau sac: ");
    for(int i = 0; i < ncolor; i++){
        scanf("%d", &a[i]);// nhap chi so cua cac mau sac
    }
    sapxep(a, ncolor);// Sap xep lai cac mau sac theo chi so tu be den lon
    printf("Cac mau sac da duoc sap xep : ");
    for (int i = 0; i < ncolor; i++) {// in ra mau sac da sap xep
        if (a[i] == 0) {
            printf("red ");
        } else if (a[i] == 1) {
            printf("white ");
        } else if (a[i] == 2) {
            printf("blue ");
        }
    }
    return 0;
}