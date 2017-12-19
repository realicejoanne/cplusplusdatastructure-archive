#include<iostream>
using namespace std;

const int maxElemen = 255; //antrian maksimal

struct mhs{
	char nama[10];
	char npm[8];
};

struct queue{
	mhs isi[maxElemen];
	int head;
	int tail;
};
queue q;

void createQueue(queue& q){
	q.head = 0;
	q.tail = -1;
}

void createElement(mhs& baru){
	cout<<"Masukkan nama: ";
	cin>>baru.nama;
	cout<<"Masukkan NPM: ";
	cin>>baru.npm;
}

void insertQueue(queue& q, mhs baru){
	if(q.tail==maxElemen-1){
		cout<<"Antrian penuh"<<endl;
	}
	else {
		q.tail = q.tail+1;
		q.isi[q.tail] = baru;
	}
}

void deleteQueue(queue& q, mhs& hapus){
	if(q.head > q.tail){
		cout<<"Antrian kosong, tidak ada yang dihapus."<<endl;
	}
	else {
		hapus = q.isi[q.head];
		for(int i=0;i<q.tail;i++){
			q.isi[q.tail] = q.isi[q.tail+1];
		}
		q.tail = q.tail-1;
	}
}

void cetakQueue(queue q){
	int i=0;
	cout<<"Nama\tNPM"<<endl;
	while(i!=q.tail+1){
		cout<<q.isi[i].nama<<"\t"<<q.isi[i].npm<<endl;
		i++;
	}
}
	
int main(){
	queue q;
	mhs baru,hapus;
	createQueue(q);
	int pilih;
	do{
		cout<<"         Menu         "<<endl;
		cout<<"----------------------"<<endl;
		cout<<"1. Insert Mahasiswa"<<endl;
		cout<<"2. Delete Mahasiswa"<<endl;
		cout<<"3. Cetak Mahasiswa"<<endl;
		cout<<"0. Keluar"<<endl;
		
		cout<<endl<<"Masukkan pilihan: ";
		cin>>pilih;
		
		switch(pilih){
			case 1: {
				createElement(baru);
				insertQueue(q,baru);
				cout<<"Mahasiswa berhasil ditambah"<<endl<<endl;
				}
				break;
			case 2: {
				deleteQueue(q,hapus);
				cout<<"Mahasiswa berhasil dihapus"<<endl<<endl;
				}
				break;
			case 3: {
				cetakQueue(q);
				cout<<endl;
				}
				break;
		}
	}
	while(pilih!=0);
}
