/*
 * uniquel.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: Sushant
 */
#include <iostream>
#include <string>

using namespace std;

bool is_lowercase(const string s){
	for(unsigned int i=0; i<s.size(); ++i){
		if((s[i]>'z') || (s[i]<'a')){
			return false;
		}
	}

	return true;

}

bool unique_chars(string s){
	unsigned int bitset = 0;
	for(unsigned int i = 0; i < unsigned(s.length()); i++){
		int setter = 1 << (s[i]-'a');
		if((setter & bitset) > 0){
			return false;
		}
		bitset |= setter;
	}
	return true;
}

int main(int argc, char *argv[]) {
	string s;
	if (argc == 1){
		cout << "Enter a lowercase string: ";
		cin >> s;
			if(!is_lowercase(s)){
				 cout << "Error: String must contain only lowercase letters." << endl;
			} else {
				if(unique_chars(s)){
					cout << "All letters are unique." << endl;
				} else {
					cout << "Duplicate letters found." << endl;
				}
			}
	} else{
		cout << "Usage: ./unique <string>" << endl;
	}


	return 0;
}

