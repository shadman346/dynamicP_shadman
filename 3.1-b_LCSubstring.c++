//it represents longest common substring ending at n-1th char in s1 & m-1th char in s2. 
//So that's why maximum can be in the matrix and not necessary to be last element of t[][]
// it is headeache to do it recursively as it is hard to track size of substring that present in subprblm or subarray.
#include<bits/stdc++.h>
using namespace std;


int max_length=-1;
int t[12+1][12+1];


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
            if(m==0 || n==0)
                return 0;
            
            if(x[i-1]==y[j-1]){
            t[i][j]= 1+ t[i-1][j-1];
            }
            else{
            t[i][j]= 0;
            }
        max_length = max(max_length, t[i][j]);  //to track largeest substring.
        }
    
return max_length;
}

int main(){
string X = "PQRSTPQRS";
string Y = "PRATPBRQRPS";
int m = X.size();
int n = Y.size();

    initialize(m,n);
    cout<<"string X: "<<X<<" and string Y: "<<Y<<endl;
    cout<<"Longest Common Substring: "<<LCS(X,Y,m,n);
    cout<<endl;
    print(m,n);


return 0;
}
