
#include<bits/stdc++.h>
using namespace std;

int t[101][101];
unordered_map< string,int > mp;


int solve(string s, int i, int j, bool istrue){ 
    if(i>j)
        return false;
    if(i==j)
    {
        if(istrue==true)
            return s[i]=='T';
        if(istrue==false)
            return s[i]=='F';
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));

    if(mp.find(temp)!= mp.end())
        return mp[temp];

    int ans=0;
    for(int k=i+1; k<j; k+=2){
        int lt= solve(s,i,k-1,true);
        int lf= solve(s,i,k-1,false);
        int rt= solve(s,k+1,j,true);
        int rf= solve(s,k+1,j,false);

        if(s[k]=='&'){
            if(istrue==true)
                ans+= lt*rt;
            else
                ans+= lf*rt + lt*rf + lf*rf;
        }
        else if(s[k]=='|'){
            if(istrue==true)
                ans+= lt*rt + lt*rf + lf*rt;
            else
                ans+= lf*rf;
        }
        else if(s[k]=='^'){
            if(istrue==true)
                ans+= lf*rt + lt*rf;
            else
                ans+= lt*rt + lf*rf;
        }
        
    }
return mp[temp] = ans;
}
int main(){
    string str="T|F|T&F|T";
    int n = str.size();

    mp.clear();
    cout<<solve(str,0,n-1,true)<<endl;
    
     

return 0;
}