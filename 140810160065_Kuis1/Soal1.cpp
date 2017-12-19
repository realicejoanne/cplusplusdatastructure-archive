/*	Nama program	: Quiz-1
	Nama			: Patricia Joanne
	NPM				: 140810160065
	Tanggal buat	: 4 April 2017
	Deskripsi		: Soal 1
****************************************/

#include<iostream.h>

int main(){
	int *p,*a;
	p=new int;
	*p=2;
	cout<<"p	: "<<p<<endl;
	cout<<"*p	: "<<*p<<endl;
	cout<<"&p	: "<<&p<<endl;
	cout<<"&(*p)	: "<<&(*p)<<endl<<endl;
	delete(p);
	
	a=new int;
	*a=12;
	cout<<"a	: "<<a<<endl;
	cout<<"*a	: "<<*a<<endl<<endl;
	
	cout<<"*p setelah delete : "<<*p<<" "<<p;
}