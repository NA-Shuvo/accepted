#include <bits/stdc++.h>
using namespace std;



template<typename T>
T sum_of_elements_of_vector_1D(vector<T> v)
{
    T result;
    int size = v.size();
    if(size == 0) return (T) 0;

    result = v[0];
    for(int i = 1; i<size; i++)
        result += v[i];

    return result;
}

template <typename T>
void print_vector_element(vector <T> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
}


int S, target, best;
vector<int> result, bag, input;

void solution(int i)
{
    if(i == S)
    {
        int temp = sum_of_elements_of_vector_1D(bag);
        if(best < temp && temp <= target)
        {
            result = bag;
            best = temp;
        }
        return;
    }

    bag.push_back(input[i]);
    solution(i+1);
    bag.pop_back();
    solution(i+1);
    return;
}


int main()
{
//    freopen("input.txt", "r", stdin);    
//    freopen("output.txt", "w", stdout);

    int temp;
    while(scanf("%d%d", &target, &S) != EOF)
    {
        best = 0;

        for(int i = 0; i<S; i++)
        {
            cin >> temp;
            input.push_back(temp);
        }

        solution(0);
        print_vector_element(result);
        printf("sum:%d\n", best);

        input.clear();
        bag.clear();
        result.clear();

    }

    return 0;
}