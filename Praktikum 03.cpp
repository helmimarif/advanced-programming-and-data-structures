#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human{
	//menampung integer umur
	int age;
	//menampung nama manusia
	char name[30];
	//menampung alamat dari data selanjutnya
	human *next;
}*head, *tail, *current;
//head adalah pointer yang menyimpan alamat data pertama
//tail adalah pointer yang menyimpan alamat data terakhir
//current adalah pointer yang digunakan sebagai variabel

//Bagian Push Tail - Menambah data ke barisan paling akhir
void pushTail(int age, char name[]){
	//alokasi memory untuk data baru
	current = (human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//kondisi tidak kosong
	else{
		tail->next = current;
		tail = current;
	}
	tail->next = NULL;
}

//Bagian Push Head - Menambah data ke barisan paling awal
void pushHead(int age, char name[]){
	//alokasi memory untuk data baru
	current = (human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//kondisi tidak kosong
	else{
		current->next = head;
		head = current;
	}	
}

//Bagian Push Mid - Menambah data ke barisan di tengah
void pushMid(int age, char name[]){
	//alokasi memory untuk data baru
	current = (human*)malloc(sizeof(struct human));
	//assign data ke dalam struct
	current->age = age;
	strcpy(current->name, name);

	//apabila linked list kosong/tidak ada data
	if(head == NULL){
		head = tail = current;
	}
	//jika data umur yang barusan dimasukkan lebih kecil dari umur data pertama (head)
	else if(current->age < head->age){
		pushHead(age, name);
	}
	//jika data umur yang barusan dimasukkan lebih besar dari umur data terakhir (tail)
	else if(current->age > tail->age){
		pushTail(age, name);
	}
	//push ditengah-tengah
	else{
		human *temp = head;
		//mencari posisi data yang sesuai untuk diselipkan
		while(temp->next->age < current->age){
			temp = temp->next;
		}
		current->next = temp->next;
		//mengarahkan penunjuk ke alamat data baru
		temp->next = current;
	}
}

//Bagian Pop Head - Menghapus data paling awal
void popHead(){
	//inisialisasi current sebagai head
	current=head;
	//jika head kosong (tidak ada data)
	if(head==NULL){
		//cetak tidak ada data
		printf("No data");
	//jika head dan tail itu sama (hanya 1 data)
	}else if(head==tail){
		//head dan tail dikosongkan
		head=tail=NULL;
		//hapus data current (head)
		free(current);
	}else{
		//set head menjadi data selanjutnya dari head
		head=head->next;
		//hapus data current (head)
		free(current);
	}
}

//Bagian Pop Tail - Menghapus data paling akhir
void popTail(){
	//jika head kosong (tidak ada data)
	if(head==NULL){
		//cetak tidak ada data
		printf("No data");
	//jika head dan tail itu sama (hanya 1 data)
	}else if(head==tail){
		//head dan tail dikosongkan
		head=tail=NULL;
		//hapus data current (head)
		free(current);
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(temp->next!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi tail
		current=tail;
		//set tail menjadi 1 data sebelum tail (hasil looping)
		tail=temp;
		//hapus data current (tail)
		free(current);
		//data setelah next dikosongkan/pointer next punya tail diberi NULL
		tail->next=NULL;
	}
}

//Bagian Pop Mid - Menghapus data ditengah
//Menghapus data sesuai dengan umurnya.
void popMid(int age){
	current=head;
	//jika head kosong (tidak ada data)
	if(head==NULL){
		printf("No data");
	//jika data umur head(data pertama) sama dengan data umur yang mau dihapus
	}else if(head->age==age){
		//pop head
		popHead();
	//jika data umur tail(data terakhir) sama dengan data umur yang mau dihapus
	}else if(tail->age==age){
		//pop tail
		popTail();
	}else{
		//buat variabel penampung baru dan assign nilai mulai dari head
		human *temp=head;
		//looping untuk mencari posisi 1 data sebelum tail
		while(temp->next->age!=age && temp!=tail){
			//temp diubah menjadi 1 data selanjutnya
			temp=temp->next;
		}
		//set data current menjadi data selanjutnya dari temp
		current=temp->next;
		//data selanjutnya dari temp diubah menjadi 2 data setelah temp
		temp->next=temp->next->next;
		//hapus data current
		free(current);
	}
}

//Pop Mid
void popAll(){
	while(head!=NULL){
		popHead();
	}
}

//Print Data
void print(){
	current = head;
	while(current != NULL){
		printf("%s - %d\n",current->name,current->age);
		current = current->next;
	}
}

//Main Function
int main(){
	pushMid(18, "jojo");
	pushMid(17, "Amir");
	pushTail(22, "andi");
	pushHead(15, "tono");
	pushMid(16, "vandoro");
	pushMid(13, "budi");
	popHead();
	popTail();
	popMid(15);
	//popAll();
	print();
	getchar();
	return 0;
}
