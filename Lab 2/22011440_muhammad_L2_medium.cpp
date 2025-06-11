#include <iostream>
#include <vector>
using namespace std;

void rearrangeAlternate(vector<int>& arr) {
    vector<int> positive, negative;

    for (int num : arr) {
        if (num >= 0)
            positive.push_back(num);
        else
            negative.push_back(num);
    }

    vector<int> result;
    int i = 0, j = 0;
    bool turnPositive = true;

    while (i < positive.size() && j < negative.size()) {
        if (turnPositive)
            result.push_back(positive[i++]);
        else
            result.push_back(negative[j++]);
        turnPositive = !turnPositive;
    }

    while (i < positive.size())
        result.push_back(positive[i++]);
    while (j < negative.size())
        result.push_back(negative[j++]);

    arr = result;
}

int main() {
    vector<int> arr = {1, 2, 3, -4, -1, 4};
    rearrangeAlternate(arr);

    cout << "Rearranged array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
