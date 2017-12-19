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

void insertLastDiv(ListDiv& first, pointerDiv pBaru){
	pointerDiv last;
	if (first==NULL){
		first=pBaru;
	}
	else {
		last=first;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void deleteFirstDiv(ListDiv& first, pointerDiv& pHapus){
	if (first==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (first->next==NULL){
		pHapus=first;
		first=NULL;
	}
	else {
		pHapus=first;
		first=first->next;
		pHapus->next=NULL;
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

void insertFirstAnggota(ListDiv& first, pointerPeg pBaru, char key[10]){
	pointerDiv pDiv;
	int ketemu=0;
	
	pDiv=first;
	while(pDiv!=NULL && ketemu==0){
		if (strcmp(pDiv->infoDiv,key)==0){
			ketemu=1;
		}
		else pDiv=pDiv->next;
	}
	
	if (ketemu){
		if (pDiv->firstPeg==NULL){
			pDiv->firstPeg=pBaru;
		}
		else {
			pBaru->nextPeg=pDiv->firstPeg;
			pDiv->firstPeg=pBaru;
		}
	}
	else{
		cout<<"Tidak ditemukan"<<endl;
	}
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

void deleteLastAnggota(ListDiv& first, pointerPeg& pHapus, char key[10]){
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
		pointerPeg last,precLast;
		if (pDiv->firstPeg==NULL){ // kosong
			pHapus=NULL;
			cout<<"List kosong, tidak ada yang dihapus"<<endl;
		}
		else if(pDiv->firstPeg->nextPeg==NULL){ //isi 1 elemen
			pHapus=pDiv->firstPeg;
			pDiv->firstPeg=NULL;
		}
		else { // isi > 1 elemen
			last=pDiv->firstPeg;
			precLast=NULL;
			while (last->nextPeg!=NULL){
				precLast=last;
				last=last->nextPeg;
			}
			pHapus=last;
			precLast->nextPeg=NULL;
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
	cout<<"Divisi\tNPM\tNama Anggota"<<endl;
    pBantuDiv=first;
    while (pBantuDiv!=NULL){
		cout<<pBantuDiv->infoDiv<<"\t";
        		pBantuPeg=pBantuDiv->firstPeg;
        
		while (pBantuPeg!=NULL){
			cout<<pBantuPeg->npm<<"\t";
			cout<<pBantuPeg->infoPeg<<endl<<"\t";
			pBantuPeg=pBantuPeg->nextPeg;
        }
		
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
		cout<<"1. Insert First Divisi"<<endl;
		cout<<"2. Insert Last Divisi"<<endl;
		cout<<"3. Delete First Divisi"<<endl;
		cout<<"4. Delete Last Divisi"<<endl;
		cout<<"5. Insert First Anggota"<<endl;
		cout<<"6. Insert Last Anggota"<<endl;
		cout<<"7. Delete First Anggota"<<endl;
		cout<<"8. Delete Last Anggota"<<endl;
		cout<<"9. Cetak Divisi"<<endl;
		cout<<"10. Cetak Divisi + Anggota"<<endl;
		cout<<"11. Cari NPM Anggota"<<endl;
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
			createElmtDiv(d);
			insertLastDiv(first,d);
			cout<<endl<<"Divisi baru berhasil ditambah."<<endl;
			break;
		case 3:
			deleteFirstDiv(first,d);
			cout<<endl<<"Divisi terakhir berhasil dihapus."<<endl;
			break;
		case 4:
			deleteLastDiv(first,d);
			cout<<endl<<"Divisi terakhir berhasil dihapus."<<endl;
			break;
		case 5:
			cout<<"Masukkan divisi: "; 
			cin>>key;
			createElmtAnggota(p);
			insertFirstAnggota(first,p,key);
			cout<<endl<<"Anggota baru berhasil ditambah."<<endl;
			break;
		case 6:
			cout<<"Masukkan divisi: "; 
			cin>>key;
			createElmtAnggota(p);
			insertLastAnggota(first,p,key);
			cout<<endl<<"Anggota baru berhasil ditambah."<<endl;
			break;
		case 7:
			cout<<"Masukkan divisi: "; 
			cin>>key;
			deleteFirstAnggota(first,p,key);
			cout<<endl<<"Anggota pertama berhasil dihapus."<<endl;
			break;
		case 8:
			cout<<"Masukkan divisi: "; 
			cin>>key;
			deleteLastAnggota(first,p,key);
			cout<<endl<<"Anggota pertama berhasil dihapus."<<endl;
			break;
		case 9:
			traversalDiv(first);
			break;
		case 10:
			traversalDivAnggota(first);
			break;
		case 11:
			linearSearch(first,cari,d);
			break;
		}
		cout<<endl;
	}
	while(pilih!=0);
}
