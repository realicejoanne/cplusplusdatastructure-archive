#include<iostream>
using namespace std;

struct pegawai {
	char nip[5];
	char nama[10];
	int gol;
	pegawai* next;
};

typedef pegawai* pointer;
typedef pointer list;

void createlist(list& first){
	first=NULL;
}
void createelement(pointer& pBaru){
	pBaru=new pegawai;
	cout<<"NIP	: ";
	cin>>pBaru->nip;
	cout<<"Nama	: ";
	cin.ignore(10,'\n');
	cin.getline(pBaru->nama,10);
	cout<<"Gol	: ";
	cin>>pBaru->gol;
	pBaru->next=NULL;
}

void insertfirst(list& first, pointer& pBaru){
	if(first==NULL) first=pBaru;
	else {
		pBaru->next=first;
		first=pBaru;
	}
}

void insertlast(list& first, pointer& pBaru){
	if(first==NULL) first=pBaru;
	else { 
		pointer last;
		last=first;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void deletefirst(list& first, pointer& pHapus){
	if(first==NULL) {
		pHapus=NULL;
		cout<<"List kosong.";
	}
	else if(first->next==NULL){
		pHapus=first;
		first=NULL;
	}
	else {
		pHapus=first;
		first=first->next;
		pHapus->next=NULL;
	}
}

void cariratagajipeg(list first){
}

/*
int carigaji(int gol){
	int gaji;
	for(int j=0;j<n;j++){
		if(pegawai->gol==1) gaji==600000;
		else if(pegawai->gol==2) gaji==800000;
		else if(pegawai->gol==3) gaji==1000000;
		else gaji==0;
	}
	return gaji;
}
*/

void traversal(list first){
	pointer pBantu;
	if(first==NULL) cout<<"List kosong."<<endl;
	else {
		pBantu=first;
		cout<<"NIP\tNama\tGol\tGaji"<<endl;
		do{
		cout<<pBantu->nip<<"\t"<<pBantu->nama<<"\t"<<pBantu->gol<<endl;
		pBantu=pBantu->next;
	}
	while(pBantu!=NULL);
	}
}

int main(){
	int x;
	list first;
	pointer pBaru,pHapus;
	char cek;
	
	createlist(first);
	do{
		createelement(pBaru);
		insertfirst(first,pBaru);
		cout<<"(Y/N)\t: ";
		cin>>cek;
	}
	while(cek=='Y'||cek=='y');
	
	do{
		cout<<endl<<endl;
		cout<<"========================="<<endl;
		cout<<"= 0. Exit               ="<<endl;
		cout<<"= 1. Traversal          ="<<endl;
		cout<<"= 2. Insert last        ="<<endl;
		cout<<"= 3. Delete first       ="<<endl;
		cout<<"========================="<<endl;
			
		cout<<endl<<"Masukkan Pilihan: ";
		cin>>x;
		switch(x){
			case 0: return 0;
				
			case 1: traversal(first);
				break;
					
			case 2: do{
						createelement(pBaru);
						insertlast(first,pBaru);
						cout<<"Data baru berhasil ditambah di belakang."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
						
			case 3: do{
						deletefirst(first,pHapus);
						traversal(first);
						cout<<"Data pada baris terdepan berhasil dihapus."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
		}
	}
	while (x!=0);
}














