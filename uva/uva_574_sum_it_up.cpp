#include <bits/stdc++.h>
using namespace std;




void print_vector_element(vector <int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i];
        if(i!= v.size()-1)
            cout << '+';

    }
        

    cout << endl;
}

int sum_of_vector_elements(vector<int> v)
{
    int sum = 0, size = v.size();
    for(int i = 0; i< size; i++)
        sum += v[i];

    return sum;
}

set<vector<int>> sol ;
vector<int> input;
vector<int> temp;
stack<vector<int>> st;



void solution(int s, int n, int target)
{
    if(s == n)
    {
        if(sum_of_vector_elements(temp) == target)
            sol.insert(temp);
        return;
    }

    temp.push_back(input[s]);
    solution(s+1, n, target);
    temp.pop_back();
    solution(s+1, n, target);
    return;

}


int main()
{
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    
    int t,n, temp;

    while(cin >> t >> n)
    {
        if(n == 0) break;
        input.clear();
        sol.clear();

        for(int i = 0; i<n; i++)
        {
            cin >> temp;
            input.push_back(temp);
        }

        solution(0, n, t);
        for (auto it = sol.begin(); it != sol.end(); it++)  
            st.push(*it);
    
        cout << "Sums of " << t <<":"<< endl;
        if(st.empty()) cout << "NONE" << endl;
        
        while(!st.empty())
        {
            print_vector_element(st.top());
            st.pop();
            
        } 
        

    }
    

    return 0;
}