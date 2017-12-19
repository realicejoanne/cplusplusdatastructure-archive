#include<iostream>
using namespace std;

struct pegawai {
	char nip[5];
	char nama[10];
	int gol;
	pegawai* next;
	pegawai* prev;
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
	pBaru->prev=NULL;
}

void insertfirst(list& first, pointer& pBaru){
	if(first=NULL) first=pBaru;
	else {
		pBaru->next=first;
		first->prev=pBaru;
	}
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
void linearsearch(list& first, int& found, pointer& pCari){
	char key[12];
	cout<<"Masukkan NIP yang ingin didelete: ";
	cin>>key;
	
	found=0;
	pCari=first;
	while(found==0&&pCari!=NULL){
		if(strcmp(pCari->nip,key)==0) found=1;
		else pCari=pCari->next;
	}
}
void deletePCari(list& first, pointer& pCari){
	if(first->next==NULL){
		pCari=first;
		first=NULL;
	}
	else if(pCari==first){
		first=first->next;
		pCari->next=NULL;
		
	}
	else if(pCari->next==NULL){
		pointer before;
		before=first;
		while(before->next!=pCari) before=before->next;
		before->next=NULL;
	}
	else{
		pointer before;
		before=first;
		while(before->next!=pCari) before=before->next;
		before->next=pCari->next;
		pCari->next=NULL;
	}
}

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
	int x,found;
	list first;
	pointer pBaru,pHapus,pCari;
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
		cout<<"= 2. LinearSearch       ="<<endl;
		cout<<"= 3. DeletePCari        ="<<endl;
		cout<<"========================="<<endl;
			
		cout<<endl<<"Masukkan Pilihan: ";
		cin>>x;
		switch(x){
			case 0: return 0;
				
			case 1: traversal(first);
				break;
			case 2: linearsearch(first,found,pCari);
				break;
			case 3: do{
						linearsearch(first,found,pCari);
						if(found==1) deletePCari(first,pCari);
						else cout<<"NIP tidak ditemukan."<<endl<<endl;
						traversal(first);
						}
						while(cek=='Y'||cek=='y');
				break;
		}
	}
	while (x!=0);
}