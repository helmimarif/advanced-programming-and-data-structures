#include <iostream>
using namespace std;

int main(){
	int x,n,i,cek,bil;
	cout << "Masukkan Bilangan Awal (x) : ";
	cin >> x;
	cout << "Masukkan Bilangan Akhir (n) : ";
	cin >> n;

int hasil[n];
	bil=x;
		while(bil<=n){
			cek=0;
			for(int j=2;j<=bil;j++){
				if(bil%j==0){
					cek++;
				}
			}
			if(cek==1){
				hasil[i]=bil;
				i++;
			}
			bil++;
		}
		for(int j=0; j<i; j++){
			cout << hasil[j];
			if(j<i-1){
				cout << ", ";
			}
		}
}
