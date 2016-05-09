//
// Author Harold Simo wshwilfried@gmail.com
//
// the principle for the opmizing solution works is as follow
// on a given day d, check if there exist a higher price in the next days, buy until before that day comes and sell all shares on that day
// else just sell.
// I could have used vectors to store the sahes but since I already know the limited size of entry i just used an array of max size

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

bool maxExist(int low, int high, int tab[])
{
    int base = tab[low];
    bool ret = false;
    if(low == high) return false;
    
    for(int i = low + 1; i <= high; i++)
    {
       if(tab[i] > base)
       {
           ret = true;
           break;
       }
    }
    
    return ret;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int testCaseNum;
    
    //
    // Get testCaseNum
    //
    
    cin >> testCaseNum;
    
    int N = 0, aux = 0;
    int predictedPrices[50000];
    long amountSpent = 0, amountGained = 0;
    long ownedShares = 0, profit;
  
    for(long i1 = 0; i1 < testCaseNum; i1++)
    {
        cin >> N;
        
        amountSpent = 0;
        amountGained = 0;
        ownedShares = 0;
        aux = 0;
        profit = 0;
        
        //
        // Get N inputs from stdin input 
        //
        
        for(long j =0; j < N; j++)
        {
            cin >> predictedPrices[j];
        }
                         
        for(int l = 0; l < N-1; l++)
        {   
            if(maxExist(l, N-1, predictedPrices) == true)
            {
                ownedShares++;
                amountSpent += predictedPrices[l];
             }
            else
            {
                amountGained += ownedShares * predictedPrices[l];
                ownedShares = 0;
            }
            
        }
        
          amountGained += ownedShares * predictedPrices[N-1];
          profit = amountGained - amountSpent;
        
        cout << profit << endl; 
        
    }
    return 0;
}
