/* PR STRUKTUR DATA */

// SOAL NO. 1A

/* Nama Program: Looping bintang 1-4
Deskripsi: Nested loop for & while */

/*
#include <iostream.h>
using namespace std;

void loopfor(int baris){
	for(int i=1;i<=baris;i++){ //looping i dengan angka lebih kecil sama dengan variabel baris dan i increment
		cout<<i; //output memunculkan i
		for(int j=1;j<=i;j++){ //looping j dengan angka lebih besar sama dengan i dan j increment
			cout<<"*"; //output memunculkan *
		}
		cout<<endl; //memunculkan baris baru
	}
}
void loopwhile(int baris){
	int i=1; //pendeklarasian i
	while(i<=baris){ //looping i dengan syarat i lebih kecil sama dengan baris
		cout<<i; //output memunculkan i 
		int j=1; //pendeklarasian j
		while(j<=i){ //looping j dengan syarat j lebih kecil sama dengan i
			cout<<"*"; //output memunculkan *
			j++; //increment dilakukan pada variabel j
		}
		i++; //increment dilakukan pada variabel i
		cout<<endl; //memunculkan baris baru
	}
}
int main(){
	int baris; //pendeklarasian
	cout<<"Banyak baris: "; //untuk input banyak baris
	cin>>baris; //variabel input berupa baris

	loopfor(baris);
	cout<<endl;
	loopwhile(baris);
}
*/

// SOAL NO. 1B

/* Nama Program: Looping bintang 4-1
Deskripsi: Nested loop & while */

/*
#include <iostream.h>
using namespace std;

void loopfor(int i){
	for(i;i>=1;i--){ //looping i dengan angka lebih besar sama dengan 1 dan i decrement
		cout<<i; //output memunculkan i
		for(int j=1;j<=i;j++){ //looping j dengan angka lebih besar sama dengan i dan j increment
			cout<<"*"; //output memunculkan *
		}
		cout<<endl; //memunculkan baris baru
	}
}
void loopwhile(int i){
	while(i>=1){ //looping i dengan syarat i lebih besar sama dengan 1
		cout<<i; //output memunculkan i
		int j=1; //pendeklarasian j
		while(j<=i){ //looping j dengan syarat j lebih kecil sama dengan i
			cout<<"*"; //output memunculkan *
			j++; //increment dilakukan pada variabel j
		}
		i--; //decrement dilakukan pada variabel i
		cout<<endl; //memunculkan baris baru
	}
}
int main(){
	int i; //pendeklarasian
	cout<<"Banyak baris: "; //untuk input banyak baris
	cin>>i; //variabel input berupa i

	loopfor(i);
	cout<<endl;
	loopwhile(i);
}
*/

//SOAL NO. 2A

/*
1
Akhir dalam loop
Akhir dalam loop
3
Akhir dalam loop
5
Akhir dalam loop
Akhir luar loop
*/

//SOAL NO. 2B

/*
Akhir loop
3
Akhir loop
4
Akhir loop
5
Akhir loop
6
Akhir loop

i=7
*/

//SOAL NO. 3

/* Nama Program: Perpangkatan
Deskripsi: Looping */

/*
#include<iostream.h>

void input(int& x,int& y){
	cout<<"Masukkan angka: ";
	cin>>x;
	cout<<"Masukkan pangkat: ";
	cin>>y;
}
int hitung(int& x,int& y,int& z){
	z=1;
	for(int i=0;i<y;++i){
		z*=x;
	}
	return z;
}
int main(){
	int x,y,z;
	input(x,y);
	cout<<"Hasil akhir: "<<hitung(x,y,z);
}
*/

//SOAL NO. 4

/* Nama Program: Anak ayam
Deskripsi: Looping */

#include <iostream.h>
using namespace std;

int main(){
	int x,jmlh;
	cout<<"Mari bernyanyi lagu anak ayam!"<<endl;
	cout<<"==============================="<<endl;
	cout<<"Masukkan jumlah anak ayam: ";
	cin>>jmlh;
	cout<<"==============================="<<endl;
	for(x=jmlh;x>0;x--){
		if (x>1) cout<<"Anak ayam turun "<<x<<" mati satu tinggal "<<x-1<<endl;
		else if (x=1)cout<<"Anak ayam turun 1 mati satu tinggal induknya"<<endl;
	}
}