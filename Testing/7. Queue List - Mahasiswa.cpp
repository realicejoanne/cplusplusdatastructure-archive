#include<iostream>
using namespace std;

struct mhs{
	char nama[10];
	char npm[8];
	mhs* next;
};

typedef mhs* pointer;
typedef pointer list;

struct queue{
	list head;
	list tail;
};
queue q;

void createQueue(queue& q){
	q.head = NULL;
	q.tail = NULL;
}

void createElement(pointer& pBaru){
	pBaru = new mhs;
	cout<<"Nama: ";
	cin>>pBaru->nama;
	cout<<"NPM: ";
	cin>>pBaru->npm;
	pBaru->next=NULL;
}

void insertQueue(queue& q,pointer pBaru){
	if(q.head==NULL && q.tail==NULL){
		q.head = pBaru;
		q.tail = pBaru;
	}
	else {
		q.tail->next=pBaru;
		q.tail = pBaru;
	}
}

void deleteQueue(queue& q, pointer& pHapus){
	if(q.head==NULL && q.tail==NULL){
		pHapus=NULL;
		cout<<"Queue kosong, tidak ada yang dihapus."<<endl;
	}
	else if(q.head->next==NULL){
		pHapus=q.head;
		q.head=NULL;
		q.tail=NULL;
	}
	else {
		pHapus=q.head;
		q.head=q.head->next;
		pHapus->next=NULL;
	}
}

void cetakQueue(queue q){
	pointer pBantu;
	if(q.head==NULL){
		cout<<"Queue kosong."<<endl;
	}
	else {
		pBantu=q.head;
		cout<<"Nama\tNPM"<<endl;
		do{
			cout<<pBantu->nama<<"\t"<<pBantu->npm<<endl;
			pBantu=pBantu->next;
		}
		while(pBantu!=q.tail->next);
	}
}

int main(){
	queue q;
	pointer pBaru, pHapus;
	
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
				createElement(pBaru);
				insertQueue(q,pBaru);
				cout<<"Mahasiswa berhasil ditambah"<<endl<<endl;
				}
				break;
			case 2: {
				deleteQueue(q,pHapus);
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
	





