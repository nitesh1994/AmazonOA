#include <iostream>
#include <vector>
using namespace std;

#define MAX_INSTANCES 200000000

int numInstances(int ini, vector<int> & avg) {
  int l = avg.size();
  for (int i = 0; i < l;) {
    if (avg[i] > 60) {
      if (ini*2 <= MAX_INSTANCES) {
        ini *= 2;
        i += 10;
      } else {
        i++;
      }
    } else if (avg[i] < 25) {
      if (ini > 1) {
        ini /= 2;
        i += 10;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }
  return ini;
}

int main() {
  int n, num_instances;
  cin >> n >> num_instances;
  vector<int> avg(n);
  for (int i = 0; i < n; i++) {
    cin >> avg[i];
  }
  cout << numInstances(num_instances, avg) << endl;
}

