#include <iostream>
#include <conio.h>
#define MAX 8
using namespace std;

struct stack{
    int penunjuk, data[MAX];
}
tumpukan;

void init(){
    tumpukan.penunjuk=-1;
}

bool isempty(){
    return tumpukan.penunjuk==-1;
}

bool isfull(){
    return tumpukan.penunjuk==MAX-1;
}

void push(){
    if(isfull()){
        cout << "\nStack sudah penuh\n";
    }
    else{
        tumpukan.penunjuk++;
        cout << "\nMasukkan data = ";
        cin >> tumpukan.data[tumpukan.penunjuk];
        cout << "Data " << tumpukan.data[tumpukan.penunjuk] << " masuk ke stack\n";
    }
}

void pop(){
    if(isempty()){
        cout << "\nStack masih kosong\n";
    }
    else{
        cout << "\nData " << tumpukan.data[tumpukan.penunjuk] << " sudah terambil\n";
        tumpukan.penunjuk--;
    }
}

void printstack(){
    if(isempty()){
        cout << "\nTumpukan kosong";
    }
    else{
        cout << "\nTumpukan : ";
        for(int i=tumpukan.penunjuk; i>=0; i--){
            cout << tumpukan.data[i] << ((i==0) ? "" : ",");
        }
    }
}

int main(){
    int pilihan, data;
    init();
    do{
        printstack();
        cout << "\n1. Input (push)\n2. Hapus (pop)\n3. Keluar\nMasukkan Pilihan: ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            return 0;
            default:
            cout << "\nPilihan tidak tersedia" << endl;
            break;
        }
    }
    while(pilihan!=3);
}
