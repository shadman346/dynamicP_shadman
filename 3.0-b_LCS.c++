
#include<bits/stdc++.h>
using namespace std;

string X = "PQRSTPQRS";
string Y = "PRATPBRQRPS";
int m = X.size();
int n = Y.size();

int t[12+1][12+1];


void initialize(){
    for (int i=0; i<m+1; i++)
        for(int j=0; j<n+1; j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)               
                t[i][j]=0;
        }
    
   
}


void print(){
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
  
    initialize();
    cout<< LCS(X,Y,m,n);

    print();


return 0;
}
