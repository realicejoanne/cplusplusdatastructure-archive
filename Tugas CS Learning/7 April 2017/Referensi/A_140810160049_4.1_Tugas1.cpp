/**************************************************************
Nama Program	: Data Menentukan Kelulusan
Nama			: Adryan Luthfi Faiz
NPM				: 140810160049
Tanggal Buat	: 5 April 2017
Deskripsi		: Menentukan Kelulusan Mahasiswa Dari Nilai Yang Didapat
***************************************************************/


#include <iostream>
#include <Windows.h>
using namespace std;

// Tugas 4.1 Latihan 1 

struct ElementList {
	char npm [12];
	char nama [15];
	int nilai;
	ElementList* next ;			// pointer next sebagai pengait
};

typedef ElementList* pointer;
typedef pointer List;

void CreateList (List& First){
	First = NULL;
}

void CreateElement (pointer& pBaru){
	pBaru = new ElementList;
	cout<<"NPM\t: ";cin >> pBaru -> npm;
	cout<<"Nama\t: ";cin >> pBaru -> nama;
	do {
		cout<<"Nilai\t: ";cin >> pBaru -> nilai;
		if (pBaru -> nilai <= 0 || pBaru -> nilai >= 100 )
			cout<<"ERROR , Masukkan Antara 0 - 100"<<endl<<endl;
	} while (pBaru -> nilai <= 0 || pBaru -> nilai >= 100 );
	pBaru -> next = NULL;
}

void InsertFirst (List& First , pointer pBaru ){
	
	if ( First == NULL)			// List Kosong
		First = pBaru ;
	else {						// Kasus ada isi
		pBaru -> next = First;
		First = pBaru;
	}
}

void traversal (List First){
	pointer pBantu;
	if (First == NULL)			// Kasus kosong
		cout<<"List Kosong"<<endl;
	else {
		pBantu = First ;
		do {
			cout<<"NPM\t\t: "<< pBantu -> npm <<endl;
			cout<<"Nama\t\t: "<< pBantu -> nama <<endl;
			cout<<"Nilai\t\t: "<< pBantu -> nilai <<endl;
			cout<<"Keterangan\t: ";
			if (pBantu -> nilai >= 60) cout<<"LULUS";
			else cout <<"TIDAK LULUS";
			cout<<endl<<endl;
			pBantu = pBantu -> next;
		} while (pBantu != NULL);
		
	}
}

main(){
	pointer p;
	List Mhs;
	int n;
	
	CreateList (Mhs);		// Element kosong
	
	cout<<"Masukkan Banyak Data : "; cin>>n;
	cout<<endl;
	
	for (int i = 0 ; i < n ; i++){
		cout<<"Data ke-"<< i+1 <<endl;
		CreateElement (p);		
		InsertFirst ( Mhs , p );
		cout<<endl;
	}
	system("cls");
	cout<<endl;
	cout<<"==== DATA ===="<<endl;
	traversal ( Mhs );		// Menayangkan dari Last ke First
}


