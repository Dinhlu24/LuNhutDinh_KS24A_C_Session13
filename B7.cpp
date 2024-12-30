#include <stdio.h>
#define maxSize 100

int matrix[maxSize][maxSize]={0};

void matrixInput(int n,int m);
void matrixOutput(int n,int m);

int main(){
	int n,m;
	printf("Moi ban nhap vao so hang: ");	scanf("%d",&n);
	printf("Moi ban nhap vao so cot: ");	scanf("%d",&m);
	
	matrixInput(n,m);
	matrixOutput(n,m);
}

void matrixInput(int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Matrix[%d]: ",i);
			scanf("%d",&matrix[i][j]);
		}
	}
}

void matrixOutput(int n,int m){
	printf("Day la ma tran cua ban:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
