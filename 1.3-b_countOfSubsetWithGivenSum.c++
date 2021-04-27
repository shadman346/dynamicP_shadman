//you have to find number/count of possible subset for given sum
//that is poosible in your given array.
// eg {2,3,5,7,10}  find possible value for sum=10
// possible subset of sum=10  =>  {10} {2,3,5} {3,7}  count=3

// keep in mind subsetSum only giving us true or false whether this subset exist or not but not actual count.
// suppose when in cond if(wt[n-1]<=w),for recursion 
//or you can say if(arr[i-1]<=j),for iteration  ..we have two conditon.
// in previous questions of knapSack prblms you pick only one because either 
//'you want optimum soln' or 'you just want to know whether it exists or not' for given array.
// but in this problem both condition matters as both can yeild true result that means
// with or without "processed item" we get "true" for both result in boolean for subsetSum but if we intialize with integer type.
// then it must be some integer value or you can say we can get a count in how ways could get specific sum value.
// for both condition as both have different required sum for same no.of elements/items.
//basically in first condition we processed element so we need to look for Sum=sum-wt[i-1] ,in [n-1] el try to find in how many ways we could get this Sum.
// and in second condition we do not processed ny el so we look for Sum=sum , in [n-1] el try to find in how way we could this sum.

#include<bits/stdc++.h>
using namespace std;

int arr[] = {2,3,5,6,8,10};   
const int n = sizeof(arr) / sizeof(arr[0]);
const int sum = 10;
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
                t[i][j] = t[i-1][j];   //instead of true/false we will get some integer which can be 0 or greater than 0

            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
        }
    return t[N][sum];
}


    

int main(){

    initialize();
    cout << countOfSubsetSum(sum, arr, n);

    print();


return 0;
}

