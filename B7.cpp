#include <stdio.h>
#define maxSize 100

int n,m;
int matrix[maxSize][maxSize]={0};

void matrixInput();
void matrixOutput();

int main(){
	matrixInput();
	matrixOutput();
}

void matrixInput(){
	printf("Moi ban nhap vao so hang: ");	scanf("%d",&n);
	printf("Moi ban nhap vao so cot: ");	scanf("%d",&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Matrix[%d]: ",i);
			scanf("%d",&matrix[i][j]);
		}
	}
}

void matrixOutput(){
	printf("Day la ma tran cua ban:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
