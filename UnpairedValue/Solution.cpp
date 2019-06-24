#include <vector>  
#include <bits/stdc++.h>   
  
using namespace std;  
  
int solution(vector<int> &A)   
{  
    unsigned int ArraySize = A.size();  
    if(ArraySize == 0)  
    {  
         return 0;  
    }  
       
     sort(A.begin(), A.end());  
  
     for(unsigned int Index = 0; Index < ArraySize; Index = Index + 2)  
     {  
        if(Index + 1 >= ArraySize )  
        {  
            return A[Index];  
        }  
          
        if(A[Index] != A[Index + 1])  
        {  
            return A[Index];  
        }  
     }  
      
    return 0;  
}  