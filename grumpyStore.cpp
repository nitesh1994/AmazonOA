#include <iostream>
#include <vector>
using namespace std;

int getSum (vector<int> v, int s, int e) {
    int sum = 0;
    for(int i = s; i <= e; i++) {
        sum += v[i];
    }
    return sum;
}

int bruteForce(vector<int> v, int t, int p) {
    if (p >= t) return getSum(v, 0, t-1);
    int m = INT_MIN;
    for (int i = 0; i < t - p + 1; i++) {
        m = max(m, getSum(v, i, i + p - 1));
    }
    return m;
}

int linear(vector<int> v, int t, int p) {
    if (p >= t) return getSum(v, 0, t-1);
    int m = getSum(v, 0, p-1);
    for(int i = 1; i < t - p + 1; i++) {
        int j = i + p - 1;
        int temp = m - v[i-1] + v[j];
        m = max(m, temp);
    }
    return m;
}

int main() {
    int t, p;
    cin >> t >> p;
    vector<int> v;
    for(int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cout << bruteForce(v, t, p) << endl;
    cout << linear(v, t, p) << endl;

    return 0;
}