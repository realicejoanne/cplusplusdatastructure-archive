/*	Nama program	: Taman Bermain Jati Fun
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 05-06-17
	Deskripsi		: UAS - Priority Queue
**************************************************/

#include<iostream>
using namespace std;

struct tiket{
	char kode[6];
	int prior;
	tiket* next;
};

typedef tiket* pointer;
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
	pBaru = new tiket;
	cout<<"Masukkan kode tiket: ";
	cin>>pBaru->kode;
	do{
		cout<<"Masukkan prioritas (1-4): ";
		cin>>pBaru->prior;
		if(pBaru->prior < 1 || pBaru->prior > 4){
			cout<<"Terjadi kesalahan input. Prioritas yang tersedia hanya 1-4."<<endl;
		}
	}
	while (pBaru->prior < 1 || pBaru->prior > 4);
	pBaru->next=NULL;
}

void insertQueue(queue& q, pointer pBaru){ // 1 harus yang tertinggi, 4 yang terendah
		if (q.head==NULL && q.tail==NULL){ //kosong
		q.head=pBaru;
	}
	else if (q.head->next==NULL){ //1 elemen
		if (pBaru->prior>q.head->prior){
			pBaru->next=q.head;
			q.head=pBaru;
		}
		else{
			q.head->next=pBaru;
			q.tail=pBaru;
		}
	}
	else{ //>1 elemen
		pointer pBantu;
		pointer pBefore;
		pBantu=q.head;
		while(pBantu->prior>=pBaru->prior && pBantu->next!=NULL){
			pBefore=pBantu;
			pBantu=pBantu->next;
		}
		if(pBantu==q.head){
			pBaru->next=pBantu;
			q.head=pBaru;
		}
		else if(q.tail->prior>=pBaru->prior){
			q.tail->next=pBaru;
			q.tail=pBaru;
		}
		else{
			pBaru->next=pBefore->next;
			pBefore->next=pBaru;
		}
	}
}

void deleteQueue(queue& q, pointer& pHapus){
	if(q.head==NULL && q.tail==NULL){ //kosong
		pHapus=NULL;
		cout<<"Queue kosong, tidak ada yang dihapus."<<endl;
	}
	else if(q.head->next==NULL) { //1 elemen
		pHapus=q.head;
		q.head=NULL;
		q.tail=NULL;
	}
	else{ //>1 elemen
		pHapus=q.head;
		q.head=q.head->next;
		pHapus->next=NULL;
	}
}

void traversal(queue q){
	if (q.head==NULL){
		cout<<"Antrian kosong"<<endl;
	}
	else{
		pointer pBantu;
		pBantu=q.head;
		cout<<"| Kode | Prior |"<<endl;
		cout<<"----------------"<<endl;
		do{
			cout<<"| "<<pBantu->kode<<" | "<<pBantu->prior<<endl;
			pBantu=pBantu->next;
		}while(pBantu!=NULL);
		cout<<"----------------"<<endl;
	}
}

int main(){
	cout<<"SELAMAT DATANG DI TAMAN BERMAIN JATI FUN!"<<endl;
	cout<<"-----------------------------------------"<<endl<<endl;
	cout<<"Silakan lakukan pemesanan tiket di program ini."<<endl;
	cout<<"Tiket yang tersedia terdiri dari:"<<endl;
	cout<<"1. Platinum\n2. Gold\n3. Silver\n4. Bronze"<<endl<<endl;
	
	queue q;
	pointer pBaru, pHapus;
	int pilih;
	createQueue(q);
	
	do{
		cout<<"  M E N U  A N T R I A N  "<<endl;
		cout<<"--------------------------"<<endl;
		cout<<"1. Tambah pengunjung"<<endl;
		cout<<"2. Hapus pengunjung"<<endl;
		cout<<"3. Cetak daftar pengunjung"<<endl;
		cout<<"0. Keluar"<<endl<<endl;
		
		cout<<"Masukkan pilihan: ";
		cin>>pilih;
		
		switch(pilih){
			case 1: {
				createElement(pBaru);
				insertQueue(q,pBaru);
				cout<<"Pengunjung berhasil ditambah"<<endl<<endl;
				}
				break;
			case 2: {
				deleteQueue(q,pHapus);
				cout<<"Pengunjung berhasil dihapus"<<endl<<endl;
				}
				break;
			case 3: {
				traversal(q);
				cout<<endl;
				}
				break;
			default: cout<<"Maaf, pilihan tidak tersedia, silakan pilih lagi."<<endl<<endl;
		}
	}
	while (pilih!=0);
}