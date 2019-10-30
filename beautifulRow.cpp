#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int> v){
    int l = v.size();
    for(int i = 0; i < l; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> lis(vector <int> v) {
    int l = v.size();
    vector<int> len(l, 0);
    vector<int> last_elem;
    for(int i = 0; i < l; i++) {
        bool flag = false;
        for(int j = 0; j < last_elem.size(); j++){
            if(last_elem[j] >= v[i]){
                last_elem[j] = v[i];
                flag = true;
                break;
            }
        }
        if(!flag){
            last_elem.push_back(v[i]);
        }
        len[i] = last_elem.size();
    }

    return len;
}

int brow(vector<int> trees) {
    int l = trees.size();
    vector<int> lf = lis(trees);
    reverse(trees.begin(), trees.end());
    vector<int> lb = lis(trees);
    reverse(lb.begin(), lb.end());

    // printvec(lf);
    // printvec(lb);

    int m = INT_MIN;
    for(int i = 0; i < l; i++){
        int temp = lf[i] + lb[i];
        m = max(temp, m);
    }

    return l - m + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> trees;
    while(n--){
        int temp;
        cin >> temp;
        trees.push_back(temp);
    }

    cout << brow(trees) << endl;
    return 0;
}
