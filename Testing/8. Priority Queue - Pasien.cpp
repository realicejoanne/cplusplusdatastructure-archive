#include<iostream>
using namespace std;

struct elqueue{
	char nama[20];
	int prior;
	elqueue* next;
};

typedef elqueue* pointer;
typedef pointer list;

struct queue{
	list head;
	list tail;
};
queue Q;

void createQueue(queue& Q){
	Q.head = NULL;
	Q.tail = NULL;
}

void createElement(pointer& pBaru){
	pBaru=new elqueue;
	cout<<"Masukkan nama pasien\t: " ;
	cin>>pBaru->nama;
	cout<<"Masukkan nomor antrian\t: " ;
	cin>>pBaru->prior;
	pBaru->next=NULL;
}

void insertFirstQueue(queue& Q,pointer pBaru){
	pBaru->next=Q.head;
	Q.head=pBaru;
}

void insertLastQueue(queue& Q,pointer pBaru){
	pointer last;
	last=Q.head;
	while(last!=Q.tail){
		last=last->next;
	}
	last->next=pBaru;
	Q.tail=pBaru;
}

void insertBeforeQueue(queue& Q,pointer pBaru,pointer pBantu){
	pBantu=Q.head;
	pointer prev;
	while(pBantu->prior>pBaru->prior){
		prev=pBantu;
		pBantu=pBantu->next;
	}
	pBaru->next=pBantu;
	prev->next=pBaru;
}

void inputQueue(queue& Q,pointer& pBaru,pointer pBantu){
	createElement(pBaru);
	if(Q.head == NULL){
		Q.head = pBaru;
		Q.tail = pBaru;
	}
	else{
		if(pBaru->prior>Q.head->prior){
			insertFirstQueue(Q,pBaru);
		}
		else if(pBaru->prior<Q.tail->prior||pBaru->prior==Q.tail->prior){
			insertLastQueue(Q,pBaru);
		}		
		else insertBeforeQueue(Q,pBaru,pBantu);
	}
}

void deleteQueue(queue& Q,pointer& pHapus){
	if(Q.head==NULL){
		cout<<"Antrian sudah kosong!";
	}
	else{
		if(Q.head->next==NULL){
			pHapus=Q.head;
			Q.head=NULL;
		}
		else{
			pHapus=Q.head;
			Q.head=pHapus->next;
			pHapus->next=NULL;
		}
	}
}

void traversal(queue Q){
	pointer pBantu;
	pBantu=Q.head;
	cout<<"Nama\tNo. Antrian"<<endl;
	do{
		cout<<pBantu->nama<<"\t"<<pBantu->prior<<endl;
		pBantu = pBantu->next;
	}
	while(pBantu!=NULL);
}

int main(){
	queue Q;
	pointer pBaru,pHapus,pBantu;
	char cek;
	int pilih;
	
	cout<<"DAFTAR REKAP PASIEN RS HARMONI 28/05/17"<<endl;
	cout<<"***************************************"<<endl;
	
	createQueue(Q);
	do{
		createElement(pBaru);
		insertFirstQueue(Q,pBaru);
		cout<<"(Y/N)\t: ";
		cin>>cek;
	}
	while(cek=='Y'||cek=='y');
	
	do{
		cout<<endl;
		cout<<"--------------- M E N U ---------------"<<endl;
		cout<<"1. Tampilkan antrian sementara (traversal)"<<endl;
		cout<<"2. Tambah pasien (input)"<<endl;
		cout<<"3. Hapus pasien yang sudah keluar (delete)"<<endl;
		
		cout<<endl<<"Masukkan Pilihan: ";
		cin>>pilih;
		
		switch(pilih){
			case 0: return 0;
			case 1: traversal(Q);
				break;
			case 2: do{
						createElement(pBaru);
						inputQueue(Q,pBaru,pBantu);
						cout<<"Lagi? (Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
			case 3: do{
						deleteQueue(Q,pHapus);
						traversal(Q);
						cout<<"Lagi? (Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
			default: cout<<"Maaf, pilihan tidak tersedia!";
				break;
		}
	}
	while(pilih!=0);
}
