#include<iostream>
#include<vector>
using namespace std;

int partition_(vector<int> &arr,int low,int high){

int i = low-1;
int j = low;

int pivot = arr[high];

for(int j=low;j<high;j++){

    if(arr[j]<pivot){
        i++;
        swap(arr[i],arr[j]);
    }

}

swap(arr[i+1],arr[high]);

return i+1;



}


void quick_sort(vector<int>&arr,int low,int high){

//base case
/*
if(low==high){
    return;
}
*/


if(low<high)
{

//choose a pivot element

int pivot =arr[high];

//find the actual index for the pivot

int p_idx = partition_(arr,low,high);


quick_sort(arr,low,p_idx-1);
quick_sort(arr,p_idx+1,high);

}

}

int main(){


vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

quick_sort(arr,0,arr.size()-1);

for(int x:arr){
    cout<<x<<endl;
}


}
