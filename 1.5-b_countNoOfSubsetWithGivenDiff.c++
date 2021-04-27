// using  count of subsetSum with given Sum to solve this problem
// S1{}-S2{}=difference
// also s2{}+s1{}=arraySum      
//  therefore 2s1{}= diff + arraySum
// use countSubsetSum on this S1{} 
#include<bits/stdc++.h>
using namespace std;
int arr[] = {1,1,2,3};   
const int n = sizeof(arr) / sizeof(arr[0]);
const int sum = 7;   //araySum
const int diff = 1;
int sumS1 = (diff + sum)/2;
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

int countSubsetSumWithDiff(int sum, int *arr, int N ){
    
    for (int i=1; i<n+1; i++)
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1]>j)
                t[i][j] = t[i-1][j];   

            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
        }
    return t[N][sumS1]; // we want t[4][4] for {1,1,2,3}
}


    

int main(){

    initialize();
    cout << countSubsetSumWithDiff(sum, arr, n);

    print();


return 0;
}

