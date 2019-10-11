#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printvec(vector<int> v) {
  for (int a: v) cout << a << " ";
  cout << endl;
}

int getSeconds(vector<int> &arr, int pos) {
  pos ++;
  int l = arr.size();
  printvec(arr);
  int count = 0;
  rotate(arr.begin(), arr.begin() + pos, arr.end());
  printvec(arr);
  for (int i = 0; i < pos; i++) {
    arr[l-i-1]--;
    count++;
  }

  printvec(arr);

  int rounds = arr[l-1];

  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i = 0; i < l; i++) {
    if(arr[i]) pq.push(arr[i]);
  }
  
  int seconds = 0;
  int r = 0;
  while(r != rounds) {
    int t = pq.top();
    cout << t << " " << seconds << " " << r << " " << rounds << endl;
    seconds += (t - r) * pq.size();
    r = t;
    pq.pop();
  }

  return seconds + count;
}

int main () {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int pos;
  cin >> pos;
  cout << getSeconds(arr, pos) << endl;
}
