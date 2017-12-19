#include<iostream>
using namespace std;

const int maxElemen = 255; //maksimal tumpukan

struct stack{
	int isi[maxElemen];
	int top;
};
stack s;

void createStack(stack& s){
	s.top=-1;
}

void push(stack& s, char x){
	if(s.top==maxElemen-1){
		cout<<"Tumpukan sudah penuh."<<endl;
	}
	else {
		s.top=s.top+1;
		s.isi[s.top]=x;
	}
}

char pop(stack& s){
	char hasil;
	if(s.top<0){
		cout<<"Tumpukan sudah kosong."<<endl;
	}
	else {
		hasil=s.isi[s.top];
		s.top=s.top-1;
	}
	return hasil;
}

int empty(stack s){ //cek stack kosong
	if(s.top==-1) return 1;
	else return 0;
}

int full(stack s){ //cek stack penuh
	if(s.top==maxElemen-1) return 1;
	else return 0;
}

int length(const char *x){
	int panjang = strlen(x);
	return panjang;
}

int main(){
	char kalimat[maxElemen];
	
	cout<<"STACK ARRAY PEMBALIK KALIMAT"<<endl;
	cout<<"----------------------------"<<endl;
	
	createStack(s);
	cout<<"Masukkan kalimat: ";
	cin.getline(kalimat,maxElemen);
	cout<<endl;
	cout<<"Setelah dibalik: ";
	for(int i=0;i<length(kalimat);i++){
		push(s,kalimat[i]);
	}
	for(int i=0;i<length(kalimat);i++){
		cout<<pop(s);
	}
}



