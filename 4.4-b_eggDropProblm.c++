
#include<bits/stdc++.h>
using namespace std;

int t[101][101];
unordered_map< string,int > mp;


int solve(int e, int f){ 
    if(e==1 || f==1)
        return f;
    if(e==0 || f==0)
        return 0;
    if(t[e][f]!=-1)
        return t[e][f];

    int mn= INT_MAX;
   for(int k=1; k<=f; k++){
       int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));

        mn=min(temp,mn);
   }
return t[e][f]=mn; ;
}
int main(){
    int egg=3;
    int floor= 100;
    memset(t,-1,sizeof(t));
  
    cout<<"turns: "<<solve(egg,floor);
    
     

return 0;
}