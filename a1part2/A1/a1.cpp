// File: a1.cpp
// Eric
// Liu
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
unsigned int todecimal(unsigned int num4)
{
	unsigned int num = 0; 
	int rem;

	for(int i=0;num4!=0;i++){
		rem = num4 % 10;
		num4 /= 10;
		num += rem * pow(4, i);
	}
	return num;
}


int main (int argc, char* argv[]) {


	ifstream f(argv[1]);//text file name
	int k = std::atoi(argv[2]);//k value
	int t = std::atoi(argv[3]);//t value
	string s = "";//string that is in text file
	getline(f, s);// gets the string
	int length=s.length();//length of the string
	int size=pow(4,k);

	//string kmers[4^k]={""};//array for storing the kmers
	string *kmers = new string[size];
	std::fill_n(kmers, size, "");
	
	int chars[4]={0};// stores the occurrence of the each chars A,C,G,T
	

	//int kmerscount[4^k]={0};
	int *kmerscount= new int [size];
	std::fill_n(kmerscount, size, 0);

	cout<<0<<" "<<k<<" "<<length<<endl;//outputs first line


	int lower=length-k+1;
	int error=0;
	if(k>length){
		error = 1;//if k>len of string
	}

	for(int i =0;i<length;i++){
		//string temps=new string("");
		string temps="";
		//char *temps=new char[k+1];
		//std::fill_n(temps, k, '');
		char temps1[k+1]={""};
		//char *temps1=new char[k+1];
		//std::fill_n(temps1, k, '');
		if(s[i]=='A'){
			chars[0]++;
		}
		if(s[i]=='C'){
			chars[1]++;
		}
		if(s[i]=='G'){
			chars[2]++;
		}
		if(s[i]=='T'){
			chars[3]++;
		}

		if(i<lower){
		    // for(int y=i;y<(i+k);y++){
		    // temps=temps+s[y];//makes the single kmers
		    // }
			temps=s.substr(i,k);
			//cout<<temps<<" ";
			for(int i=0;i<k;i++){//converting the substring to base 4
				if(temps[i]=='A'){
					temps1[i]='0';
				}
				if(temps[i]=='C'){
					temps1[i]='1';
				}
				if(temps[i]=='G'){
					temps1[i]='2';
				}
				if(temps[i]=='T'){
					temps1[i]='3';
				}
			}
			//cout<<temps1<<" ";
			unsigned int index = atoi(temps1);//converting the base4 to int
			//cout<<index<<" ";
			index=todecimal(index);// converting the base 4 to decimal
			//cout<<index<<endl;
			kmers[index]=temps;//adding the substring to array
			kmerscount[index]++;//incrementing the count

		}
		//delete[] temps;
		//delete[] temps1;

	}

	
	cout<<1;
	for(int i=0;i<4;i++){
		cout<<" "<<chars[i];//prints the second line
	}
	cout<<endl;

	if(error){
		cout<<"error"<<endl;
	}else{


		for(int i=0;i<size;i++){
			if(kmerscount[i]>=t){
				cout<<kmers[i]<<" "<<kmerscount[i]<<endl;
			}
		}
	}

	delete[] kmers;
	delete[] kmerscount;
}