//1624
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << "\n";
#define pv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define pum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
int inf = 1000000007;

vector<vi> dir = {{1,-1},{1,0},{1,1}};
void modify(int x, int y, int delta, vector<vi>& board) {
    for (const auto& didj : dir) {
        int di=didj[0];int dj=didj[1];
        int i=x+di; int j=y+dj;
        while (i>=0 && j>=0 && i<8 && j<8) {
            board[i][j]+= delta;
            i+=di;
            j+=dj;
        }
    }
}

void dfs(int i, vector<vi>& board, int& res) {
    if (i==8) {
        res++;
        return;
    }
    for (int j=0; j<8; ++j) {
        if (board[i][j]) continue;
        modify(i, j, 1, board);
        dfs(i+1, board, res);
        modify(i, j, -1, board);
    }
}

int main() {
    vector<vi> board(8,vi(8));
    string row;
    for (int i=0;i<8;++i) {
        cin >> row;
        board[i] = vi(8);
        for (int j=0;j<8;++j) {
            board[i][j]=row[j]=='*';
        }
    }
    int res = 0;
    dfs(0, board, res);
    p(res);
}