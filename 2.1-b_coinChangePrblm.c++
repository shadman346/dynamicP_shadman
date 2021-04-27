//in this problem we have unlimited supply of coin of some specific value or price
// we need to count total no. of ways in which we can obtain given sum or cost
// it is clearly unbounded just use countSubsetSum with unbounded variation
#include<bits/stdc++.h>
using namespace std;

int arr[] = {1,3,4,5};   
const int n = sizeof(arr) / sizeof(arr[0]);
const int sum = 5;
int t[n+1][sum+1]; 

void initialize(){
    for (int i=0; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
        {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
}

void print(){
for (int i = 0; i < n+1; i++){
        cout<<endl;
        for(int j = 0; j< sum+1; j++)
            {
              cout<<t[i][j]<<"  ";
            }
    }
    cout<<endl;
}

int countOfSubsetSum(int sum, int *arr, int N ){

    for (int i=1; i<n+1; i++)
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1]>j)
                t[i][j] = t[i-1][j];   

            if(arr[i-1]<=j)
                t[i][j] = t[i][j-arr[i-1]] + t[i-1][j];   //unbounded variation
        }
    return t[N][sum];
}


    

int main(){

    initialize();
    cout << countOfSubsetSum(sum, arr, n);

    print();


return 0;
}

