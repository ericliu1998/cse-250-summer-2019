// File: a2.hpp
// First Name
// Last Name
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A2_HPP
#define A2_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>
using namespace std;
struct keyvaluestruct{
    int key;
    vector<int> value;
    
};

class key_value_sequences {
    list<keyvaluestruct> g;
public:
    
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY

    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN 0
    int size(int key) const{
        
        list<keyvaluestruct>::const_iterator it2;
        for(it2=g.begin();it2!=g.end();it2++){
            if(it2->key==key){
                
                return it2->value.size();
            }
        }
        return 0;
    }

    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key) const{

        list<keyvaluestruct>::const_iterator it;
        for(it=g.begin();it!=g.end();it++){
            if(it->key==key){
                return it->value.data();
            }
        }
        return nullptr;
    }

    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value){
        
        list<keyvaluestruct>::iterator it;
        for(it=g.begin();it!=g.end();it++){
            if(it->key==key){
                it->value.push_back(value);
                //bool_contains=1;
                return;
            }
        }
        
            keyvaluestruct newkeyvalue;
            newkeyvalue.key=key;
            newkeyvalue.value.push_back(value);
            g.push_back(newkeyvalue);
        
    }

}; // class key_value_sequences

#endif // A2_HPP
