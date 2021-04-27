// same as printing LCS sequence only difference is we also include character that is not common in both
// and the reason is obvious we need full X and Y sub string to be present in superSequence as sub sequence

#include<bits/stdc++.h>
using namespace std;

string X = "giemek";
string Y = "emke";
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

void print_LCS(string x, string y , int m, int n){
    string s=""; 
    int i=m, j=n;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s=s + x[i-1];
            i--;
            j--;
        }else{
            if(t[i][j-1]>=t[i-1][j]){   
                s=s + y[j-1];   // it is adding character that is not common or in relative order w.r.t both string
                j--;
            }else if(t[i][j-1]<t[i-1][j]){
                s=s + x[i-1];  // same as above statement
                i--;
            }
        }
 
    }
    // extra condition compare to LCS print prblm
     while(i>0){            //remaining characters that should be added
        s=s+ x[i-1];
        i--;
    }
     while(j>0){
        s=s+ y[j-1];
        j--;
    }
reverse(s.begin(), s.end());
cout<<endl<<s;
}

int main(){
  
    initialize();
    cout<< LCS(X,Y,m,n);
    print();
    print_LCS(X,Y,m,n);


return 0;
}
