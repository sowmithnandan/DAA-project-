#include <iostream>
#include <string.h>
using namespace std;
//memoization
int arr[700][700];

//function to get the maximum 
int max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}

//function to the maximum sum of values of a valid bracket subsequence
int maxsumsub(int b[],int v[],int i,int j,int k){
    if(j-i==0 || j<i){
        return 0;
    }
    //if arr[i][j] is precalculated, then return the result
    if(arr[i][j]){
        return arr[i][j];
    }
    //iterate through brackets and finding th emaximum sum using the dynamic approach
    for(int a=i+1;a<=j;a++){
        //opening bracket
        if(b[a]<=k){
            arr[i][a]=arr[i][a-1];
        }
        //closing bracket
        else{
            int flag=0,t=0;
            //findin its opening bracket
            for(int c=i;c<a;c++){
                //first pair found
                if(b[c]+k==b[a] && flag==0){
                    if(c==0){
                        t=v[c]+v[a]+maxsumsub(b,v,c+1,a-1,k);
                    }
                    else{
                        t=arr[i][c-1]+v[c]+v[a]+maxsumsub(b,v,c+1,a-1,k);
                    }
                    flag=1;
                }
                else if(b[c]+k==b[a] && flag==1){
                    //comparison
                    t=max(t,arr[i][c-1]+v[c]+v[a]+maxsumsub(b,v,c+1,a-1,k));
                }
            }
            arr[i][a]=max(arr[i][a-1],t);
        }
    }
    return arr[i][j];
}

int main(){
    int n,k;
    cin>>n>>k;
    int b[n],v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<maxsumsub(b,v,0,n-1,k);
    return 0;
}