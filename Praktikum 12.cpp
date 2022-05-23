#include <stdio.h>

int main(){
	int n, array[50], i, j, tmp;
	printf("Masukkan banyak elemen: ");
	scanf("%d", &n);
	printf("Masukkan nilai:\n", n);
	for(i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	for(i = 1; i <= n; i++){
		j = i;
		while(j > 0 && array[j-1] > array[j]){
			tmp = array[j];
			array[j] = array[j-1];
			array[j-1] = tmp;
			j--;
		}
	}
	printf("Hasil pengurutan sebagai berikut:\n");
	for(i = 0; i <= n-1; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
