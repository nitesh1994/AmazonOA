// url: https://leetcode.com/discuss/interview-question/233724
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int vowelString(string s) {
    int start = 0;
    int end = s.length() - 1;
    int count = 0;
    
    while(start <= end && isVowel(s[start])) {
        start++;
    }
    while(end > start && isVowel(s[end]) ) {
        end--;
    }
    
    count += start; // num vowels at the front
    count += s.length() - end - 1; // num vowels at the end
    
    int max_vcount = 0;
    int cur_vcount = 0;
    
    // count longest number of consecutive vowels
    while (start <= end) {
        if (isVowel(s[start])){
            cur_vcount++;
        } else {
            if(cur_vcount > max_vcount) max_vcount = cur_vcount;
            cur_vcount = 0;
        }
        start++;
    }
    
    return count + max_vcount;
}

int main() {
    string s;
    cin >> s;
    cout << vowelString(s) << endl;
}
