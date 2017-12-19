/*
Nama Program		: Program Latihan Operasi Dasar Singly Linked List
Tanggal				: 05 April 2017
Nama				: Eko Fajar Putra
NPM					: 140810160061
Deskripsi			: Program modular latihan operasi dasar singly linked list 2 halaman 11 No 1
*********************************************/
#include <iostream>
#include <conio.h>
using namespace std;

struct ElemtList{
	char nip[14];
	char nama[20];
	char alamat[30];
	int gol;
	int gaji;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer list;

void banyakData(int& n){
	cout<<"Banyak data : "; cin>>n;
}

void createList(list& first){
	first = NULL;
}

void createElmt(pointer& pBaru){
	pBaru = new ElemtList;		//Alokasi
	cout<<"Masukkan NIP : "; cin>>pBaru->nip;
	cout<<"Masukkan Nama : "; cin.ignore(); cin.getline(pBaru->nama, 18);
	cout<<"Masukkan Alamat : "; cin.ignore(); cin.getline(pBaru->alamat, 25);
	cout<<"Masukkan Golongan : "; cin>>pBaru->gol;
	cout<<"Masukkan Gaji : "; cin>>pBaru->gaji;
	pBaru->next = NULL;
}

void insertFirst(list& first, pointer pBaru){
// I.S List First mungkin kosong dan pBaru sudah terdefinisi
// F.S List bertambah satu elemen di depan denganpBaru
	
	if(first==NULL)		// kasus kosong
		first = pBaru;
	
	else{		// kasus ada isi
		pBaru->next = first;// 1
		first = pBaru;// 2
	}
}

void traversal(list first){
	pointer pBantu;
	if (first==NULL) {
		cout<<"List kosong"<<endl;
	}
	else {
		pBantu = first;		//Catat elemen pertama
		do {
			cout<<"NIP : "<<pBantu->nip<<endl;
			cout<<"Nama : "<<pBantu->nama<<endl;
			cout<<"Alamat : "<<pBantu->alamat<<endl;
			cout<<"Golongan : "<<pBantu->gol<<endl;
			cout<<"Gaji : "<<pBantu->gaji<<endl<<endl;		//Proses cetak
			pBantu = pBantu->next;		//Pindah ke berikutnya
		} while(pBantu != NULL);
	}
}

void linearSearch(list First, char key[12], int& found, pointer& pCari){
	found = 0; // belum ditemukan
	pCari = First; // pencarian mulai dari elemen pertama
	while (found==0 && pCari != NULL) {
		if (strcmp(pCari->nip, key) == 0)
			found=1;
		else
			pCari=pCari->next;
	}
}

void deletePCari(list& First, pointer& pCari){	
	if(First->next == NULL ){		//Jika First Berisi 1 Elemen
		pCari = First;
		First = NULL;
	}
	
	else if(pCari == First ){		//Jika Elemen Berada pada posisi First
		First = First -> next;
		pCari -> next = NULL;
		
	}
	else if(pCari->next == NULL){		//Jika Pencarian berada pada posisi Last
		pointer pBefore;
		pBefore = First ;
		while (pBefore->next != pCari)
			pBefore = pBefore->next;
		pBefore->next = NULL;
	}
	
	else{		//Jika elemen lebih dari 1
		pointer pBefore;
		pBefore = First ;
		while ( pBefore->next != pCari)
			pBefore = pBefore->next;
		pBefore->next = pCari->next ;
		pCari->next = NULL ;
	}
	
}

int main(){
	int n, ketemu;
	char kunci[12];
	pointer p, pCari;
	list listPegawai;
	
	createList(listPegawai);		//List kosong
	cout<<"\t\tInsert First\n";
	cout<<"============================================\n";
	banyakData(n);
	for(int i=0; i<n; i++){
		createElmt(p);
		insertFirst(listPegawai, p);
		cout<<endl;
	}
	traversal(listPegawai);
	
	cout<<"============================================\n";
	cout<<"\t\tDelete pCari\n";
	cout<<"============================================\n";
	cout<<"NIP yang ingin di-delete : "; cin >>kunci;
	linearSearch(listPegawai, kunci, ketemu, pCari);
	if (ketemu) {
		deletePCari(listPegawai, pCari);
	}
	else {
		cout<<"Data tidak ditemukan"<<endl<<endl;
	}
	
	cout<<"============================================\n";
	cout<<"\tData setelah delete pCari\n";
	cout<<"============================================\n";
	traversal(listPegawai);
	cout<<"Selesai";
	getch();
	
}
