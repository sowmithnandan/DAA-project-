#include<stdio.h>
int a[700][700];         // a is an array which at the location a[i] stores all the indices of opening brackets which match with the opening bracekt at i .  
int b[700],v[700];       // b stores the value which differentiates the bracket and v stores the value assigned to those bracket which is used to get the maximum sum  
int Max_store[700][700]; // At Max_store[i][j] the value stored is the maximum sum of the subsequence from i to j

int Answer_func(int s,int n) // This function returns maximum sum of subsequence from s to n in the array of brackets, note that the function calculates  by recursively calling  itself   
    {
    if(n<=s||n==0)
        {
        return 0;
        }
    int Max=0,i=0,Max_dash=0,k=0,max1=0,max2=0;
    Max=Answer_func(s,n-1); // Recursively calling itself 
    while(k==0 && 1)
        {
        if(a[n][i]<=-1) // This means that that particular bracket does not have any other opening brackets which can pair  up with it 
            {
            break;
            k==1;
            }
        if(a[n][i]>=s)
            {
            if(Max_store[s][a[n][i]-1]==-1)       //Here this loop is to check if there is already a value calculated and stored for that particular  subsequence and if it is not calculated \                                                  
                                                  //then recursively calling answer_func to calculate and store it  
                {
                max1= Answer_func(s,a[n][i]-1); 
                }
            else
                {
                max1=Max_store[s][a[n][i]-1];
                }
            if(Max_store[a[n][i]+1][n-1]==-1)
                {
                max2=Answer_func(a[n][i]+1,n-1);
                }
            else
                {
                max2=Max_store[a[n][i]+1][n-1];
                }
            Max_dash=max1+v[n]+v[a[n][i]]+max2;
            if(Max_dash>Max)
                {
                Max=Max_dash;
                }
            }
        i++;
        }
    Max_store[s][n]=Max;
    return Max;
    }

int main()
    {
    int i,j,n,k,l;
    for(i=0;i<700;i++)
        {
        for(j=0;j<700;j++)
            {
            Max_store[i][j]=-1;
            }
        }
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++)
        {
        scanf("%d",&v[i]);
        }
    for(i=0;i<n;i++)
        {
        scanf("%d",&b[i]);
        }
    for(i=0;i<n;i++) // This loop is to fill values in the array in which the row a[i] is the opening brackets which pair up with the closing bracket at i and are to the left of i .
        {
        l=0;
        for(j=0;j<i;j++)
            {
            if(b[i]<=k)
                {
                break;
                }
            if(b[i]-b[j]==k)
                {
                a[i][l]=j;
                l++;
                }
            }
        a[i][l]=-1; // -1 value is assigned to signify that there are no opening brackets which map to the closing brackets from here on in this row 
        }
    printf("%d\n",Answer_func(0,n-1));
    return 0;
    }
  
