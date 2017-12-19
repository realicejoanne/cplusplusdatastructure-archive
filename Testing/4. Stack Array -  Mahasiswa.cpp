/* bisa gak nama npm di satu row stack? */

#include<iostream>
using namespace std;

const int maxElemen = 255; //maksimal tumpukan

struct mhs{
	char nama[10];
	char npm[8];
};

struct stack{
	mhs isi[maxElemen];
	int top;
};
stack s;

void createStack(stack& s){
	s.top=-1;
}

void createElement(mhs& baru){
	cout<<"Masukkan nama: ";
	cin>>baru.nama;
	cout<<"Masukkan NPM: ";
	cin>>baru.npm;
}

void push(stack& s, mhs baru){
	if(s.top==maxElemen-1){
		cout<<"Tumpukan sudah penuh."<<endl;
	}
	else {
		s.top=s.top+1;
		s.isi[s.top]=baru;
	}
}

void pop(stack& s, mhs& hapus){
	if(s.top<0){
		cout<<"Tumpukan sudah kosong."<<endl;
	}
	else {
		hapus=s.isi[s.top];
		for(int i=0;i<maxElemen;i++){
			s.isi[maxElemen] = s.isi[maxElemen+1];
		}
		s.top=s.top-1;
	}
}

void cetakStack(stack s){
	int i=0;
	cout<<"Nama\tNPM"<<endl;
	/*while(s.top!=maxElemen-1){
		cout<<s.isi[i].nama<<"\t"<<s.isi[i].npm<<endl;
		i++;
	}*/
	for(int i=s.top;i>=0;i--){
		cout<<s.isi[i].nama<<"\t"<<s.isi[i].npm<<endl;
	}
}

int main(){
	stack s;
	mhs baru,hapus;
	createStack(s);
	int pilih;
	do{
		cout<<"         Menu         "<<endl;
		cout<<"----------------------"<<endl;
		cout<<"1. Insert Mahasiswa"<<endl;
		cout<<"2. Delete Mahasiswa"<<endl;
		cout<<"3. Cetak Mahasiswa"<<endl;
		cout<<"0. Keluar"<<endl;
		
		cout<<endl<<"Masukkan pilihan: ";
		cin>>pilih;
		
		switch(pilih){
			case 1: {
				createElement(baru);
				push(s,baru);
				cout<<"Mahasiswa berhasil ditambah"<<endl<<endl;
				}
				break;
			case 2: {
				pop(s,hapus);
				cout<<"Mahasiswa berhasil dihapus"<<endl<<endl;
				}
				break;
			case 3: {
				cetakStack(s);
				cout<<endl;
				}
				break;
		}
	}
	while(pilih!=0);
}