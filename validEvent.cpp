#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<string>
//#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main(){

	vector<string> events={{"ACQUIRE 11"}, {"ACQUIRE 21"}, {"RELEASE 10"}, {"RELEASE 21"}};

	unordered_set<int> lockList;
	stack<int> lockOrder;
	for(int i=0;i<events.size();++i){
		string curEvent=events[i];
		string temp="";
		string name="";
		int lockNumber;
		int j=0;
		stringstream ss(curEvent);
		while(ss>>temp){
			if(j==0) name=temp;
			else lockNumber=stoi(temp);
			++j;
		}

		string sti="123";
		cout<<stoi(sti);
		if(name=="ACQUIRE"){
		
			if(lockList.find(lockNumber)!=lockList.end()){
				cout<<"Failed case:";
				break;
			}
			lockList.insert(lockNumber);
			lockOrder.push(lockNumber);

		}else{
			//Handles lock locked before release,  order of release is opposite of acquiring
			if(lockList.find(lockNumber)==lockList.end() || (!lockOrder.empty() && lockOrder.top()!=lockNumber)){
				cout<<"Failed case:";
				break;
			}
			lockOrder.pop();
			lockList.erase(lockNumber);

		}

	}

	if(lockOrder.empty()){
		cout<<"Passed case";
		return 0;
	}

	cout<<"Failed case";
}
