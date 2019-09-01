unordered_map<int, int> counts;
        
        int start = 0, end = 0, d = 0, res = 0;
        while (end <= A.size()) {
            if (end < A.size() && counts.size() < K) {
                counts[A[end]]++;
                end++;
            } else if (counts.size() == K) {
                // Do not increment end in this block. So, we reconsider A[end] again
                if (d <= end) {
                    d = end;
                    while (d < A.size() && counts.find(A[d]) != counts.end()) d++;
                }
                while (counts.size() == K) {
                    res += (d - end + 1);
                    int rem = A[start++];
                    counts[rem]--;
                    if (counts[rem] == 0) counts.erase(rem);
                }
            } else {
                end++;
            }
        }
        return res;
