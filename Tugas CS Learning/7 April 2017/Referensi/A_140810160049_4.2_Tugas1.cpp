/**************************************************************
Nama Program	: Delete pSearching
Nama			: Adryan Luthfi Faiz
NPM				: 140810160049
Tanggal Buat	: 6 April 2017
Deskripsi		: Menghapus Data Pegawai Berdasarkan Pencarian NIP
***************************************************************/

#include <iostream>
#include <Windows.h>
#include <String.h>
using namespace std;

// Tugas 4.2 Latihan 1

struct pegawai {
	char nip [12];
	char nama [15];
	char alamat [30];
	int gol ;
	pegawai* next ;			// pointer next sebagai pengait
};

typedef pegawai* pointer;
typedef pointer List;

void CreateList (List& First){
	First = NULL;
}

void CreateElement (pointer& pBaru){
	pBaru = new pegawai;
	cout<<"NIP\t\t: ";cin >> pBaru -> nip;
	cout<<"Nama\t\t: ";cin >> pBaru -> nama;
	cout<<"Alamat\t\t: ";cin >> pBaru -> alamat;
	do {
		cout<<"Golongan\t: ";cin >> pBaru -> gol;
		if (pBaru -> gol < 0 || pBaru -> gol > 4 )
			cout<<"ERROR , Masukkan Gol Antara 1-4 "<<endl<<endl;
	} while (pBaru -> gol < 0 || pBaru -> gol > 4 );
	pBaru -> next = NULL;
}

int gaji (int n){
	switch (n){
		case 1 : return 2000000 ; break;
		case 2 : return 3000000 ; break;
		case 3 : return 5000000 ; break;
		case 4 : return 8000000 ; break;
	}
}

void traversal (List First){
	pointer pBantu;
	if (First == NULL)			// Kasus kosong
		cout<<"List Kosong"<<endl;
	else {
		pBantu = First ;
		do {
			cout<<"NIP\t\t: "<< pBantu -> nip <<endl;
			cout<<"Nama\t\t: "<< pBantu -> nama <<endl;
			cout<<"Alamat\t\t: "<< pBantu -> alamat <<endl;
			cout<<"Golongan\t: "<< pBantu -> gol <<endl;
			cout<<"Gaji\t\t: "<< gaji (pBantu -> gol) <<endl;
			cout<<endl;
			pBantu = pBantu -> next;
		} while (pBantu != NULL);
	}
}

void InsertFirst (List& First , pointer pBaru ){
	
	if ( First == NULL)			// List Kosong
		First = pBaru ;
	else {						// Kasus ada isi
		pBaru -> next = First;
		First = pBaru;
	}
}


void DeletePCari ( List& First , pointer& pCari){
	
	if (First -> next == NULL ){		// Jika First Berisi 1 Elemen
		pCari = First;
		First = NULL;
	}
	
	else if ( pCari == First ){			// Jika Elemen Berada pada posisi First
		First = First -> next;
		pCari -> next = NULL;
		
	}
	else if ( pCari -> next == NULL){	// Jika Pencarian berada pada posisi Last
		pointer pBefore;
		pBefore = First ;
		while ( pBefore -> next != pCari)
			pBefore = pBefore -> next;
		pBefore -> next = NULL;
	}
	
	else{								// Jika elemen lebih dari 1
		pointer pBefore;
		pBefore = First ;
		while ( pBefore -> next != pCari)
			pBefore = pBefore -> next;
		pBefore -> next = pCari -> next ;
		pCari -> next = NULL ;
	}
	
}

void linearSearch (List& First, char key [12] , int& found, pointer& pCari){
	found=0; 				// belum ditemukan
	pCari=First; 			// Mencari NIP
	while (found==0 && pCari!=NULL) {
		if ( strcmp (pCari-> nip , key ) == 0 ) // Membandingkan , jika sama maka bernilai 0
			found=1;
		else
			pCari=pCari->next;
	}
	if ( found == 1 ) DeletePCari (First , pCari);
}

main(){
	pointer p;
	List Pegawai;
	int n;
	char key [12];
	int found ;
	
	CreateList (Pegawai);		// Element kosong
	
	cout<<"Masukkan Banyak Data : "; cin>>n;
	cout<<endl;
	
	for (int i = 0 ; i < n ; i++){
		cout<<"Data ke-"<< i+1 <<endl;
		CreateElement (p);		
		InsertFirst ( Pegawai , p );
		cout<<endl;
	}
	
	system("cls");
	cout<<endl;
	cout<<"==== DATA ===="<<endl;
	traversal ( Pegawai );		// Menayangkan dari Last ke First
	cout<<endl<<endl;
	cout<<"Masukkan Data NIP Yang Ingin Dihapus : "; cin>>key;
	linearSearch ( Pegawai , key , found, p);
	if (found == 0) cout<<endl<<" Data Tidak Ditemukan " <<endl<<endl;
	else {
		system("cls");
		cout<<endl;
		cout<<"==== DATA ===="<<endl;
		traversal ( Pegawai );
	}

	
}
