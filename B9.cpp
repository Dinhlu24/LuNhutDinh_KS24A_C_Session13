#include <stdio.h>
#define maxSize 100

int n=0,m=0;
int matrix[maxSize][maxSize]={{0}};

void inputMatrix();
void printMatrix();
void cornerMatrix();
void borderMatrix();
void duongCheoChinh();
void duongCheoPhu();
int isPrime(int n);
void primeMatrix();

int main(){
	int choice=0;
	do{
		printf("---------------MENU---------------\n");
		printf("1.Nhap gia tri cac phan tu cua mang\n");
		printf("2.In ra gia tri cac phan tu theo ma tran\n");
		printf("3.In ra cac phan tu o goc theo ma tran\n");
		printf("4.In ra cac phan tu nam tren duong bien theo ma tran\n");
		printf("5.In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
		printf("6.In ra cac phan tu la so nguyen to theo ma tran\n");
		printf("7.Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d", &choice);
		switch(choice){
			case 1://Nhap gia tri cac phan tu cua mang
				{
					inputMatrix();
				}
				break;
			case 2://In ra gia tri cac phan tu theo ma tran
				{
					if(n != 0 && m != 0){
						printMatrix();
					}
				}
				break;
			case 3://In ra cac phan tu o goc theo ma tran
				{
					if(n != 0 && m != 0){
						cornerMatrix();
					}
				}
				break;
			case 4://In ra cac phan tu nam tren duong bien theo ma tran
				{
					if(n != 0 && m != 0){
						borderMatrix();
					}
				}
				break;
			case 5://In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran
				{
					if(n != 0 && m != 0){
						duongCheoChinh();
						duongCheoPhu();
					}
				}
				break;
			case 6://In ra cac phan tu la so nguyen to theo ma tran
				{
					if(n != 0 && m != 0){
						primeMatrix();
					}
				}
				break;
			case 7://Thoat
				{
					printf("Chuong trinh ket thuc");
				}
				break;
			default:
				printf("Lua chon cua ban khong hop le vui long nhap lai!!!\n");
		}
		if(n == 0 && m == 0 && choice >= 1 && choice < 7){
			printf("Ma tran cua ban dang trong vui long nhap ma tran vao truoc khi thuc hien thao tac\n");
		}
		printf("\n\n");
	}while(choice != 7);
	
	return 0;
}

void inputMatrix(){
	printf("Moi ban nhap vao do dai hang (2->100): ");	scanf("%d",&n);
	while(n <= 1 || n > maxSize){
		printf("Gia tri banh nhap vao khong hop le vui long nhap lai (1 -> 100): ");
		scanf("%d", &n);
	}
	
	printf("Moi ban nhap vao do dai cot (2 -> 100): ");	scanf("%d",&m);
	while(m <= 1 || m > maxSize){
		printf("Gia tri banh nhap vao khong hop le vui long nhap lai (1 -> 100): ");
		scanf("%d", &m);
	}
	printf("Nhap lieu hoan thanh\n");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Matrix[%d][%d]: ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("Nhap gia tri hoan thanh\n");
}

void printMatrix(){
	printf("Day la ma tran cua ban:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void cornerMatrix(){
	printf("Hien thi cac goc cua ma tran:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i == 0 && j == 0 || i == 0 && j == m-1 || i == n-1 && j == 0 || i == n-1 && j == m-1){
				printf("%d ",matrix[i][j]);
			}
			else	printf("  ");
		}
		printf("\n");
	}
}

void borderMatrix(){
	printf("Hien thi duong bien cua ma tran:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
				printf("%d ",matrix[i][j]);
			}
			else	printf("  ");
		}
		printf("\n");
	}
}

void duongCheoChinh(){
	printf("Day la duong cheo chinh:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i == j)	printf("%d ",matrix[i][j]);
			else	printf("  ");
		}
		printf("\n");
	}
}

void duongCheoPhu(){
	printf("Day la duong cheo phu:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i == m-j-1)	printf("%d",matrix[i][j]);
			else	printf("  ");
		}
		printf("\n");
	}
}

int isPrime(int n){
	if(n < 2)	return 0;
	
	for(int i=2;i*i<=n;i++){
		if(n % i == 0)	return 0;
	}
	
	return 1;
}

void primeMatrix(){
	printf("Hien thi cac so nguyen to tren ma tran:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(isPrime(matrix[i][j]))	printf("%d ",matrix[i][j]);
			else	printf("  ");
		}
		printf("\n");
	}
}
