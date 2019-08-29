int getPairsCount(int arr[], int n) 
{ 
    // Store counts of all elements in map m 
    // to find pair (arr[i], sum-arr[i]) 
    // because (arr[i]) + (sum - arr[i]) = sum 
    map<int, int> m; 
    for (int i = 0; i < n; i++) 
        m[arr[i]]++; 
  
    // To remove duplicate items we use result map 
    map<pair<int, int>, int> pairs; 
  
    int count = 0; // Initialize result 
  
    // Consider all pairs 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
  
            // If sum of current pair exists 
            if (m[arr[i] + arr[j]] > 0 &&  
                pairs[{ arr[i], arr[j] }] == 0) { 
                count++; 
            } 
  
            // Insert current pair both ways to avoid 
            // duplicates. 
            pairs[{ arr[i], arr[j] }]++; 
            pairs[{ arr[j], arr[i] }]++; 
        } 
    } 
    return count; 
} 
  
// Driver function to test the above function 
int main() 
{ 
    int arr[] = { 1, 5, 6, 4, -1, 5, 10 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << getPairsCount(arr, n); 
    return 0; 
} 
