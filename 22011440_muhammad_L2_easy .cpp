#include <bits/stdc++.h>
using namespace std;

int thirdLargest(vector<int> &arr) {
    int n = arr.size();
    
    int first = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > first) first = arr[i];
    }
    
    int second = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }
    
    int third = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }
    
    return third;
}

int main() {
    vector<int> arr = {3, 19, 2, 24, 31, 20};
    cout << thirdLargest(arr) << endl;

    return 0;
}