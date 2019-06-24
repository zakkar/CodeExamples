#include <algorithm>  
#include <vector>  
  
using namespace std;  
  
const vector<int> ConvertToBinary(const int N)  
{  
    int BinaryNumber = N;  
    vector<int> BinaryContainer;  
    while (BinaryNumber != 1)  
    {  
        BinaryContainer.push_back(BinaryNumber % 2);  
        BinaryNumber = BinaryNumber / 2;  
    }  
      
    BinaryContainer.push_back(1);  
    return BinaryContainer;  
}  
  
  
int solution(int N) {  
    int LongestBinaryGap = 0;  
    int CurrentBinaryGap = 0;  
      
    const vector<int> BinaryN = ConvertToBinary(N);  
      
    bool bStartCount = false;  
    for( unsigned int Index = 0; Index < BinaryN.size(); ++Index)  
    {  
        if(BinaryN[Index] == 1)  
        {  
            if(bStartCount)  
            {  
                if (CurrentBinaryGap > LongestBinaryGap)  
                {  
                    LongestBinaryGap = CurrentBinaryGap;    
                }  
                  
                CurrentBinaryGap = 0;  
            }  
            else  
            {  
             bStartCount = true;     
            }  
  
          continue;  
        }  
          
        if(BinaryN[Index] == 0 && bStartCount)  
        {  
            ++CurrentBinaryGap;  
        }  
   }  
      
    return LongestBinaryGap;  
}  
  