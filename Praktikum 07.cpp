#include <iostream>
#define MAX 20 //maksimum data queue
using namespace std;
struct Queue {
 int front, rear, data[MAX];
}Q;
bool isFull() {
 return Q.rear = MAX;
}
bool isEmpty() {
 return Q.rear = 0;
}
void printQueue() {
 if (isEmpty()) {
 cout << "Antrian kosong"<<endl;
 }
 else {
 cout << "QUEUE : ";
 for (int i = Q.front; i < Q.rear; i++)
 //menambahkan koma jika data tidak terdapat di antrian pertama
 cout << Q.data[i] << ((Q.rear-1 == i) ? "" : ",");
 cout << endl;
 }
}
void antri() {
 if (isFull())
 {
 cout << "Antrian penuh!"<<endl;
 }
 else {
 int data;
 //menambahkan data ke antrian
 cout << "Masukkan Data : ";cin >> data;
 Q.data[Q.rear] = data;
 //menempatkan tail pada elemen data terakhir yang ditambahkan
 Q.rear++;
 cout << "Data ditambahkan\n";
 printQueue();
}
}
void keluar() {
if (isEmpty())
{
 cout << "Antrian masih kosong"<<endl;
}
else{
 cout << "Mengambil data \"" << Q.data[Q.front] << "\"..." << endl;
 //menggeser antrian data ke head
 for (int i = Q.front; i < Q.rear; i++)
 Q.data[i] = Q.data[i + 1];
 //menempatkan tail pada data terakhir yang digeser
 Q.rear--;
 printQueue();
}
}
int main() {
int chose;
do
{
 //Tampilan menu
 cout << "--------------------------------\n"
 << " Program Antrian Sederhana\n"
 << "---------------------------------\n"
 << " [1] Masukan \n"
 << " [2] Keluarkan \n"
 << " [3] Exit \n\n"
 << "---------------------------------\n"
 << "Masukkan pilihan : "; cin >> chose;
 switch (chose)
 {
 case 1:
 antri();
 break;
 case 2:
 keluar();
 break;
 defaul:
 cout << "Pilihan tidak tersedia";
 break;
 }
} while (chose !=3);
return 0;
}
