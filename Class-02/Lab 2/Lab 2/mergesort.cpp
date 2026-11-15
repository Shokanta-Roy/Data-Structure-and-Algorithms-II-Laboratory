#include<iostream>
#include<vector>
using namespace std;


void merge_sorted_arrays(vector<int> &arr,int low,int mid,int high){

//1st half
int i=low;
//for 2nd half
int j = mid+1;
//for new array
int k = 0;

//size of new arr
int n = high-low+1;

int merged_arr[n];

while(i<=mid && j<=high){

    //comparison

    if(arr[i]<=arr[j]){

            merged_arr[k]=arr[i];
            i++;
            k++;

    }

    else{
        merged_arr[k]=arr[j];
        j++;
        k++;
    }




}

// at least one array traverse is completed

//if 1st half is yet to be processed


while(i<=mid){

    merged_arr[k]=arr[i];
    i++;
    k++;
}


//if 2nd half is yet to be processed


while(j<=high){

    merged_arr[k]=arr[j];
    j++;
    k++;
}


//copy elements from merged array to our array

k=0;

for (int i =low;i<=high;i++){
    arr[i]=merged_arr[k];
    k++;
}





}

void merge_sort(vector <int> &arr, int low, int high){

//base case

if(low==high){ //single element always strted
    return;
}




//divide

int mid = (low+high)/2;

merge_sort(arr,low,mid); //left half will be sorted

merge_sort(arr,mid+1,high); // right half will be sorted

merge_sorted_arrays(arr,low,mid,high);



}



int main(){



vector<int> arr = {1,10,-5,30,15};
merge_sort(arr,0,arr.size()-1);

for( int x : arr){
    cout<<x<<endl;
}



}
