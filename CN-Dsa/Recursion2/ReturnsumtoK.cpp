#include <iostream>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k)
{

    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0; //BASE CASE
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int op1[1000][50];
    int op2[1000][50];

    int s2 = subsetSumToK(input + 1, n - 1, op2, k);
    int s1 = subsetSumToK(input + 1, n - 1, op1, k - input[0]);

    int rownumber = 0;
    for (int i = 0; i < s2; i++)
    {
        for (int j = 0; j <= op2[i][0]; j++)
        {
            output[rownumber][j] = op2[i][j];
        }
        rownumber++;
    }
    for (int i = 0; i < s1; i++)
    {
        output[rownumber][0] = op1[i][0] + 1;
        output[rownumber][1] = input[0];
        for (int j = 2; j <= op1[i][0]; j++)
        {
            output[rownumber][j] = op2[i][j - 1];
        }
        rownumber++;
    }
    return rownumber;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
/*
int subsetSumToK(int input[], int n, int output[][50], int k) {
    
    if(n==0)
    {
        if(k==0)
        {
            output[0][0]=0;                  
            return 1;
        }
        else {
            return 0;
        }
    }
    
    int op1[1000][50];
    int op2[1000][50];
    
 
    int s2=subsetSumToK(input+1,n-1,op2,k);
    int s1=subsetSumToK(input+1,n-1,op1,k-input[0]);
    
    int rownumber=0;
    
 
    for(int i=0;i<s2;i++)
    {
        for(int j=0;j<=op2[i][0];j++)
        {
            output[rownumber][j]=op2[i][j];
        }
        rownumber++;
    }
    

    for(int i=0;i<s1;i++)
    { 
      output[rownumber][0]=op1[i][0]+1;
      output[rownumber][1]=input[0];
        for(int j=1;j<=op1[i][0];j++)
        {
            output[rownumber][j+1]=op2[i][j];
        }
        rownumber++;
    }    
   
return rownumber;
}

*/