#include <iostream>
#include <vector>
using namespace std;

int helper(int s, int e, vector<int> &arr) {
  if (s > e) return 0;
  int ind = 0;
  int range = 0;
  for (int i = s; i <= e; i++) {
    int ts = max(i - arr[i], s);
    int te = min(i + arr[i], e);
    int r = te - ts + 1;
    if (r > range) {
      range = r;
      ind = i;
    }
  }

  int rs = max(ind - arr[ind], s);
  int re = min(ind + arr[ind], e);
  return 1 + helper(s, rs - 1, arr) + helper(re + 1, e, arr);
}

int numFountains(vector<int> &arr) {
  return helper(0, arr.size() - 1, arr);
}

int main () {
  int N;
  cin >> N;
  vector<int> input(N);
  for (int i = 0; i < N; i++) cin >> input[i];
  cout <<  numFountains(input) << endl;
}

