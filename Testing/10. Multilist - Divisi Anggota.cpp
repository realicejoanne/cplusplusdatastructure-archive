/* 	Nama program	: Daftar Pegawai + Divisinya
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 02-06-17
	Deskripsi		: Multilist
************************************************************/

#include <iostream>
#include<string.h>
using namespace std;

struct pegawai{
	int npm;
	char infoPeg[10];
	pegawai* nextPeg;	
};

struct divisi{
	char infoDiv[10];				
	pegawai* firstPeg;	
	divisi* next;		 
};

typedef divisi* pointerDiv;
typedef pegawai* pointerPeg;
	
typedef pointerDiv ListDiv;

void createListDiv(ListDiv& first){
	first = NULL;
}

void createElmtDiv(pointerDiv& pBaru){
	pBaru = new divisi;
	cout<<"Nama divisi: ";
	cin>>pBaru->infoDiv;
	pBaru->next = NULL;
	pBaru->firstPeg = NULL;
}

void createElmtAnggota(pointerPeg& pBaru) {
	pBaru = new pegawai;
	cout<<"NPM anggota: ";
	cin>>pBaru->npm;
	cin.ignore();
	cout<<"Nama anggota: ";
	cin.getline(pBaru->infoPeg,10);
	pBaru->nextPeg = NULL;
}

void traversalDiv(ListDiv first){
	pointerDiv pBantu=first;
	int x=1;
	cout<<"Daftar divisi yang ada: "<<endl;
	while (pBantu!= NULL){
		cout<<x++<<". "<<pBantu->infoDiv<<endl;
		pBantu=pBantu->next;
	}
}

void insertFirstDiv(ListDiv& first, pointerDiv pBaru){
	if (first==NULL) first=pBaru;
	else { // kasus ada isi
		pBaru->next=first;// 1
		first=pBaru;// 2
	}
}

void deleteLastDiv(ListDiv& first, pointerDiv& pHapus){
	pointerDiv last,precLast;
	if (first==NULL){ // kosong
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (first->next==NULL){ //isi 1 elemen
		pHapus=first;
		first=NULL;
	}
	else { // isi > 1 elemen
		last=first;
		precLast=NULL;
		while (last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

void linearSearch(ListDiv& first, int cari, pointerDiv& pCari){
	pCari = first;
	int ketemu = 0;
	cout<<"NPM yang dicari: ";
	cin>>cari;
	while(pCari!=NULL && ketemu==0){
		if (pCari->firstPeg->npm==cari){
			ketemu=1;
		}
		else pCari=pCari->next;
	}
	if (ketemu==1){
		cout<<"NPM ditemukan."<<endl;
	}
	else cout<<"Tidak ditemukan NPM yang dicari."<<endl;
}

void insertLastAnggota(ListDiv& first, pointerPeg pBaru, char key[10]){
	pointerDiv pDiv;
	int ketemu=0;
	pDiv = first;
	
	while(pDiv!=NULL && ketemu==0){
		if (strcmp(pDiv->infoDiv,key)==0){
			ketemu=1;
		}
		else pDiv=pDiv->next;
	}
	
	if(ketemu){
		cout<<"Ditemukan"<<endl;
		if (pDiv->firstPeg==NULL){
			pDiv->firstPeg=pBaru;
		}
		else {
			while (pDiv->firstPeg->nextPeg!=NULL){
				pDiv->firstPeg=pDiv->firstPeg->nextPeg;
			}
			pDiv->firstPeg->nextPeg=pBaru;
		}
	}
	else{
		cout<<"Tidak ditemukan"<<endl;
	}
}

void deleteFirstAnggota(ListDiv& first, pointerPeg& pHapus, char key[10]){
	pointerDiv pDiv;
	int ketemu=0;
	pDiv = first;
	
	while(pDiv!=NULL && ketemu==0){
		if (strcmp(pDiv->infoDiv,key)==0){
			ketemu=1;
		}
		else pDiv=pDiv->next;
	}
	
	if(ketemu){
		if (pDiv->firstPeg==NULL){    // kosong
			pHapus=NULL;
			cout<<"List kosong, tidak ada yang dihapus"<<endl;
		}
		else if (pDiv->firstPeg->nextPeg==NULL){   //isi 1 elemen
      		pHapus=pDiv->firstPeg;
      		pDiv->firstPeg=NULL;
		}
		else {		// isi > 1 elemen
			pHapus=pDiv->firstPeg;
      		pDiv->firstPeg=pDiv->firstPeg->nextPeg;
      		pHapus->nextPeg=NULL;
		}
	}
	else{
        cout<<"Tidak ditemukan"<<endl;
	}
}

void traversalDivAnggota(ListDiv first){
	pointerDiv pBantuDiv;
    pointerPeg pBantuPeg;

	cout<<"Daftar Lengkap Divisi dan Anggotanya"<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"Divisi\tNPM Anggota\tNama Anggota"<<endl;
    pBantuDiv=first;
    while (pBantuDiv!=NULL){
		cout<<pBantuDiv->infoDiv<<"\t";
        pBantuPeg=pBantuDiv->firstPeg;
        
		while (pBantuPeg!=NULL){
			cout<<pBantuPeg->npm<<"\t";
			cout<<pBantuPeg->infoPeg;
			pBantuPeg=pBantuPeg->nextPeg;
        }
		cout<<endl<<"\t\t";
		
        pBantuDiv=pBantuDiv->next;
		cout<<endl;
    }
}

int main(){
	cout<<"Susunan Kepanitiaan Technopreneur 2017"<<endl;
	cout<<"--------------------------------------"<<endl<<endl;
	
	pointerDiv d;
	pointerPeg p;
	ListDiv first;
	char key[10];
	int cari;
	
	createListDiv(first);
	int pilih;
	do{
		cout<<"Pilihan Menu"<<endl;
		cout<<"------------"<<endl;
		cout<<"1. Insert Divisi"<<endl;
		cout<<"2. Delete Divisi"<<endl;
		cout<<"3. Insert Anggota"<<endl;
		cout<<"4. Delete Anggota"<<endl;
		cout<<"5. Cetak Divisi"<<endl;
		cout<<"6. Cetak Divisi + Anggota"<<endl;
		cout<<"7. Cari NPM Anggota"<<endl;
		cout<<"0. Keluar"<<endl;
		
		cout<<endl<<"Masukkan pilihan: ";
		cin>>pilih;
		
		switch(pilih){
		case 1:
			createElmtDiv(d);
			insertFirstDiv(first,d);
			cout<<endl<<"Divisi baru berhasil ditambah."<<endl;
			break;
		case 2:
			deleteLastDiv(first,d);
			cout<<endl<<"Divisi terakhir berhasil dihapus."<<endl;
			break;
		case 3:
			cout<<"Masukkan divisi: "; 
			cin>>key;
			createElmtAnggota(p);
			insertLastAnggota(first,p,key);
			cout<<endl<<"Anggota baru berhasil ditambah."<<endl;
			break;
		case 4:
			cout<<"Masukkan divisi: "; 
			cin>>key;
			deleteFirstAnggota(first,p,key);
			cout<<endl<<"Anggota pertama berhasil dihapus."<<endl;
			break;
		case 5:
			traversalDiv(first);
			break;
		case 6:
			traversalDivAnggota(first);
			break;
		case 7:
			linearSearch(first,cari,d);
			break;
		}
		cout<<endl;
	}
	while(pilih!=0);
}
