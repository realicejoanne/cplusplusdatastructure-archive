/*	Nama Program	: Pegawai - Traversal, insert first, insert last, delete first, delete last
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 7 April 2017
	Deskripsi		: Singly List 1
************************************************************************************************/

#include<iostream>
using namespace std;

struct pegawai{
	char nip[4];
	char nama[20];
	char alamat[40];
	int gol;
	int gaji;
	pegawai* next;
};

typedef pegawai* pointer;
typedef pointer list;

void createlist(list& first){
	first=NULL;
}
void createelement(pointer& peg){
	peg=new pegawai;
	cout<<"Masukkan NIP (10xx)\t: ";
	cin>>peg->nip;
	cout<<"Masukkan nama pegawai\t: ";
	cin.ignore(20,'\n');
	cin.getline(peg->nama,20);
	cout<<"Masukkan alamat rumah\t: ";
	//cin.ignore(40,'\n');
	cin.getline(peg->alamat,40);
	cout<<"Masukkan golongan\t: ";
	cin>>peg->gol;
	cout<<"Masukkan gaji (Rp)\t: ";
	cin>>peg->gaji;
	peg->next=NULL;
}
void insertfirst(list& first, pointer peg){
	if(first==NULL) first=peg;
		else peg->next=first;
		first=peg;
}
void traversal(list& first){
	pointer bantu;
	if(first==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		bantu=first;
		cout<<endl<<"NIP\tNama\tAlamat\t\tGol\tGaji";
		cout<<endl<<"-------------------------------------------------------"<<endl;
		do{
			cout<<bantu->nip<<"\t"<<bantu->nama<<"\t"<<bantu->alamat<<"\t\t"<<bantu->gol<<"\t"<<bantu->gaji<<endl;
			bantu=bantu->next;
		} 
		while(bantu!=NULL);
	}
}
void insertdepan(list& first, pointer peg){
	peg->next=first;
	first=peg;
}
void insertbelakang(list& first, pointer peg){
	pointer last=first;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=peg;
}
void deletedepan(list& first, pointer peg){
	pointer delf=first;
	first=first->next;
	delf->next=NULL;
}
void deletebelakang(list& first, pointer peg){
	pointer dell=first;
	while(dell->next!=NULL){
		dell=dell->next;
	}
}
int main(){
	int x;
	list first;
	pointer peg;
	char cek;
	
	cout<<"Data Pegawai PT. Kerja Lembur Setiap Hari 2017"<<endl;
	cout<<"=============================================="<<endl<<endl;
	
	createlist(first);
	do{
		createelement(peg);
		insertfirst(first,peg);
		cout<<"(Y/N)\t: ";
		cin>>cek;
	}
	while(cek=='Y'||cek=='y');

	do{
		cout<<endl<<endl;
        cout<<"========================="<<endl;
        cout<<"=  PROGRAM SINGLY LIST  ="<<endl;
        cout<<"========================="<<endl;
		cout<<"= 0. Exit               ="<<endl;
        cout<<"= 1. Traversal          ="<<endl;
        cout<<"= 2. Insert first       ="<<endl;
        cout<<"= 3. Insert last        ="<<endl;
        cout<<"= 4. Delete first       ="<<endl;
        cout<<"= 5. Delete last        ="<<endl;
        cout<<"========================="<<endl;
        
		cout<<endl<<"Masukkan Pilihan: ";
		cin>>x;
        switch(x){
			case 0: return 0;
            case 1: traversal(first);
                break;
            case 2: do{
						createelement(peg);
						insertdepan(first,peg);
						cout<<"Data baru berhasil ditambah di depan."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
                break;
            case 3: do{
						createelement(peg);
						insertbelakang(first,peg);
						cout<<"Data baru berhasil ditambah di belakang."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
				break;
            case 4: do{
						deletedepan(first,peg);
						cout<<"Data pada baris terdepan berhasil dihapus."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
                break;
            case 5: do{
						deletebelakang(first,peg);
						cout<<"Data pada baris terbelakang berhasil dihapus."<<endl<<"(Y/N)\t: ";
						cin>>cek;
					}
					while(cek=='Y'||cek=='y');
                break;
            default: cout<<"Maaf, pilihan tidak tersedia!";
        }
    }
    while(x!=0);
}
