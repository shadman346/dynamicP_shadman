// exactly same as last problem 1.5-b :countNoOfSubsetWithGivenDiff
// only way of asking question is different
// in this question they asked us count in how many ways to assign either '+' or '-' to your array elements
// such we get the given or asked SUM
// in previous question it was difference
// think mathamatically ,you are basically making 2 subset one contains minus array el and other positive array element. 
#include<bits/stdc++.h>
using namespace std;
int arr[] = {1,1,2,3};   
const int n = sizeof(arr) / sizeof(arr[0]);
const int sum = 7;   //araySum
const int getSum = 1; // diff in previous prblm
int sumS1 = (getSum + sum)/2;
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
                t[i][j] = t[i-1][j];   //instead of true/false we will get some integer which can be 0 or greater than 0

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

