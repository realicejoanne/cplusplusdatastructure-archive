/*	Nama Program	: Gaji Pegawai
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 5 April 2017
	Deskripsi		: Array of Record
*****************************************/

#include<iostream>
#include<iomanip>
using namespace std;

struct pegawai{
	int nip;
	char nama[20]; //nama pegawai maks 20 karakter
	int gaji;
	int gol;
};

typedef pegawai array[20]; //banyak pegawai maks 20

void carigaji(int& n,array& peg){
	for(int i=0;i<n;i++){
		switch(peg[i].gol){
			case 1: peg[i].gaji = 2000000;
				break;
			case 2: peg[i].gaji = 3000000;
				break;
			case 3: peg[i].gaji = 5000000;
				break;
			case 4: peg[i].gaji = 8000000;
				break;
		}
	}		
}
void input(int& n,array& peg){
	cout<<"Banyak pegawai: ";
	cin>>n;
	cout<<endl;
	
	for(int i=0;i<n;i++){
		cout<<"Data pegawai ke-"<<i+1<<endl;
		cout<<"NIP\t:  ";
		cin>>peg[i].nip;
		cout<<"Nama\t:  ";
		cin.ignore();
		cin.getline(peg[i].nama, 20);
		cout<<"Gol\t:  ";
		cin>>peg[i].gol;
		cout<<endl;
	}
}

void daftar(){
	cout<<" GOL "<<setw(5)<<" GAJI "<<endl;
	cout<<"==========="<<endl;
	cout<<"  1  "<<setw(5)<<"  2jt "<<endl;
	cout<<"  2  "<<setw(5)<<"  3jt "<<endl;
	cout<<"  3  "<<setw(5)<<"  5jt "<<endl;
	cout<<"  4  "<<setw(5)<<"  8jt "<<endl<<endl;
}

void sorting(int& n,array& peg){
	carigaji(n,peg);
	cout<<"NIP\tNama\t\tGol\tGaji"<<endl;
	cout<<"============================================="<<endl;
	for(int i=0;i<n;i++){
		cout<<peg[i].nip<<"\t"<<peg[i].nama<<"\t\t"<<peg[i].gol<<"\t"<<"Rp"<<peg[i].gaji<<endl;
	}
	
	cout<<endl<<"Setelah disorting secara ascending: "<<endl<<endl;
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(peg[j].nip>peg[j+1].nip){
				swap(peg[j],peg[j+1]);
			}
		}
	}
	cout<<"NIP\tNama\t\tGol\tGaji"<<endl;
	cout<<"============================================="<<endl;
	for(int j=0;j<n;j++){
		cout<<peg[j].nip<<"\t"<<peg[j].nama<<"\t\t"<<peg[j].gol<<"\t"<<"Rp"<<peg[j].gaji<<endl;
	}
}

void ratagaji(int& n,array& peg){
	int sum=0;
	int rata;
	for(int i=0;i<n;i++){
		sum=sum+peg[i].gaji; 
	}
	rata=sum/n;
	cout<<endl<<"Rata-rata: "<<rata;
}

void max(int& n,array& peg){
	int max=0;
	for (int i=0;i<n;i++){
		if(max<peg[i].gaji) max=peg[i].gaji;
	}
	cout<<endl<<"Gaji terbesar: "<<max;
}

void min(int& n,array& peg){
	int min;
	for(int i=0;i<n;i++){
		if(min>peg[i].gaji) min=peg[i].gaji;
	}
	cout<<endl<<"Gaji terkecil: "<<min;
}
int main(){
	int n;
	array peg;
	
	cout<<"DAFTAR GAJI PEGAWAI PT. INGIN SUKSES"<<endl;
	cout<<"===================================="<<endl<<endl;
	
	//cetakdaftar
	daftar();
	
	//input pegawai
	input(n,peg);
	
	//sorting
	sorting(n,peg);
	
	//ratagaji
	ratagaji(n,peg);
	
	//gajitertinggi
	max(n,peg);
	
	//gajiterendah
	min(n,peg);
}