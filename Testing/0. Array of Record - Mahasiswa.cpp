#include<iostream>
using namespace std;

struct mahasiswa{
	char npm[13];
	char nama[20];
	int nilai;
};

typedef mahasiswa array[10];

void banyakdata(int& n){
	cout<<"Banyak data: ";
	cin>>n;
}
void inputdata(int& n,array& mhs){
	for(int i=0;i<n;i++){
		cout<<"Data mahasiswa ke-"<<i+1<<endl<<"---------------------"<<endl;
		cout<<"NPM\t: ";
		cin>>mhs[i].npm;
		cout<<"Nama\t: ";
		cin.ignore();
		cin.getline(mhs[i].nama, 20);
		cout<<"Nilai\t: ";
		cin>>mhs[i].nilai;
		cout<<endl;
	}
}
void cetakdata(int& n,array& mhs){
	cout<<"PENCETAKAN DATA MAHASISWA"<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<"\t"<<mhs[i].npm<<"\t"<<mhs[i].nama<<"\t"<<mhs[i].nilai<<endl;
	}
	cout<<endl;
}
void rata(int& n,array& mhs){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+mhs[i].nilai;
	}
	int rata=sum/n;
	cout<<"Rata-rata: "<<rata<<endl;
}
void maximum(int& n,array& mhs){
	int max=0;
	for(int i=0;i<n;i++){
		if(max<mhs[i].nilai) max=mhs[i].nilai;
	}
	cout<<"Nilai tertinggi: "<<max<<endl;
}
void minimum(int& n,array& mhs){
	int min;
	for(int i=0;i<n;i++){
		if(min>mhs[i].nilai) min=mhs[i].nilai;
	}
	cout<<"Nilai terendah: "<<min<<endl;
}
void sorting(int& n,array& mhs){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(mhs[j].npm>mhs[j+1].npm){
				swap(mhs[j],mhs[j+1]);
			}
		}
	}
	cout<<"Sorting:"<<endl<<endl<<"NPM\t\tNama\t\tNilai"<<endl;
	cout<<"============================================="<<endl;
	for(int j=0;j<n;j++){
		cout<<mhs[j].npm<<"\t"<<mhs[j].nama<<"\t\t"<<mhs[j].nilai<<endl;
	}
}
int main(){
	int n;
	array mhs;
	
	banyakdata(n);
	inputdata(n,mhs);
	cetakdata(n,mhs);
	rata(n,mhs);
	maximum(n,mhs);
	minimum(n,mhs);
	sorting(n,mhs);
}
  