// File: a4.hpp
// First Name: Eric
// Last Name: Liu
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A4_HPP
#define A4_HPP

#include <ostream>
#include <queue>
#include <vector>
#include "symbol.hpp"


using namespace std;


// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT ALL REQUIRED FUNCTIONS BELOW
// YOU ARE NOT ALLOWED TO ALTER ANY INTERFACE
// INSIDE A FUNCTION YOU CAN DO WHATEVER YOU LIKE

// IMPLEMENT YOUR FUNCTION huffman_tree
bnode<symbol>* combine(bnode<symbol>* first,bnode<symbol>* second){
	bnode<symbol>* tempbnode=new bnode<symbol>();

	tempbnode->value.count=first->value.count+second->value.count;
	
	if(first->value.value<second->value.value){
		tempbnode->value.value=first->value.value;
	}else{
		tempbnode->value.value=second->value.value;
	}
	tempbnode->left=first;
	tempbnode->right=second;
	
	//cout<<tempbnode->value.value<<" "<<tempbnode->value.count<<endl;
	return tempbnode;
}
template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last){


	struct compare_bnodes {
	bool operator()(const bnode<symbol>* lhs, const bnode<symbol>* rhs) const {
    	return rhs->value < lhs->value;

	}
	};


	priority_queue<bnode<symbol>*,vector<bnode<symbol>*>,compare_bnodes> pq;
	
	for(Iter temps = first;temps!=last;temps++){
		bnode<symbol>* tempbnode=new bnode<symbol>();
		tempbnode->value=*temps;
		tempbnode->left=nullptr;
		tempbnode->right=nullptr;
		//cout<<tempbnode->value.value<<" "<<tempbnode->value.count<<endl;
		pq.push(tempbnode);
	}


	// while(pq.size()!=0){
	// 	bnode<symbol>* tempprint=pq.top();
	// 	pq.pop();
	// 	cout<<tempprint->value.value<<" "<<tempprint->value.count<<endl;
	// }

	//bnode<symbol>* first=new bnode<symbol>(pq.top());

	while(pq.size()>1){
	bnode<symbol>* firstbnode=pq.top();
	pq.pop();
	bnode<symbol>* secondbnode=pq.top();
	pq.pop();
	
	bnode<symbol>* combined=combine(firstbnode,secondbnode);
	pq.push(combined);

	}
	return pq.top();
	//return nullptr;
} 

void printhelper(std::ostream& os,string str,bnode<symbol>* node){
	if(node->left!=nullptr){
		string strleft=str+"0";
		printhelper(os,strleft,node->left);
	}
	if(node->right!=nullptr){
		string strright=str+"1";
		printhelper(os,strright,node->right);
	}
	if(node->left==nullptr){
		os<<node->value.value<<" "<<str<<endl;
	}
}

// IMPLEMENT YOUR FUNCTION print_dictionary
void print_dictionary(std::ostream& os, bnode<symbol>* root){
	string s="";
	printhelper(os,s,root);
	
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){
	if(root->left!=nullptr){
		release_tree(root->left);

	}
	if(root->right!=nullptr){
		release_tree(root->right);
	}
	delete root;
	
}
#endif // A4_HPP
