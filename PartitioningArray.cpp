#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool PartitionArray(vector<int> &arr, int k) {
  int n = arr.size();
  if (n % k) return 0;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
    if (mp[arr[i]] > n/k) return 0;
  }
  return 1;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  string s = PartitionArray(arr, k)? "Yes" : "No";
  cout << s << endl;
}

