#include<bits/stdc++.h>
using namespace std;

//A(i) = arr[i-1]*arr[i]
// Ai => A1 A2 A3 A4 A5
int Mcm(int *arr, int i, int j){ 
    if(i>=j)
        return 0;
    int mn=INT_MAX;
    for(int k=i; k<=j-1; k++){   // k<=j-1 or k<j index because you need to have atleast something when you divdide your problems, you can't left it empty, or else it will be infinite loop , suppose prblm divide into 2 subprblm if one part is empty then other part will repeat full prblm
        int temp = Mcm(arr,i,k) + Mcm(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]); 
        //part 1st give minOperation to get matrix out from Ai.Ak  and + 2nd give minOPeration to get matrix out from A(k+1).Aj 
        // and + last part tell us the operation that is going to take to multiply these two matrixes or parts.
        if(temp<mn)
            mn=temp;
    }
return mn;
}
int main(){
    int arr[]={2,10,20};
    int n = *(&arr+1) - arr;
    cout<<Mcm(arr,1,n-1);

return 0;
}