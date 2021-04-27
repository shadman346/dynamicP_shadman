// partition an array into 2 sets such that we get the minimum difference= s2{}-s1{}.

// in this approach I am using subset sum for t[n+1][sum+1] matrix ,
//i need only last row as it includes every element and it tells whether 
//there is any subset for corresponding Sum [j-->] in boolean infact I need only half row 
//because we will check till half_sum/range. so we can reduce it to only t[n+1][sum/2 + 1] matrix. decrease space complexity
// take range as MAX_SUM and if we have s1{} set and s2{} set ,then one must be smaller(or equal) to range/2.
// if range= s2{} + s1{} then s2{}=range-s1{}
// therefore diff= s2{}-s1{} can be wriiiten as diff=range-2*s1{};  we can also see as s1{} approaching range/2 the diff will be min
//for arr {1,2,7} , dynamic matrix t[3+1][10/2 +1]  (boolean) 
// we have sum=10 then s1{} must lie sum<=5 now we check t[3][5] if true then there subset exist otherewise no.
// if t[3][5] false then check t[3][4] if true then calculate minimum difference = range-2*s1 = 10-2*4=2; if not continue the process
#include<bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 7,};

const int sum=10;  //this is arraySum !  1+2+7=10
const int n = sizeof(arr) / sizeof(arr[0]);



bool t[n+1][sum/2 + 1];

void initialize(){
    for (int i=0; i<n+1; i++)
        for(int j=0; j<sum/2+1; j++)
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
        for(int j = 0; j< sum/2+1; j++)
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

int minSubsetDiff(){
    subsetSum(sum/2, arr, n); // need to check till half row as we need to find only s1{} which is always <=sum/2
    for (int j= sum/2; j>=0; j-- )
            if(t[n][j]==true)
                return sum-2*j;

return 0;//program err
}

int main(){

    initialize();
    cout << minSubsetDiff();

    print();


return 0;
}
