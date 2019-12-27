#include <iostream>
#include <vector>
using namespace std;

int finalprice(vector<int> &arr) {
  int min = INT_MAX;
  int total = 0;
  for (int i = arr.size() - 1; i >= 0; i --) {
    int cost = arr[i];
    if (cost >= min) {
      cost -= min;
    } else {
      min = arr[i];
    }
    // cout << cost << " " ;
    total += cost;
  }
  cout << endl;

  return total;
}

int main () {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << finalprice(arr) << endl;
}
