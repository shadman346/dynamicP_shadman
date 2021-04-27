
#include<bits/stdc++.h>
using namespace std;

string X = "stone";
string Y = "longest";
int m = X.size();
int n = Y.size();

int t[8+1][8+1];


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
        for(int j = 0; j< m+1; j++)
            {
              cout<<t[i][j]<<"  ";
            }
    }
    cout<<endl;
}

int LCS(string x, string y, int m, int n){
        if(m==0 || n==0)
            return 0;
        
        if(x[m-1]==y[n-1]){
            return 1+LCS(x,y,m-1,n-1);
        }
        else{
            return max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
        }
    
return -1; //c++ err
}

int main(){
  
    initialize();
    cout<< LCS(X,Y,m,n);

    print();


return 0;
}
