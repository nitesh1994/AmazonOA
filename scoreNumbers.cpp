#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;
int score(int num){
	int scoreThree=0;
	int scoreEven=0;
	int scoreSevens=0;
	
	if(num%3==0) scoreThree=4;

	int temp=num;
	while(num){
		int now=num%10;
		if(now==7) scoreSevens+=5;
		
		if(now%2==0) scoreEven+=3;

		num/=10;
	}

	int numConsecTwos=0;
	int scoreConsecTwos=0;
	int prevVal=INT_MIN;
	int incStreak=1;
	int scoreIncreasing=0;
	while(temp){
		int cur=temp%10;

		if(cur==2) numConsecTwos++;
		else{
			if(numConsecTwos>1) scoreConsecTwos+=6*(numConsecTwos-1);
			numConsecTwos=0;

		}

		if(prevVal!=INT_MIN && cur==prevVal+1){
			incStreak++;
		}
		else if(prevVal>=0){
			scoreIncreasing+=pow(incStreak, 2);
			incStreak=1;		

		}

		prevVal=cur;
		temp/=10;

	}

	if(incStreak>0) scoreIncreasing+=pow(incStreak, 2);

	if(numConsecTwos>1) scoreConsecTwos+=6*(numConsecTwos-1);

	int totalScore=scoreThree+scoreEven+scoreSevens+scoreConsecTwos+scoreIncreasing;
}
int main(){
	int N;
	cin>>N;
	cout<<score(N)<<endl;

}
