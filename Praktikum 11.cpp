#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main(){
	int i, j, F0, F1, Fibo, n, m, N, Flag, x;
	int FK, FK1, FK2, FK3, s, p, q, t;
	int A[10] = {8, 15, 21, 28, 31, 37, 39, 46, 48, 50};
	int FIBO[8];
	cout << "\tMetode Fibonancci Search\n\n";
	cout << "Data : ";
	for(x=0; x<10; x++){
		cout << A[x]<<" ";
		n = 9;
		F0 = 1; F1 = 1; Fibo = 1;
		j = 1;
	}
	while(Fibo<= n+1){
		FIBO[j] = Fibo;
		Fibo = F0+F1; F0=F1; F1=Fibo;
		j++;
	}
	s = j - 1;
	FK = FIBO[s];
	FK1 = FIBO[s-1]; i = FK1;
	FK2 = FIBO[s-2]; p = FK2;
	FK3 = FIBO[s-3]; q = FK3;
	m = (n+1) - FK;
	printf("\n\nMasukkan data yang ingin dicari : ");
	scanf("%d", &N);
	
	if(N > A[i]) i = i+m;
	Flag = 0;
	while(i != 0 && Flag ==0){
		if(N == A[i]) Flag = 1;
		else if(N < A[i]){
			if(q == 0) i = 0;
			else{
				i = i - q;
				t = p;
				p = q;
				q = t - q;
			}
		}
		else{
			if(p == 1)
			i = 0;
			else{
				i = i + q;
				p = p - q;
				q = q - p;
			}
		}
	}
	if(Flag == 1)
	printf("\nData ditemukan");
	else
	printf("\nData tidak ditemukan");
}
