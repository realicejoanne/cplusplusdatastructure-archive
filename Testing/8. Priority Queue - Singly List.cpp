//bug pada program ini ada pada insert dimana tdk bs input 275 tp bs 527, jd intinya pBaru hrs lebih kecil/lebih besar dr q.head

#include<iostream>
using namespace std;

struct mhs{
	char nama[10];
	int prior;
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
	do{
		cout<<"Prioritas: ";
		cin>>pBaru->prior;
		if (pBaru->prior<1||pBaru->prior>10){
			cout<<"ERROR! Masukkan Angka 1-10"<<endl<<endl;
		}
	}
	while(pBaru->prior<1||pBaru->prior>10);
	pBaru->next=NULL;
}

void insertQueue(queue& q,pointer pBaru){
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

void cetakQueue(queue q){
	if (q.head==NULL){
		cout<<"Data kosong tidak ada yang dihapus";
	}
	else{
		pointer pBantu;
		pBantu=q.head;
		cout<<"Nama\tPrioritas"<<endl;
		cout<<"=================="<<endl;
		do{
			cout<<pBantu->nama;
			cout<<"\t";
			cout<<pBantu->prior<<endl;
			pBantu=pBantu->next;
		}while(pBantu!=NULL);
	}
}

int main(){
	queue q;
	pointer pBaru, pHapus;
	
	createQueue(q);
	int pilih;
	do{
		cout<<"  Menu Daftar Mhs  "<<endl;
		cout<<"------------------------"<<endl;
		cout<<"1. Insert Mhs"<<endl;
		cout<<"2. Delete Mhs"<<endl;
		cout<<"3. Cetak Antrian"<<endl;
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




