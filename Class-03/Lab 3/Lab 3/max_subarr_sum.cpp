#include<iostream>
#include<vector>
using namespace std;

int find_cross_sum(vector<int>arr,int low,int mid,int high){


    //mid to low

   int l_max=INT_MIN;
   int l_sum =0;

    for(int i=mid;i>=low;i--){

        l_sum+=arr[i];
        if(l_sum>l_max){
            l_max=l_sum;
        }

    }

   int r_max=INT_MIN;
   int r_sum=0;

   for(int i=mid+1;i<=high;i++){
    r_sum+=arr[i];
    if(r_sum>r_max){
        r_max=r_sum;
    }
   }

 return l_max+r_max;

}


int max_subarr_sum(vector<int>arr, int low, int high){


//base case

if(low==high){
    return arr[low];
}

int mid = (low+high)/2;

int l_max_sum =max_subarr_sum(arr,low,mid);

int r_max_sum = max_subarr_sum(arr,mid+1,high);

int cross_sum = find_cross_sum(arr, low,mid, high);


//conquer

return max(max(l_max_sum,r_max_sum),cross_sum);




}




int main(){


vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

cout<<"max sum: "<<max_subarr_sum(arr,0,arr.size()-1);







}
