// you  need to find the lenght of reapating longest sub sequence for a string,
// now we do know if we try to find LCS of bwtween same/duplicate string it always be the size of string.
// now to get the repeating sequence in same string we just need to stop  processing character that are at same index
// so the character at that index can match another same character may present in some other index at same string.
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
            
            if(x[i-1]==y[j-1] && i!=j){  // add (i!=j) to stop processing character at same index
            t[i][j]= 1+ t[i-1][j-1];
            }
            else{
            t[i][j]= max(t[i][j-1],t[i-1][j]);
            }
        }
    
return t[m][n];
}

int main(){
    string X = "agbcab";
    string Y = X;
    int m = X.size();
    int n = Y.size();

    initialize(m,n);
    int Lcs=LCS(X,Y,m,n);
    cout<<endl<<"LCS repating in same string "<< Lcs<<endl;
    print(m,n);


return 0;
}
