#include<iostream>
using namespace std;

struct pegawai {
	char nip[5];
	char nama[10];
	int gol;
	//int gaji;
};

typedef pegawai larik[10];

void banyakdata(int& n){
	cout<<"Banyak pegawai: ";
	cin>>n;
}

int carigaji(larik& pegawai, int n){
	int gaji;
	for(int j=0;j<n;j++){
		if(pegawai[j].gol==1) gaji==600000;
		else if(pegawai[j].gol==2) gaji==800000;
		else if(pegawai[j].gol==3) gaji==1000000;
		else gaji==0;
	}
	return gaji;
}

void input(larik& pegawai, int n){
	cout<<"--- Input data pegawai ---"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Data pegawai ke-"<<i+1<<endl;
		cout<<"NIP\t:";
		cin>>pegawai[i].nip;
		cout<<"Nama\t:";
		cin>>pegawai[i].nama;
		cout<<"Gol\t:";
		cin>>pegawai[i].gol;
	}
}

void sorting(larik& pegawai, int n){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(pegawai[j].nip>pegawai[j+1].nip){
				swap(pegawai[j],pegawai[j+1]);
			}
		}
	}
}

void output(larik& pegawai, int n){
	sorting(pegawai,n);
	cout<<"Sorting:"<<endl<<endl<<"No\tNIP\tNama\tGol\tGaji"<<endl;
	cout<<"============================================="<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<"\t"<<pegawai[i].nip<<"\t"<<pegawai[i].nama<<"\t"<<pegawai[i].gol<<endl;
	}
}

void deletelarik(larik& pegawai, int n){
	char key[255];
	int status;
	cout<<"Masukkan NIP yang dicari: ";
	cin>>key;
	for(int i=0;i<n;i++){
		if(key==pegawai[i].nip) status=1;
		else status=0;
	}
	if(status==1) {
		for(int i;i<n-1;i++){
			pegawai[i]=pegawai[i+1];
			n=n-1;
		}
	}
}

int main(){
	larik pegawai;
	int n;
	banyakdata(n);
	input(pegawai,n);
	sorting(pegawai,n);
	output(pegawai,n);
}
