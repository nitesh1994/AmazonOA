#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
static bool compare(const string& a, const string& b){
	int l=0;

	char l1;
	char l2;
	string alpha="abcdefghijklmnopqrstuvwxyz";
	while( l<a.size()){
		++l;
		l1=a[l];
		l2=b[l];

		if( alpha.find(l1) > alpha.find(l2)) return true;
		else if( alpha.find(l2) > alpha.find(l1)) return false;

	}

	return true;


}

int main(){

	vector<string> words={"fgh","fghi"};

	sort(words.begin(), words.end(), compare);

	cout<<words[0]<<words[1];


}
