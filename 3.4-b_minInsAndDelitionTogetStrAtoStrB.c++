// find kar LCS dono ka ab basically strA mai LCS ke alava jo sab character hai faltu hai,
// strA.size - LCS = deltion mil jayega, ab insetion ke liye jis string mai strA ko badlana vo dekh jo strB hai,
// to strB mai LCS bataeyga ki konse character add karne strA mai , LCS minus karde strB.size mai se pata chal jayega. 
#include<bits/stdc++.h>
using namespace std;

string X = "heap";
string Y = "pea";
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
            if(m==0 || n==0)
                return 0;
            
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
    int Lcs=LCS(X,Y,m,n);
    cout<<"LCS: "<< Lcs<<endl;
    cout<<"deletion: "<< m-Lcs<<endl;
    cout<<"insertion: "<< n-Lcs;

    print();


return 0;
}
