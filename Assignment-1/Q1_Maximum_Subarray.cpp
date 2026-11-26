#include<iostream>
#include<vector>
using namespace std;

struct SubarrayResult {
    long long sum;
    int start_index;
    int end_index;
};

SubarrayResult find_cross_sum(const vector<int>& arr, int low, int mid, int high) {

    // Find the maximum sum from the middle to the left.
    long long l_max = arr[mid];
    long long l_sum = 0;
    int l_start = mid;

    for(int i=mid;i>=low;i--){
        l_sum += arr[i];
        if(l_sum > l_max || (l_sum == l_max && i < l_start)){
            l_max = l_sum;
            l_start = i;
        }
    }

    // Find the maximum sum from the middle to the right.
    long long r_max = arr[mid+1];
    long long r_sum = 0;
    int r_end = mid+1;

    for(int i=mid+1;i<=high;i++){
        r_sum += arr[i];
        if(r_sum > r_max || (r_sum == r_max && i < r_end)){
            r_max = r_sum;
            r_end = i;
        }
    }

    return {l_max + r_max, l_start, r_end};
}

bool is_better(const SubarrayResult& first, const SubarrayResult& second) {
    if(first.sum != second.sum) return first.sum > second.sum;
    if(first.start_index != second.start_index)
        return first.start_index < second.start_index;
    return first.end_index < second.end_index;
}

SubarrayResult max_subarr_sum(const vector<int>& arr, int low, int high) {

    // Base case.
    if(low == high){
        return {arr[low], low, high};
    }

    int mid = low + (high-low)/2;

    SubarrayResult l_max = max_subarr_sum(arr, low, mid);
    SubarrayResult r_max = max_subarr_sum(arr, mid+1, high);
    SubarrayResult cross_sum = find_cross_sum(arr, low, mid, high);

    // Conquer: choose the best subarray from the three candidates.
    SubarrayResult result = l_max;
    if(is_better(r_max, result)) result = r_max;
    if(is_better(cross_sum, result)) result = cross_sum;

    return result;
}

int main(){
    int n;
    cin >> n;

    if(n <= 0) return 0;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    SubarrayResult result = max_subarr_sum(arr, 0, n-1);

    cout << "Sum = " << result.sum << '\n';
    cout << "Start Index = " << result.start_index << '\n';
    cout << "End Index = " << result.end_index << '\n';

    return 0;
}
