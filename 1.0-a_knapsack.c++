#include<bits/stdc++.h>

using namespace std;

int t[5][6]={0};

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
int knapSack(int w, int *val, int *wt, int n){

    if(n==0 || w==0 || t[n][w]!=0)  //this for value not wt keep in mind 
        return t[n][w];
    
    if(wt[n-1]>w){
        t[n][w] = knapSack(w, val, wt, n-1);
        return t[n][w];
    }
    if(wt[n-1]<=w){       
        t[n][w] = max(val[n-1] + knapSack(w-wt[n-1], val, wt, n-1) , knapSack(w, val, wt, n-1) );
        return t[n][w];
    }

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