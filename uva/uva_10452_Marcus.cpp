#include <bits/stdc++.h>
using namespace std;


template <typename T>
void print_array_2D(T &a, int size_r, int size_c)
{
    for(int i = 0; i<size_r; i++)
    {
        for(int j = 0; j<size_c; j++)
            cout << a[i][j] << " ";

        cout << endl;
    }
}

bool within_the_boundary(int R, int C, int r, int c)
{
    if(c < 0 || c >= C) return false;
    if(r < 0 || r >= R) return false;
 
    return true;
}

int dir_r[3] = {-1, 0, 0}; // 0 : forth, 1 : left, 2 : right
int dir_c[3] = {0, -1, 1};
int N, M, nxt;
char iehova[8] = {'@', 'I','E', 'H', 'O', 'V', 'A', '#'};
char input[8][8];

vector<int> command;

void solution(int l, int r, int c)
{

    if(l == 7) return;
    
    for(int op = 0; op<3; op++)
    {
        int next_r = r + dir_r[op], next_c = c + dir_c[op];  
        if(!within_the_boundary(N, M, next_r, next_c)) continue;       
        if(input[next_r][next_c] == iehova[nxt])
        {
            command.push_back(op);
            nxt++;
            solution(l+1, next_r, next_c);

        }
    }

    return;

}

void print_solution()
{
    for(int i = 0; i<7; i++)
    {
        if(command[i] == 0) cout << "forth";
        else if(command[i] == 1) cout << "left";
        else cout << "right";
        if(i<6) cout << " ";
    }
    cout << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    int T, ir, ic;
    cin >> T;


    while(T--)
    {
        cin >> N >> M; 
        getchar();
        nxt = 1;

        for(int i = 0; i< N; i++)
        {
            for(int j = 0; j< M; j++)
            {
                scanf("%c", &input[i][j]);
                if(input[i][j] == '@') ir = i, ic = j;
            }
            getchar();
        }
        
        command.clear();
        solution(0, ir, ic);
        print_solution();
        

        

    }
    
    return 0;
}