#include <stdio.h>
//tao ham kiem tra so nguyen to
int nguyento(int n){
	if(n < 2) return 0;
	for(int i = 2; i * i < n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
int main() {
	//Nhap so nguyen n
	int N;
	printf("Nhap N :");
	scanf("%d", &N);
	//Tao mang a chua cac so nguyen to co dang 4k + 3 voi chi so = so do
	int a[N] = {0};
	for(int i = 0; i < N; i++){
		if(nguyento(i) == 1 && i % 4 == 3) a[i] = i;
	}
	int b1 = 0;
	//Tao mang b ke thua cac phan tu cua mang a voi chi so tu 0 toi b1
	int b[N] = {0};
	for(int i = 0; i < N; i++){
		if(a[i] > 0){
			b[b1] = a[i];
			b1++;
		}
	}
	// Tao mang c chua cac so blum duoc tao ra tu tich 2 so bat ki tu mang b
	int c[N] = {0};
	int c1 = 0;
	for(int i = 0; i < b1; i++){
		for(int j = i; j < b1; j++){
			c[c1] = b[i] * b[j];
			c1++;
		}
	}
	// Tao mang d chua cac so blum be hon N
	int d[N] = {0};
	int d1 = 0;
	for(int i = 0; i < c1; i++){
		if(c[i] < 100){
			d[d1] = c[i];
			d1++;
		}
	}
	printf("Cac so blum be hon N la :\n");
	for(int i = 0; i < d1; i++){
		printf("%d ", d[i]);
	}
    // Tao mang e chua cac phan tu la tong cua cac cap so blum
	int e[N] = {0};
	int e1 = 0;
	printf("\nCac cap so thoa man tong be hon N la :\n");
	for(int i = 0; i < d1 - 1; i++){
		for(int j = i + 1; j < d1; j++){
			e[e1] = d[i] + d[j];
			if(e[e1] < 100) printf("%d and %d\n", d[i], d[j]);
			e1++;
		}
	}
	// kiem tra xem so M co ton tai trong day so blum vua duoc tao ra khong?
	// nhap M
	int M;
	printf("\nNhap M : ");
	scanf("%d", &M);
	int check = 0;
	for(int i = 0 ; i < d1; i++){
		if(d[i] == M) check = 1;
	}
	if(check == 1) printf("M thuoc day so blum duoc tao ra");
	else printf("M khong thuoc day so blum duoc tao ra");
    return 0;
}
