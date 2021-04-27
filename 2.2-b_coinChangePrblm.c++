// Coin change problem: Minimum number of coins
//minimum number of coins for cartain sum or cost
// if you try to think if you want to obtain minprofit or some min_value subset for given array 
//you need to intialize with some infinity value so when from our two cond in knapSack when we use min() function we cound get min value. or else it will always be zero.
// t[0][0] is ambiguous state it could be infinity or 0 i.e. in sum type questions
// thats why initialize 2nd row aswell especially in this problem it would work fine even without it as it is unbounded
// but if it bounded prblm you must initialize 2nd row  or take t[0][0] = 0

#include<bits/stdc++.h>
using namespace std;
int coins[] = { 3, 1, 1, 3 };   // this basically item[] array from knapSack that contains {value[] and wt[]}
int const sum = 5;                       
int const n = sizeof(coins) / sizeof(coins[0]);

int t[n+1][sum+1];
// N+1=5; W+1=6;

void initialize(){
    for (int i=0; i<n+1; i++)
        for(int j=0; j<sum+1; j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)               //t[0][0] set from this condition
                t[i][j]=INT_MAX-1;
        }
    
    //this is not necessary but in bounded you might need it as t[0][0] is int_max -1 
                                    //t[1][0] row..
    for (int j = 1; j<sum+1; j++)  // 2nd row initialization from index j=1
        if(j % coins[0] == 0)
            t[1][j] = 1;
        else
            t[1][j] = INT_MAX-1;
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

int coinChange(int W, int *wt, int N){
    for(int i=1; i<N+1; i++)
        for (int j = 1; j <W+1; j++)
        {
            if(wt[i-1]>j)
                t[i][j] = t[i-1][j];
                
            if(wt[i-1]<=j){
                t[i][j] = min( 1 +t[i][j-wt[i-1]] , t[i-1][j]);
            }
        }
   return t[N][W];    
}
int main(){
  
    initialize();
    cout << coinChange(sum, coins, n);

    print();


return 0;
}
