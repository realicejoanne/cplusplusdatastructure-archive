#include <iostream>
using namespace std;

struct Anak {
	char infoAnak;				
	Anak* nextAnak;	
};

struct Pegawai {
	char infoPeg;				
	Anak*    FirstAnak;	
	Pegawai*  next;		 
};

typedef Pegawai* pointerPeg;
typedef Anak*    pointerAnak;
	
typedef pointerPeg ListPeg;

void createListPeg(ListPeg& First) {
	First = NULL;
}

void createElementPeg(pointerPeg& pBaru) {
	pBaru = new Pegawai;					// alokasi
	cout<<"Masukkan info pegawai : ";
	cin>>pBaru->infoPeg;					// isi info
	pBaru->next = NULL;
	pBaru->FirstAnak = NULL;
}

void createElementAnak(pointerAnak& pBaru) {
	pBaru = new Anak;					// alokasi
	cout<<"Masukkan info anak : ";
	cin >> pBaru->infoAnak;					// isi info
	pBaru->nextAnak = NULL;
}

void insertFirstPeg(ListPeg& First, pointerPeg pBaru){
	// I.S List First mungkin kosong dan pBaru sudah terdefinisi
	// F.S List bertambah satu elemen di depan denganpBaru
	if (First==NULL) // kasus kosong
		First=pBaru;
	else {// kasus ada isi
		pBaru->next=First;// 1
		First=pBaru;// 2
	}
}

void insertFirstAnak(ListPeg& First, char key, pointerAnak pBaru){
	// I.S  List First mungkin kosong dan pBaru sudah terdefinisi
	// F.S  Elemen anak bertambah satu elemen di depan 
	
	pointerPeg pOrtu;
	int ketemu;
	
	cout<<"Insert First Anak"<<endl;
	//  linearSearch(First,key,ketemu,pOrtu);
	pOrtu = First;
	ketemu = 0;
	while(pOrtu !=NULL && ketemu==0) {   	//!ketemu
		if (pOrtu->infoPeg==key)
			ketemu=1;
		else
			pOrtu=pOrtu->next;
	}
	//----------------------------------------------
	if (ketemu){                   		 // (ketemu==1)
		cout<<"Ditemukan"<<endl;
		if (pOrtu->FirstAnak==NULL){
			pOrtu->FirstAnak=pBaru;
		}
		else {
			pBaru->nextAnak=pOrtu->FirstAnak;
			pOrtu->FirstAnak=pBaru;
		}
	}
	else{
		cout<<"Tidak ditemukan"<<endl;
	}
}

void deleteFirstAnak(ListPeg& First, char key, pointerAnak& pHapus){
	// I.S List First mungkin kosong
	// F.S. List anak berkurang didepan, yg dihapus dikembalikan
	
	pointerPeg pOrtu;
	int ketemu;
	cout<<"Delete First Anak"<<endl;
	pOrtu=First;
	ketemu=0;
	while (pOrtu !=NULL && ketemu==0) {
		if (pOrtu->infoPeg==key)
			ketemu=1;
		else
			pOrtu=pOrtu->next;
	}
	
	if(ketemu) {
		if (pOrtu->FirstAnak==NULL){    // kosong
		pHapus=NULL;
		cout<<"List kosong, tidak ada hapus"<<endl;
		}
		
		else if (pOrtu->FirstAnak->nextAnak==NULL){         
			//isi 1 elemen
      		pHapus=pOrtu->FirstAnak;
      		pOrtu->FirstAnak=NULL;
		}
		
		else {                       // isi > 1 elemen
			pHapus=pOrtu->FirstAnak;
      		pOrtu->FirstAnak=pOrtu->FirstAnak->nextAnak;
      		pHapus->nextAnak=NULL;
		}
	}
	else{
        cout<<"Tidak ditemukan"<<endl;
	}
}

void traversalOrtuAnak(ListPeg First){
	pointerPeg  pBantuPeg;
    pointerAnak pBantuAnak;

	cout<<"Traversal Pegawai"<<endl;
    pBantuPeg=First;
    while (pBantuPeg!=NULL){             //loop ortu
		cout<<pBantuPeg->infoPeg <<endl;
        pBantuAnak=pBantuPeg->FirstAnak;
        
		while (pBantuAnak!=NULL) {       //loop anak
             cout<<"     "<<pBantuAnak->infoAnak <<endl;
             pBantuAnak=pBantuAnak->nextAnak;
        }
		
        pBantuPeg=pBantuPeg->next;           
    }
}


int main(){
	pointerPeg p;
	pointerAnak a;
	ListPeg pegawai;
	char key;
	createListPeg(pegawai);
	
	createElementPeg(p);			//W
	insertFirstPeg(pegawai, p);
	
	createElementAnak(a);				//A
	insertFirstAnak(pegawai,'W', a);
	createElementAnak(a);				//B
	insertFirstAnak(pegawai, 'W', a);
	
	createElementPeg(p);			//X
	insertFirstPeg(pegawai, p);
	createElementAnak(a);				//C
	insertFirstAnak(pegawai, 'X', a);
	createElementAnak(a);				//D
	insertFirstAnak(pegawai, 'X', a);
	
	traversalOrtuAnak(pegawai);

}
