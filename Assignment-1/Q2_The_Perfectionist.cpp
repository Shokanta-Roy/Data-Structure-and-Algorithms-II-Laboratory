#include<iostream>
#include<vector>
using namespace std;

long long merge_sorted_arrays(vector<int>& arr, vector<int>& temp, int low, int mid, int high){

    // 1st half.
    int i = low;
    // 2nd half.
    int j = mid+1;
    // New array.
    int k = low;
    long long violations = 0;

    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            violations += mid-i+1;
            j++;
            k++;
        }
    }

    // If 1st half is yet to be processed.
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    // If 2nd half is yet to be processed.
    while(j<=high){
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy elements from merged array to our array.
    for(int i=low;i<=high;i++){
        arr[i] = temp[i];
    }

    return violations;
}

long long merge_sort(vector<int>& arr, vector<int>& temp, int low, int high){

    // Base case.
    if(low >= high){
        return 0;
    }

    // Divide.
    int mid = low + (high-low)/2;

    long long violations = 0;
    violations += merge_sort(arr, temp, low, mid);
    violations += merge_sort(arr, temp, mid+1, high);

    // Conquer.
    violations += merge_sorted_arrays(arr, temp, low, mid, high);

    return violations;
}

int main(){
    int n;
    cin >> n;

    if(n <= 0) return 0;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> temp(n);
    cout << merge_sort(arr, temp, 0, n-1) << '\n';

    return 0;
}
