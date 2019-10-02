#include<iostream> 
#include<string>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
vector<string> editwords(string str){
	std::vector<string> words;
	int size=str.size();
	for(int i=0;i<size;i++){

		string temp=str;
		temp.erase(temp.begin()+i);//deletion

		words.push_back(temp);
		
		for(int j=0;j<26;j++){
			string temp2=str;
			string charr="";
			charr=charr+(char)(j+65);
			temp2.erase(temp2.begin()+i);
			temp2.insert(i,charr);
			if(temp2!=str) words.push_back(temp2);
		}

		
	}
	for(int i=0;i<=size;i++){
		for(int j=0;j<26;j++){
			string temp1=str;
			string charr="";
			charr=charr+(char)(j+65);
			temp1.insert(i,charr);
			words.push_back(temp1);
		}
		
	}
	
	return words;
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);
	std::vector<string> inputs;
	string s;
	while(cin>>s){
		inputs.push_back(s);	
	}
	
	string dict_words;
	map<string, int> mapp;
	while(getline(f,dict_words)){
		if(dict_words=="") break;
		
		
		stringstream check1(dict_words);
		string dict_words2;
		string freq;

		getline(check1,dict_words2,' ');
		getline(check1,freq);
		int freq1=stoi(freq);
		//cout<<freq1<<endl;
		mapp[dict_words2]=freq1;
	}

	map<string, int>::iterator mapitr;
	int size=inputs.size();
	for(int x=0;x<size;x++){

		mapitr=mapp.find(inputs[x]);
		if(mapitr!=mapp.end()){
			//cout<<inputs[x]<<" is in the dictionary"<<endl;
			cout<<inputs[x]<<" "<<(mapitr->second)++<<endl;

		}else{
			int inside=0;
			map<string, int>::iterator mapitr2;
			string suggestion="";
			int max=0;

			std::vector<string> editwordss=editwords(inputs[x]);
			int sizeedit=editwordss.size();
			for(int i=0;i<sizeedit;i++){
				mapitr2=mapp.find(editwordss[i]);
				if(mapitr2!=mapp.end()){

					inside=1;
					if(mapitr2->second>max){
						suggestion=mapitr2->first;
						max=mapitr2->second;
					}else if(mapitr2->second==max){
						if(suggestion>mapitr2->first){
							suggestion=mapitr2->first;
						}
					}
				}
			}
			
			if(!inside){
				cout<<"-"<<endl;
				mapp[inputs[x]]=1;
			}else{
				cout<<suggestion<<" "<<mapp[suggestion]<<endl;
			}
		}
	}
	cout<<"-----"<<endl;
	for(mapitr=mapp.begin();mapitr!=mapp.end();mapitr++){
		cout<<mapitr->first<<" "<<mapitr->second<<endl;
	}

  	//cout<<"BILL"<<" "<<mapp["BILL"]<<endl;
	//cout<<itr->first<<" "<<itr->second<<endl;
	
}