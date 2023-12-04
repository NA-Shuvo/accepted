#include <bits/stdc++.h>
using namespace std;
#define MAX 17


template <typename T, typename X>
void set_value_1D(T &a, int size, X value)
{
    for(int i=0; i<size; i++)
        a[i] = value;
}


vector <int> bag;
vector <vector<int>> big_bag;

int N;

bool is_prime[101];
bool taken[MAX];

void solution(int l)
{
    if(l == 1)
    {
        if(is_prime[bag[N-1] + 1])
        {
            for(int i = 0; i< N; i++)
            {
                cout << bag[i];
                if(i != N-1) cout << " ";
            }
                
            cout << endl;
//            big_bag.push_back(bag);
        }
        
        return ;
    }

    for(int i = 2; i<=N; i++)
    {

        if(!taken[i])
        {
            int last_element_taken = bag[bag.size()-1];

            if(is_prime[last_element_taken + i])
            {
                //out << i;
                taken[i] = true;
                bag.push_back(i);
                solution(l-1);
                taken[i] = false;
                bag.pop_back();
            }
        }
    }

    return;
}

void fill_is_prime()
{
    set_value_1D(is_prime, 101, false);
    int primes_within_100[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for(int i = 0; i<25; i++)
        is_prime[primes_within_100[i]] = true;
}

int main()
{
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    vector <int> input;
    int cs = 0, temp;

    while(cin >> temp)
        input.push_back(temp);
        
    
    int sz = input.size();
    for(int i = 0; i<sz; i++)
    {
        cout << "Case "<< ++cs << ":\n";
        fill_is_prime();
        
        bag.clear();
        set_value_1D(taken, MAX, false);
        taken[1] =  true;
        bag.push_back(1);
        N = input[i]; 
        solution(N);
        if(i != sz-1)
            cout << endl;
    }


    return 0;
}