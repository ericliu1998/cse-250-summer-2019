#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
using namespace std;

int main()
{


	// int k =3;
 //    string *kmers = new string[4^k];
	// std::fill_n(kmers, 4^k, "x");
	// cout<<kmers[7]<<endl;
 //    delete[] kmers;
    srand(time(0));
    
    for(int i=0;i<100000000;i++){
       int r = (rand() % 4);
       if(r==0){
		   	cout<<'A';
		}
		if(r==1){
		   	cout<<'C';
		}
		if(r==2){
		   	cout<<'G';
		}
        if(r==3){
		   	cout<<'T';
		}
    }
    
 

    return 0;
}