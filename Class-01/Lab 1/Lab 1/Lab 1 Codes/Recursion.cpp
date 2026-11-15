#include<iostream>
using namespace std;

bool checkPallindrome(string str,int l,int h){

//base case

if(l>=h){
    return true;
}

if(str[l]==str[h]){
    return checkPallindrome(str,l+1,h-1);
}
else{

    return false;
}





}


bool checkPower(int n,int x){
if(n==1){
    return true;
}
if(n==0||n%x!=0){
    return false;
}



return checkPower(n/x,x);


}

int find_max(int arr[],int n){

//base case
if(n==0){
    return INT_MIN;
}
return max(arr[n-1],find_max(arr,n-1));
}

int sumOfDigits(int n){

if(n==0){
    return 0;
}
return n%10 + sumOfDigits(n/10);

}

int stairClimbing(int n){

if(n==0||n==1){
    return 1;
}

return stairClimbing(n-1)+ stairClimbing(n-2);

}


int fib(int n){

if(n==0||n==1){
    return n;
}
return fib(n-1)+fib(n-2);

}

int calcSum(int n){

//base case : smallest valid input
if(n==1){
    return 1;
}

return n+calcSum(n-1);

}

int fact(int n){

//base case : smallest valid input
if(n==0||n==1){
    return 1;
}

return n*fact(n-1);

}


int main(){

cout<<"sum of 1 to 6: "<<calcSum(6)<<endl;
cout<<"factorial of 4: "<<fact(4)<<endl;
cout<<"5th fibonacci number: "<<fib(5)<<endl;
cout<<checkPower(10,2);


}
