#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

int isValid (vector<string> &input) {
  int l = input.size();
  stack<int> st;
  unordered_set<int> acquired;
  for(int i = 0; i < l; i++) {
    string s = input[i];
    int space_ind = s.find(' ');
    int id = stoi(s.substr(space_ind + 1, s.length() - space_ind - 1));
    bool acq = s.substr(0, space_ind) == "A"? 1 : 0;
    if (acq) {
      if(acquired.find(id) != acquired.end()) {
        return i;
      }
      st.push(id);
      acquired.insert(id);
    } else {
      if (st.top() != id) return i;
      st.pop();
      acquired.erase(id);
    }
  }
  if (!st.empty()) return l+1;
  return 0;
}

int main() {
  vector<string> input = {"A 23", "A 46", "A 47", "A 85", "A 78"};
  cout << isValid(input) << endl;
}

