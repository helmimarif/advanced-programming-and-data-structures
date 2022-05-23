#include <stdio.h>

int cari (int data[], int n, int k){
	int posisi, i, ketemu;
	if(n <= 0)
	posisi = -1;
	else{
		ketemu = 0;
		i = 1;
		while((i <= n-1) && (!ketemu))
		if(data[i] == k){
			posisi = i;
			ketemu = 1;
		}
		else
		i++;
		if(!ketemu)
		posisi = -1;
	}
	return posisi;
}

int main(){
	int data[5] = {12, 13, 19, 27, 28};
	int dicari = 19;
	
	printf("\tMetode Sequential Search\n\n");
	printf("Data: 12, 13, 19, 27, 28\n\n");
	printf("Posisi %d berada pada index ke-: %d \n", dicari, cari(data, 5, dicari));
	
	return 0;
}
