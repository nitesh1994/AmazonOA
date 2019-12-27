#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int UniqueSum(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  int l = arr.size();
  for (int i = 1; i < l; i++) {
    if (arr[i] <= arr[i-1]) {
      arr[i] = arr[i-1] + 1;
    }
  }

  int sum = 0;
  for (int i = 0; i < l; i++) {
    cout << arr[i] << " ";
    sum += arr[i];
  }
  cout << endl;

  return sum;
}

int main () {
  int n;
  cin >> n;
  vector<int> ids(n);
  for (int i = 0; i < n; i++) {
    cin >> ids[i];
  }

  cout << UniqueSum(ids) << endl;;
}
