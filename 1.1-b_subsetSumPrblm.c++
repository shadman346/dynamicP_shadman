// does a certian sum exist in array.
// T or F 
#include<bits/stdc++.h>
using namespace std;

int arr[] = {2, 3, 7, 7, 10};   
const int sum = 11;
const int n = sizeof(arr) / sizeof(arr[0]);

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

    for (int i=1; i<N+1; i++)
        for(int j=1; j<sum+1; j++)   // j is basically a capacity for knapSack
        {
            if(arr[i-1]>j)
                t[i][j] = t[i-1][j];

            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];     // possible cond {TT,FF,TF,FT}
        }
    return t[N][sum];
}

int main(){

    initialize();
    cout << subsetSum(sum, arr, n);

    print();


return 0;
}
