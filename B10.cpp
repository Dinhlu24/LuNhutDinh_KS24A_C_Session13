#include <stdio.h>
#define maxSize 100

int currentSize=0,arr[maxSize];
int smnc; //sortMenuChoice

void inputArray();
void printArray();
int addArray();
void fixArray();
void deleteArray();
void sortMenu();
void sortArray(int choice);
int linearSearch(int n);
int binarySearch(int n,int choice);

int main(){
	int choice=0;
	do{
		printf("1. Nhap so phan tu & gia tri cac phan tu\n");
		printf("2. In gia tri cac phan tu\n");
		printf("3. Them phan tu vao\n");
		printf("4. Sua phan tu\n");
		printf("5. Xoa phan tu\n");
		printf("6. Menu sap xep\n");
		printf("7. Menu tim kiem\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d",&choice);
		printf("\n");
		switch(choice){
			case 1://Nhap so phan tu & gia tri cac phan tu
				{
					inputArray();
				}
				break;
			case 2://In gia tri cac phan tu
				{
					if(currentSize){
						printArray();
					}
				}
				break;
			case 3://Them phan tu vao
				{
					if(currentSize){
						addArray();
					}
				}
				break;
			case 4://Sua phan tu
				{
					if(currentSize){
						fixArray();
					}
				}
				break;
			case 5://Xoa phan tu
				{
					if(currentSize){
						deleteArray();
					}
				}
				break;
			case 6://Menu sap xep
				{
					if(currentSize){
						sortMenu();
					}
				}
				break;
			case 7://Menu tim kiem
				{
					if(currentSize){
						int smn,searchNum; // searchmenuchoice
						do{
							printf("=-=-=-=-=-=-=-=-=-=-=-SEARCH MENU-=-=-=-=-=-=-=-=-=-=-=\n");
							printf("1. Linear Search\n");
							printf("2. Binary Search\n");
							printf("Lua chon cua ban: ");	scanf("%d",&smn);
							switch(smn){
								case 1:
									{
										printf("Moi nhap vao gia tri ban can tim kiem: ");	scanf("%d",&searchNum);
										if(linearSearch(searchNum)){
											printf("Phan tu %d ton tai trong mang",searchNum);
										}
										else{
											printf("Phan tu %d khong ton tai trong mang",searchNum);
										}
									}
									break;
								case 2:
									{
										printf("De thuc hien binary search xin moi ban chon menu sap xep truoc khi thuc hien thao tac !!\n");
										sortMenu();
										printf("\nMoi nhap vao gia tri ban can tim kiem: ");	scanf("%d",&searchNum);
										
										if(binarySearch(searchNum,smnc)){
											printf("Phan tu %d ton tai trong mang",searchNum);
										}
										else{
											printf("Phan tu %d khong ton tai trong mang",searchNum);
										}
									}
									break;
								default:
									printf("Gia tri nhap vao khong hop le vui long nhap lai !!\n");
							}
						}while(smnc < 1 || smnc > 2);
						
					}
				}
				break;
			case 8:
				{
					printf("Chuong trinh ket thuc");
				}
				break;
			default:
				printf("Gia tri ban nhap vao khong hop le");
		}
		if(currentSize == 0 && choice != 8)	printf("\nMang cua ban dang trong vui long nhap mang truoc khi thuc hien thao tac");
		printf("\n\n");	
	}while(choice != 8);
	
	return 0;
}

void inputArray(){
	do{
		printf("Moi nhap vao do dai cua mang: ");	scanf("%d",&currentSize);
		if(currentSize <= 0 || currentSize > maxSize)
		printf("Do dai cua ban khong hop le vui long nhap lai !!\n");
	}while(currentSize <= 0 || currentSize > maxSize);
					
	printf("Do dai hop le !!\n");
	for(int i=0;i<currentSize;i++){
		printf("Array[%d]: ",i);
		scanf("%d",arr+i);
	}
	printf("Nhap gia tri hoan tat !!\n");
}

void printArray(){
	for(int i=0;i<currentSize;i++){
		printf("Array[%d]: %d",i,arr[i]);
		if(i < currentSize-1)	printf(", ");
	}
}

int addArray(){
	int addIndex,addValue;
	printf("Moi nhap vao vi tri muon them vao (0 -> %d): ",currentSize-1);	scanf("%d",&addIndex);
	printf("Moi nhap vao gia tri muon them vao: ");	scanf("%d",&addValue);
	
	currentSize++;
	if(addIndex > currentSize){
		addIndex=currentSize;
		arr[addIndex] = addValue;
		return 0;
	}
	else if(addIndex <= 0){
		addIndex=0;
	}
	
	for(int i=currentSize-2;i>=addIndex-1;i--){
		arr[i+1]=arr[i];
	}
	arr[addIndex] = addValue;
	printf("Da them xong !!");
}

void fixArray(){
	int fixIndex,fixValue;
	do{
		printf("Moi nhap vao vi tri muon sua (0 -> %d): ",currentSize-1);	scanf("%d",&fixIndex);
		if(fixIndex < 0 || fixIndex >= currentSize)
			printf("Vi tri ban nhap vao khong hop le vui long nhap lai !!\n");
	}while(fixIndex < 0 || fixIndex >= currentSize);
	
	printf("Moi nhap vao gia tri muon sua: ");	scanf("%d",&fixValue);
	
	arr[fixIndex] = fixValue;
	printf("Da sua xong !!");
}

void deleteArray(){
	int deleteIndex;
	
	do{
		printf("Moi nhap vao vi tri muon xoa (0 -> %d): ",currentSize-1);	scanf("%d",&deleteIndex);
		if(deleteIndex < 0 || deleteIndex >= currentSize)
			printf("Vi tri ban nhap vao khong hop le vui long nhap lai !!\n");
	}while(deleteIndex < 0 || deleteIndex >= currentSize);
	
	currentSize--;
	for(int i=deleteIndex;i<currentSize;i++){
		arr[i] = arr[i+1];
	}
	printf("Da xoa xong !!");
}

void sortMenu(){	
	printf("=-=-=-=-=-=-=-=-=-=-=-SORT MENU-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("1. Giam dan\n");
	printf("2. Tang dan\n");
	printf("Lua chon cua ban: ");	scanf("%d",&smnc);
	while(smnc != 1 && smnc != 2){
		printf("Gia tri ban nhap vao khong hop le vui long nhap lai: ");	scanf("%d",&smnc);
	}
	sortArray(smnc);
}

void sortArray(int choice){
	for(int i=0;i<currentSize-1;i++){
		int Index=i;
		for(int j=i+1;j<currentSize;j++){
			if((choice == 1)?(arr[j] > arr[Index]):(arr[j] < arr[Index])){
				Index = j;
			}
		}
		int tmp=arr[i]; arr[i] = arr[Index]; arr[Index] = tmp;
	}
	if(choice == 1){
		printf("Da sap xep giam dan xong !!");
	}
	else	printf("Da sap xep tang dan xong !!");
}

int linearSearch(int n){
	for(int i=0;i<currentSize;i++){
		if(arr[i] == n)	return 1;
	}
	return 0;
}

int binarySearch(int n,int choice){
	int start=0,end=currentSize-1,mid;
	while(start <= end){
		mid = start + (end - start)/2;
		if(n == arr[mid])	return 1;
		
		else if((choice == 1)?arr[mid] < n:arr[mid] > n)	end = mid - 1;
		
		else	start = mid + 1;
	}
	return 0;
}
