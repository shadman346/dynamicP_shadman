// min partttion in a string to get plaindromic sub strings
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

bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int partition(string s, int i, int j){ 
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    if(isPalindrome(s.substr(i,j-i+1)))
        return 0;

    int mn=INT_MAX;
    for(int k=i; k<j; k++){   //j is index so you are iterating size-1 passes only
        int temp = partition(s,i,k) + partition(s,k+1,j) + 1;
    
        if(temp<mn)
            mn=temp;
    }
return t[i][j]=mn;
}
int main(){
    string str="nitink";
    int n = str.size();

    memset(t,-1,sizeof(t));
    cout<<partition(str,0,n-1)<<endl;
    
     

return 0;
}