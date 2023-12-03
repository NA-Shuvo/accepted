#include <bits/stdc++.h>
using namespace std;


template <typename T, typename X>
void set_value_1D(T &a, int size, X value)
{
    for(int i=0; i<size; i++)
        a[i] = value;
}


int s, EQS[92][8]; 
bool chess_diag1[15];
bool chess_diag2[15];
bool column[8];

vector <int> col;


bool queen_in_the_same_col(int c)
{
    if(column[c])
        return true;
    return false;
}

bool queen_in_the_same_diagon(int r, int c)
{
    if(chess_diag1[r+c] || chess_diag2[c-r+8-1] )
        return true;
    return false;
}




void place_queens(int r)
{
    if(r == 8)
    {
        s++;
        for(int i = 0; i<8; i++) EQS[s][i] = col[i];
            //cout << col[i] << " ";
        return;
    }

    for(int c = 0; c<8; c++)
    {
        if(queen_in_the_same_col(c) || queen_in_the_same_diagon(r,c))
            continue;
        col.push_back(c);
        column[c] = chess_diag1[r+c] = chess_diag2[c-r+8-1] = true;
        place_queens(r + 1);
        col.pop_back();
        column[c] = chess_diag1[r+c] = chess_diag2[c-r+8-1] = false;

    }

    return;

}


void print_solution(int result)
{
    stack<int> st;
    while(result)
    {
        st.push(result%10);
        result /= 10;
    }

    int sz = st.size();
    for(int i = 0; i<5-sz; i++)
        cout << " ";
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    return;
}

int main()
{

//    freopen("input.txt", "r", stdin); 
//    freopen("output.txt", "w", stdout); 
    s = -1;
    place_queens(0);

    int k, input[8][8];
    cin >> k;
    while(k--)
    {
        for(int i = 0; i<8; i++)
        {
            for(int j = 0; j<8; j++)
                cin >> input[i][j];
        }

        int result = 0;
        for(int sol = 0; sol<92; sol++)
        {
            int sum = 0;
            for(int row = 0; row<8; row++)
            {
                sum += input[row][EQS[sol][row]];
                
            }
            result = max(result, sum);
        }

        print_solution(result);
        cout << endl;

    }   

    return 0;
}