
#include<bits/stdc++.h>
using namespace std;

int t[101][101];
unordered_map< string,int > mp;


bool solve(string s1, string s2, int z){ 
    
    if(s1.compare(s2) == 0)
        return true;
    if(z<=1)
        return false;
    
    string temp = s1;
    temp.push_back(' ');
    temp.append(s2);

    if(mp.find(temp)!= mp.end())
        return mp[temp];
    
    bool flag= false;
    for(int k=0; k<z-1; k++){
        
        if(( solve(s1.substr(0,k+1),s2.substr(z-k-1,k+1),k+1) && solve(s1.substr(k+1,z-k-1),s2.substr(0,z-k-1),z-k-1) ) ||
        ( solve(s1.substr(0,k+1),s2.substr(0,k+1),k+1) && solve(s1.substr(k+1,z-k-1),s2.substr(k+1,z-k-1),z-k-1) ))
        {
            flag = true;
            break;
        }
        
    }
return mp[temp] = flag;
}
int main(){
    string x="roger";
    string y="rrgoe";
    int nx = x.size();
    int ny = y.size();

    mp.clear();
    if(nx==ny)
        cout<<solve(x,y,nx)<<endl;
    else
        cout<<false;
    
     

return 0;
}