#include<bits/stdc++.h>
using namespace std;

int t[5][6]={0};
// N+1=5; W+1=6;

void print(){
for (int i = 0; i < 5; i++){
        cout<<endl;
        for(int j = 0; j< 6; j++)
            {
              cout<<t[i][j]<<"  ";
            }
    }
    cout<<endl;
}

int knapSack(int W, int *val, int *wt, int N){
    for(int i=1; i<N+1; i++)
        for (int j = 1; j <W+1; j++)
        {
            if(wt[i-1]>j)
                t[i][j] = t[i-1][j];
                
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
            }
        }
   return t[N][W];    
}
int main(){

    int val[] = { 60, 100, 120 };   
    int wt[] = { 1, 2, 3 };
    int W = 5;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, val, wt, n);

    print();


return 0;
}
