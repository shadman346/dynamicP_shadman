
#include<bits/stdc++.h>
using namespace std;


int t[100+1][100+1];


void initialize(int m, int n){
    for (int i=0; i<m+1; i++)
        for(int j=0; j<n+1; j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)               
                t[i][j]=0;
        }
    
   
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

int LCS(string x, string y, int m, int n){
    for(int i=1; i<m+1; i++)
        for(int j=1; j<n+1; j++){
            
            if(x[i-1]==y[j-1]){ 
            t[i][j]= 1+ t[i-1][j-1];
            }
            else{
            t[i][j]= max(t[i][j-1],t[i-1][j]);
            }
        }
    
return t[m][n];
}

int main(){
    string X = "ace";
    string Y = "abcdef";  // {a,c,e} present answr will be true
    int m = X.size();
    int n = Y.size();

    initialize(m,n);
    int Lcs=LCS(X,Y,m,n);

    bool ans=false;         
    if(Lcs==m)    // if LCS is as same size as matching string then it is true
        ans=true;

    cout<<endl<<"is string X subsequence of string B?: "<<ans<<endl;
    print(m,n);


return 0;
}
    