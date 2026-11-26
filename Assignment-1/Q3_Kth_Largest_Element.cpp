#include<iostream>
#include<vector>
using namespace std;

void merge_sorted_arrays(vector<int>& arr, vector<int>& temp, int low, int mid, int high){

    // 1st half.
    int i = low;
    // 2nd half.
    int j = mid+1;
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
}

void merge_sort(vector<int>& arr, vector<int>& temp, int low, int high){

    // Base case.
    if(low >= high){
        return;
    }

    // Divide.
    int mid = low + (high-low)/2;

    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid+1, high);

    // Conquer.
    merge_sorted_arrays(arr, temp, low, mid, high);
}

int main(){
    int n;
    cin >> n;

    if(n <= 0) return 0;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    if(k < 1 || k > n){
        cout << "Invalid k\n";
        return 0;
    }

    vector<int> temp(n);
    merge_sort(arr, temp, 0, n-1);

    // kth largest is at index n-k in ascending order.
    cout << arr[n-k] << '\n';

    return 0;
}
