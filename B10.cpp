#include <stdio.h>
#define maxSize 100

int currentSize=0,arr[maxSize];
int sortMNC; //sortMenuChoice, sortMNC = 1(mang giam dan),sortMNC = 2(mang tang dan)

void inputArray(); //Ham nhap mang
void printArray(); // Ham xuat mang
void fixArray(); // Ham sua phan tu trong mang theo vi tri
void deleteArray(); // Ham xoa phan tu trong mang theo vi tri
void sortMenu(); // MENU sap xep {TangDan,GiamDan} dung Insertion sort
void sortArray(int sortMNC);// ham sap xep
int addArray();// Them phan tu vao mang
int checkArray(int sortMNC); // Dung de kiem tra xem mang da duoc sap xep hay chua
int linearSearch(int n);//Tim kiem tuyen tinh
int binarySearch(int n,int sortMNC);// Tim kiem nhi phan

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
					choice=0;//khoi tao lai gia tri cua choice
					if(currentSize){
						sortMenu();
					}
				}
				break;
			case 7://Menu tim kiem
				{
					if(currentSize){
						int searchMN,searchNum; // searchmenuchoice
						do{
							printf("=-=-=-=-=-=-=-=-=-=-=-SEARCH MENU-=-=-=-=-=-=-=-=-=-=-=\n");
							printf("1. Linear Search\n");
							printf("2. Binary Search\n");
							printf("Lua chon cua ban: ");	scanf("%d",&searchMN);
							switch(searchMN){
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
										if(!checkArray(sortMNC)){
											printf("De thuc hien binary search xin moi ban chon menu sap xep truoc khi thuc hien thao tac !!\n");
										}
										else{
											printf("\nMoi nhap vao gia tri ban can tim kiem: ");	scanf("%d",&searchNum);
										
											if(binarySearch(searchNum,sortMNC)){
												printf("Phan tu %d ton tai trong mang",searchNum);
											}
											else{
												printf("Phan tu %d khong ton tai trong mang",searchNum);
											}
										}
									}
									break;
								default:
									printf("Gia tri nhap vao khong hop le vui long nhap lai !!\n");
							}
						}while(searchMN < 1 || searchMN > 2);
						
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
	printf("Lua chon cua ban: ");	scanf("%d",&sortMNC);
	while(sortMNC != 1 && sortMNC != 2){
		printf("Gia tri ban nhap vao khong hop le vui long nhap lai: ");	scanf("%d",&sortMNC);
	}
	sortArray(sortMNC);
}

void sortArray(int sortMNC){
	//Insertion Sort
	for(int i=1;i<currentSize;i++){
		int Index=i-1,Value=arr[i];
		while(Index >= 0 && (sortMNC==1)?arr[Index] < Value:arr[Index] > Value){
			arr[Index+1] = arr[Index];
			Index--;
		}
		arr[Index+1]=Value;
	}
	
	if(sortMNC == 1){
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

int binarySearch(int n,int sortMNC){
	int start=0,end=currentSize-1,mid;
	while(start <= end){
		mid = start + (end - start)/2;
		if(n == arr[mid])	return 1;
		
		else if((sortMNC == 1)?arr[mid] < n:arr[mid] > n)	end = mid - 1;
		
		else	start = mid + 1;
	}
	return 0;
}

int checkArray(int sortMNC){
	int flag1=1,flag2=1;// flag1 dung de kiem tra mang giam dan, flag2 dung de kiem tra mang tang dan
	
	for(int i=1;i<=2;i++){
		for(int j=0;j<currentSize-1;j++){
			if(i == 1){
				if(arr[j] < arr[j+1]){
					flag1=0;
					continue;
				}
			}
			if(i==2){
				if(arr[j] > arr[j+1]){
					flag2=0;
					break;
				}
			}
		}
	}
	
	if(flag1 + flag2 == 2){
		return 1;//Mang bang nhau tu dau den cuoi
	}
	//dat gia tri moi cho choice de biet duoc hien tai choice dang o trang thai mang tang dan hay giam dan
	if(flag1)	sortMNC = 1;
	if(flag2)	sortMNC = 2;
	
	return (flag1+flag2);
}
