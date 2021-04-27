// finding if we partion a array into two subset whether we could get 2 equal sum subset
#include<bits/stdc++.h>
using namespace std;

int arr[] = {3, 3, 7, 7,2,2,4,4,3,9};   
const int n = sizeof(arr) / sizeof(arr[0]);
const int sum = 100;//sum is not given in this problem we are taking for sake of initializing dynamic arr 
//that means it can use for upto array total_sum= 200;
bool t[n+1][sum+1]; 

void initialize(){
    for (int i=0; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
        {
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
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

bool subsetSum(int sum, int *arr, int N ){  

    for (int i=1; i<n+1; i++)
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1]>j)
                t[i][j] = t[i-1][j];

            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }
    return t[N][sum];
}

bool equalSumPartition(int *arr, int n){
    int sum=0; //this sum will determine actual weight/sum/capacity or limiter for our prblm
    for (int i=0; i<n; i++)
        sum+=arr[i];
    
    if (sum%2 !=0)
        return false;
    
    if (sum%2==0)
        return subsetSum(sum/2, arr, n);
    
return 0; // not gonna come here giving fizool ka error thatss why add this return
    
}
int main(){

    initialize();
    cout << equalSumPartition(arr, n);

    


return 0;
}
