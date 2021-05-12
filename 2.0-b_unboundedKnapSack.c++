// almost same as knapSack , but now it can take reptative lelements as it is unbounded
// now when the item wight is smaller than knap sack we used to have 2 conditions, right?
//we have 2 condition here to0, but unlike KnapSack we do not processed item in one of those condition,
//when we are not including item then only we considered it processed and apply algo in (n-1)elements for some capacity
// but when we are including item we do not processed as because there is a chance that we want that item again
// so we apply algo in (n) elements for some capacity-item_weight

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

int knapSack(int W, int *val, int *wt, int N){
    for(int i=1; i<N+1; i++)
        for (int j = 1; j <W+1; j++)
        {
            if(wt[i-1]>j)
                t[i][j] = t[i-1][j];
                
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i][j-wt[i-1]] , t[i-1][j]);  //only change here t[i-1][j-wt[i-1]] to t[i][j-wt[i-1]]
            }
        }
   return t[N][W];    
}
int main(){
    //you can make a rope ie. {1,1,2} {2,2} {3,1}  see you can repeatitive items
    int price[] = { 3, 7, 12, 9 };   
    int length[] = { 1,2,3,4};   // sometime it is not given for question like this as you have every posible rope length aval for your disposal; you can make your length[] equal to size of price[] own then (generally) ,sometime you get fixed peices
    int rope_size = 4;
    int n = sizeof(price) / sizeof(price[0]);
    cout << knapSack(rope_size, price, length, n);

    print();


return 0;
}
