#include <bits/stdc++.h>
using namespace std;


template <typename T, typename X>
void set_value_1D(T &a, int size, X value)
{
    for(int i=0; i<size; i++)
        a[i] = value;
}


int cnt = 0; 

bool diag2[15];

bool diag2_is_free(int d)
{
    return diag2[d];
}

void mark_diag2(int d)
{
    diag2[d] =  true;
    return;
}

void unmark_diag2(int d)
{
    diag2[d] = false;
    return;
}

void place_bishop(int n, int k, int d, int bn)
{
    if(bn ==  k)
    {
        cnt++;
        return;
    }
    if(d == 2*n)
    {
        return;
    }
     
    
    for(int c = d; c >= -1; c--) 
    {
        if(c == -1)
            place_bishop(n, k, d+1, bn);
        else
        {
            int diag2 = c - (d-c) + n -1;
            if(diag2_is_free(diag2))
            {
                mark_diag2(diag2);
                //cnt++;
                place_bishop(n, k, d+1, bn+1);
                unmark_diag2(diag2);
                
            }
            
        }

        
    }
    return;

}



int main()
{

//    freopen("input.txt", "r", stdin); 
//    freopen("output.txt", "w", stdout); 


    int n=4, k=4;
    set_value_1D(diag2, 2*n - 1, false);
    place_bishop(n, k, 0, 0);
    cout << cnt;

    return 0;
}