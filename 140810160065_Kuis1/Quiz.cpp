#include<iostream>
#include<string.h>
using namespace std;

struct mahasiswa{
	string npm,nama;
	char hm;
	float tugas, quiz, uts, uas, akhir;
};

typedef mahasiswa array[30];

void jmlhmhs(int& n){
	cout<<"Jumlah mahasiswa: ";
	cin>>n;
}
void input(int& n, array& mhs){
	for(int i=0;i<n;i++){
		cout<<"Input data mahasiswa ke-"<<i+1<<endl;
		cout<<"NPM\t: ";
		cin.ignore();
		getline(cin, mhs[i].npm);
		cout<<"Nama\t: ";
		//cin.ignore();
		getline(cin, mhs[i].nama);
		cout<<"Tugas\t: ";
		cin>>mhs[i].tugas;
		cout<<"Quiz\t: ";
		cin>>mhs[i].quiz;
		cout<<"UTS\t: ";
		cin>>mhs[i].uts;
		cout<<"UAS\t: ";
		cin>>mhs[i].uas;
		cout<<endl;
	}
}
void hitungakhir(int& n, array& mhs){
	for(int i=0;i<n;i++){
		mhs[i].akhir=mhs[i].tugas*0.2+mhs[i].quiz*0.2+mhs[i].uts*0.3+mhs[i].uas*0.3;
	}
}
void output(int& n, array& mhs){
	cout<<endl;
	cout<<"Hasil output data: "<<endl<<endl;
	cout<<"NPM\t\tNama\tTugas\tQuiz\tUTS\tUAS\tNA"<<endl;
	for(int i=0;i<n;i++){
		cout<<mhs[i].npm<<"\t"<<mhs[i].nama<<"\t"<<mhs[i].tugas<<"\t"<<mhs[i].quiz<<"\t"<<mhs[i].uts<<"\t"<<mhs[i].uas<<"\t"<<mhs[i].akhir<<endl;
	}
}
void hurufmutu(int& n,array& mhs){
	cout<<endl<<"HURUF MUTU"<<endl;
	cout<<"=========="<<endl;
	cout<<"A (80-100)"<<endl<<"B (68-79)"<<endl<<"C (56-67)"<<endl<<"D (40-55)"<<endl<<"E (< 40)"<<endl<<endl;
	
	for(int i=0;i<n;i++){
		if(mhs[i].akhir>=80&&mhs[i].akhir<=100) mhs[i].hm='A';
		if(mhs[i].akhir>=68&&mhs[i].akhir<=79) mhs[i].hm='B';
		if(mhs[i].akhir>=56&&mhs[i].akhir<=67) mhs[i].hm='C';
		if(mhs[i].akhir>=40&&mhs[i].akhir<=55) mhs[i].hm='D';
		if(mhs[i].akhir>=0&&mhs[i].akhir<=39) mhs[i].hm='E';
	}
}
/*
void swap(int& a, int& b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
*/
void sorting(int& n, array& mhs){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(mhs[j].npm>mhs[j+1].npm){
				swap(mhs[j],mhs[j+1]);
			}
		}
	}
	cout<<"Hasil sorting data: "<<endl<<endl;
	cout<<"NPM\t\tNama\tTugas\tQuiz\tUTS\tUAS\tNA\tHM"<<endl;
	for(int i=0;i<n;i++){
		cout<<mhs[i].npm<<"\t"<<mhs[i].nama<<"\t"<<mhs[i].tugas<<"\t"<<mhs[i].quiz<<"\t"<<mhs[i].uts<<"\t"<<mhs[i].uas<<"\t"<<mhs[i].akhir<<"\t"<<mhs[i].hm<<endl;
	}
	cout<<endl;
}
void maksimum(int& n, array& mhs){
	float max=0;
	for(int i=0;i<n;i++){
		if(max<mhs[i].akhir) max=mhs[i].akhir;
	}
	cout<<"Nilai akhir maksimum: "<<max<<endl;
}
void minimum(int& n,array& mhs){
	float min;
	for(int i=0;i<n;i++){
		if(min>mhs[i].akhir) min=mhs[i].akhir;
	}
	cout<<"Nilai akhir minimum: "<<min<<endl;
}
void rata(int& n, array& mhs){
	float sum=0,avr;
	for(int i=0;i<n;i++){
		sum=sum+mhs[i].akhir;
	}
	avr=sum/n;
	cout<<"Rata-rata nilai akhir: "<<avr<<endl;
}
int main(){
	array mhs;
	int n;
	
	jmlhmhs(n);
	input(n,mhs);
	hitungakhir(n,mhs);
	output(n,mhs);
	hurufmutu(n,mhs);
	sorting(n,mhs);
	maksimum(n,mhs);
	minimum(n,mhs);
	rata(n,mhs);
}
