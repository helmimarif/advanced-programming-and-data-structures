#include <iostream>
using namespace std;

int pangkat(int x, int y){
	if (y==0)
		return 1;
	else
		return x * pangkat(x,y-1);
}

int main(){
	int x, y;
	cout << "FUNGSI REKURSIF UNTUK MENGHITUNG PANGKAT\n" << endl;
	cout << "Masukkan Nilai X = ";
	cin >> x;
	cout << "Masukkan Nilai Y = ";
	cin >> y;
	cout << endl << x << " Dipangkatkan " << y << " = " << pangkat(x,y);
}
