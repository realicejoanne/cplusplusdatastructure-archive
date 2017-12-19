/*	Nama Program	: Pegawai - Searching, insert after, delete after
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 7 April 2017
	Deskripsi		: Singly List 2
*********************************************************************/

#include<iostream>
using namespace std;

struct pegawai{
	char nip[6];
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
void linearsearch(list& first, char key [12], int& found, pointer& cari){
	cout<<"Masukkan NIP yang dicari: ";
	cin>>key;
	
	found=0;
	cari=first;
	while(found==0&&cari!=NULL){
		if(strcmp(cari->nip,key)==0) found=1;
		else cari=cari->next;
	}
}
void insertafter(list& first, pointer cari, pointer peg){
	if (cari->next==NULL) cari->next=peg;
	else{
		peg->next=peg->next;
		cari->next=peg;
	}
}
void deleteafter(list& first, pointer cari, int& found){
	pointer hapus;
	if(cari->next==NULL){
		hapus=NULL;
		cout<<"Tidak ada yang dihapus."<<endl;
		found=0;
	}
	else {
		hapus=cari->next;
		cari->next=hapus->next;
		hapus->next=NULL;
	}
}
int main(){
	int x,found;
	list first;
	pointer peg,cari;
	char cek,key[12];
	
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
        cout<<"= 2. Insert after       ="<<endl;
        cout<<"= 3. Delete after       ="<<endl;
		cout<<"= 4. Searching          ="<<endl;
        cout<<"========================="<<endl;
        
		cout<<endl<<"Masukkan Pilihan: ";
		cin>>x;
        switch(x){
			case 0: return 0;
            case 1: traversal(first);
				break;
            case 2:	do{
						linearsearch(first,key,found,cari);
						if (found==1){
							cout<<"Data baru akan ditambah setelah data yang NIPnya ditemukan."<<endl;
							createelement(first);
							insertafter(first,cari,peg);
							cout<<endl<<"(Y/N)\t: ";
							cin>>cek;
						}
						else cout<<"Tidak ditemukan yang dicari."<<endl;
					}
					while(cek=='Y'||cek=='y');
                break;
            case 3: do{
						linearsearch(first,key,found,cari);
						if (found==1){
							cout<<"Data akan dihapus setelah data yang NIPnya ditemukan."<<endl;
							deleteafter(first,cari,found);
							cout<<endl<<"(Y/N)\t: ";
							cin>>cek;
						}
						else cout<<"Tidak ditemukan yang dicari."<<endl;
					}
					while(cek=='Y'||cek=='y');
				break;
			case 4: linearsearch(first,key,found,cari);
					if (found==1)cout<<"Ditemukan yang dicari yaitu: "<<peg->nama<<endl;
						else cout<<"Tidak ditemukan yang dicari."<<endl;
                break;
            default: cout<<"Maaf, pilihan tidak tersedia!";
        }
    }
    while(x!=0);
}
