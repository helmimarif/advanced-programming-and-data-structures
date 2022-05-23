#include <stdio.h>
#define ROW 3 
#define COL 5 

int main(void){
	int data[ROW][COL];
	int i, j; 
	printf("-- ARRAY 2 DIMENSI --\n\n");
	for(int i = 0; i < ROW; i++){
		printf("Baris Ke-%d\n", i+1);
	for(int j = 0; j < COL; j++){
		printf(" Data Kolom %d: ", j+1);
		scanf("%d", &data[i][j]);
	}
	printf("\n");
	} 
	printf("Hasilnya: \n--------------------------------\n");
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			printf(" %d\t", data[i][j]);
	} 
	printf("\n");
	} 
return 0; 
}
