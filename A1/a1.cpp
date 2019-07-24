	// File: a1.cpp
	// Eric
	// Liu
	// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
	// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
	// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES
	#include <iostream>
	#include <fstream>
	#include <string>

	int main (int argc, char* argv[]) {

		std::ifstream f(argv[1]);
	 	int k = std::atoi(argv[2]);
	 	std::string s = "";
	 	getline(f, s);
	 	int length=s.length();
	   	if(k>length){
	   		std::cout<<"error"<<std::endl;
	   	}else
	   	{
			for(int i =0;i<(length-k+1);i++){
	    	for(int y=i;y<(i+k);y++){
	    		std::cout<<s[y];
	    	}
			//std::cout<<s.substr(i, k)<<std::endl;
			std::cout<<std::endl;
			}
		}
	}