#include<bits/stdc++.h>
using namespace std;

int t[101][101];

void initialize(int m, int n){
    for (int i=0; i<m+1; i++)
        for(int j=0; j<n+1; j++)
            t[i][j]=-1;
    
}


void print(int m, int n){
for (int i = 0; i < m+1; i++){
        cout<<endl;
        for(int j = 0; j< n+1; j++)
            {
              cout<<t[i][j]<<"  ";
            }
    }
    cout<<endl;
}

int Mcm(int *arr, int i, int j){ 
    if(i>=j)
        return 0;
    if(t[i][j] != -1)
        return t[i][j];

    int mn=INT_MAX;
    for(int k=i; k<=j-1; k++){   // k<=j-1 or k<j index because you need to have atleast something when you divdide your problems, you can't left it empty, or else it will be infinite loop , suppose prblm divide into 2 subprblm if one part is empty then other part will repeat full prblm
        int temp = Mcm(arr,i,k) + Mcm(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]); 
        
        if(temp<mn)
            mn=temp;
    }
return t[i][j]=mn;
}
int main(){
    int arr[]={2,10,20};  //size-1 matrixs
    int n = *(&arr+1) - arr;

    initialize(n,n);
    cout<<Mcm(arr,1,n-1)<<endl;
    print(n-1,n-1);  

return 0;
}