#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector_element(vector <T> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i];

    cout << endl;
}

vector<int> hbs;

void phd(int i, int k)
{

    if(i == 0)
    {
        if(k == 0)
        {
            print_vector_element(hbs);
            
        }
        return;
    }

    hbs.push_back(0);
    phd(i-1, k);
    hbs.pop_back();
    hbs.push_back(1);
    phd(i-1, k-1);
    hbs.pop_back();
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin); 
//    freopen("output.txt", "w", stdout); 
    
    int TC, N, H;
    cin >> TC;
    while(TC--)
    {
        cin >> N >> H;
        hbs.clear();
        phd(N,H);
        if(TC) cout << endl;

    }
    

    return 0;
}