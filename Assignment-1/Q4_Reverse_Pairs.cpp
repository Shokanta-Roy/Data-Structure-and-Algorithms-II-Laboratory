#include<iostream>
#include<vector>
using namespace std;

long long merge_sorted_arrays(vector<long long>& arr, vector<long long>& temp, int low, int mid, int high){

    // Count reverse pairs from the two sorted halves.
    long long reverse_pairs = 0;
    int j = mid+1;

    for(int i=low;i<=mid;i++){
        while(j<=high && arr[i] > 2LL*arr[j]){
            j++;
        }
        reverse_pairs += j-(mid+1);
    }

    // 1st half.
    int i = low;
    // 2nd half.
    j = mid+1;
    // New array.
    int k = low;

    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
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

    return reverse_pairs;
}

long long merge_sort(vector<long long>& arr, vector<long long>& temp, int low, int high){

    // Base case.
    if(low >= high){
        return 0;
    }

    // Divide.
    int mid = low + (high-low)/2;

    long long reverse_pairs = 0;
    reverse_pairs += merge_sort(arr, temp, low, mid);
    reverse_pairs += merge_sort(arr, temp, mid+1, high);

    // Conquer.
    reverse_pairs += merge_sorted_arrays(arr, temp, low, mid, high);

    return reverse_pairs;
}

int main(){
    int n;
    cin >> n;

    if(n <= 0) return 0;

    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<long long> temp(n);
    cout << merge_sort(arr, temp, 0, n-1) << '\n';

    return 0;
}
