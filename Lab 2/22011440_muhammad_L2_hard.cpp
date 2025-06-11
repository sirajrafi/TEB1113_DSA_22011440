#include <bits/stdc++.h>
using namespace std;

int minJumpsRecur(int i, vector<int> &arr) {
    
    if (i >= arr.size()-1)
        return 0;

    int ans = INT_MAX;
    for (int j=i+1; j<=i+arr[i]; j++) {
        int val = minJumpsRecur(j, arr);
        if (val != INT_MAX)
            ans = min(ans, 1+val);
    }

    return ans;
}

int minJumps(vector<int>& arr) {

    int ans =  minJumpsRecur(0, arr);
    
    if (ans == INT_MAX) 
        return -1;
        
    return ans;
}

int main() {
    vector<int> arr = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    cout << minJumps(arr);
    return 0;
}
