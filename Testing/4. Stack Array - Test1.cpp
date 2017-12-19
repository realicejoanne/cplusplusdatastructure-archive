#include<iostream>
using namespace std;

const int maxElemen = 255;

struct stack{
	char isi[maxElemen]; //buat cout angka/huruf
	int top;
};
stack s;

void createStack(stack& s){
	s.top=-1;
}

void push(stack& s, char elemenBaru){
	if (s.top==maxElemen-1){
		cout<<"Tumpukan sudah penuh"<<endl;
	}
	
	else{
		s.top=s.top+1;
		s.isi[s.top]=elemenBaru;
	}
}

void pop(stack& s, char elemenHsl){
	if (s.top<0){
		cout<<"Tumpukan sudah kosong"<<endl;
	}
	else{
		elemenHsl=s.isi[s.top];
		s.top=s.top-1;
	}
}

void cetak(stack& s){
	for(int i=s.top;i>=0;i--){
		cout<<s.isi[i]<<endl;
	}
}
	
int main(){
	stack s;
	char a;
	
	createStack(s);
	push(s,'S');
	push(s,'O');
	push(s,'P');
	push(s,'I');
	cout<<"Stack awal: "<<endl;
	cetak(s);
	cout<<endl;
	
	pop(s,a);
	cout<<"Stack akhir: "<<endl;
	cetak(s);
}
	
	
	