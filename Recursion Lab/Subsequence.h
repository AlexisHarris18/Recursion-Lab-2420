#pragma once
#include <iostream>
#include <string>

//ADD LIBARIES
using std::ostream;
using std::string;


class Subsequence {
	public:
		string word;
		Subsequence(string w) : word(w){}
		bool isSubsequence(string sub, int wIndx = 0, int sIndx = 0);
		friend ostream& operator<<(ostream&, const Subsequence&);
};

bool Subsequence::isSubsequence(string sub, int wIndx, int sIndx) {
	//BASE CASES
	int wSize = word.size();
	int sSize = sub.size();
	if (sub.empty()) { //An empty subsequence is always a subsequence of that word
		return true;
	}
	if (word.empty()) { //Sub cannot be a subsequence of an empty word
		return false;
	}
	
	//RECURSION CASE
	else {
		if (sIndx == sSize) {
			return true;
		}
		if (wIndx == wSize) {
			return false;
		}
		if (word[wIndx] == sub[sIndx]) {
			return isSubsequence(sub, wIndx + 1, sIndx + 1);
		}
		else {
			return isSubsequence(sub, wIndx + 1, sIndx);
		}
		
	}
}

ostream& operator<<(ostream& out, const Subsequence& s) {
	out << "Word:" << s.word;
	return out;
}
