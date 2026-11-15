#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Extrema {
    int min1, min2;
    int max1, max2;
    bool hasMin2, hasMax2;
};

Extrema find_extrema(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return {arr[low], 0, arr[low], 0, false, false};
    }

    int mid = low + (high - low) / 2;
    Extrema left = find_extrema(arr, low, mid);
    Extrema right = find_extrema(arr, mid + 1, high);

    // Find the two smallest distinct values among both halves.
    vector<int> minCandidates = {left.min1, right.min1};
    if (left.hasMin2) minCandidates.push_back(left.min2);
    if (right.hasMin2) minCandidates.push_back(right.min2);
    sort(minCandidates.begin(), minCandidates.end());
    minCandidates.erase(unique(minCandidates.begin(), minCandidates.end()),
                        minCandidates.end());
    int smallest = minCandidates[0];
    bool hasSecondSmallest = minCandidates.size() > 1;
    int secondSmallest = hasSecondSmallest ? minCandidates[1] : 0;

    // Find the two largest distinct values among both halves.
    vector<int> maxCandidates = {left.max1, right.max1};
    if (left.hasMax2) maxCandidates.push_back(left.max2);
    if (right.hasMax2) maxCandidates.push_back(right.max2);
    sort(maxCandidates.begin(), maxCandidates.end(), greater<int>());
    maxCandidates.erase(unique(maxCandidates.begin(), maxCandidates.end()),
                        maxCandidates.end());
    int largest = maxCandidates[0];
    bool hasSecondLargest = maxCandidates.size() > 1;
    int secondLargest = hasSecondLargest ? maxCandidates[1] : 0;

    return {smallest, secondSmallest, largest, secondLargest,
            hasSecondSmallest, hasSecondLargest};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array must contain at least one element.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int& value : arr) cin >> value;

    Extrema result = find_extrema(arr, 0, n - 1);
    if (result.hasMax2) cout << "Second maximum: " << result.max2 << '\n';
    else cout << "Second maximum: does not exist (need two distinct values).\n";

    if (result.hasMin2) cout << "Second minimum: " << result.min2 << '\n';
    else cout << "Second minimum: does not exist (need two distinct values).\n";
}
