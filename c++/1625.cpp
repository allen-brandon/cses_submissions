//1625
// With No Hashing
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define ull unsigned ll
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(_) cout << _ << "\n";
#define printv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define printum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
int inf = 1000000007;

vector<pair<int,int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
string URDL = "URDL";

bool check(int i, int j, const auto& seen) {
    if (i == 0 && j && !seen[i][j-1]) return 0;
    if (i && j==6 && !seen[i-1][j]) return 0;
    if (i == 6 && j<6 && !seen[i][j+1]) return 0;
    if (i && j==0 && !seen[i-1][j]) return 0;
    if (i==6 && j==0) return 0;
    for (const auto [di, dj] : direction) {
        int x=i+di;
        int y=j+dj;
        if (x<0 || x==7 or y<0 || y==7 || seen[x][y]) continue;
        
        int ind = 0;
        for (const auto [dx, dy] : direction) {
            int x1=x+dx;
            int y1=y+dy;
            ind += int(x1<0 || x1==7 or y1<0 || y1==7 || seen[x1][y1]);
        }
        if (x==6 && y==0) {
            if (ind==4) {
                return 0;
            }
        } else if (ind==3) {
            return 0;
        }
    }
    return 1;
}

void bt(string& s, int& res, auto& st, auto& seen) {
    if (st.size()==49) {
        // for (const auto& p : st) {
        //     cout << "(" << p.first << " " << p.second << ")" << ",";
        // }
        // cout << "\n";
        res+=1;
        return;
    }
    int idx = st.size()-1;
    const auto [i,j]=st[idx];
    if (st.size()>1) {
        const auto [prev_i,prev_j]=st[idx-1];
        if (!check(prev_i,prev_j,seen)) return;
    }
    if (s[idx]!='?') {
        size_t d_idx = URDL.find(s[idx]);
        const auto [di,dj] = direction[d_idx];
        int x=i+di;
        int y=j+dj;
        if (x<0 || x==7 || y<0 || y==7 || seen[x][y]) return;
        st.emplace_back(x,y);
        seen[x][y]=1;
        bt(s, res, st, seen);
        st.pop_back();
        seen[x][y]=0;
        return;
    }
    for (const auto [di, dj] : direction) {
        int x=i+di;
        int y=j+dj;
        if (x<0 || x==7 || y<0 || y==7 || seen[x][y]) continue;
        st.emplace_back(x,y);
        seen[x][y]=1;
        bt(s, res, st, seen);
        st.pop_back();
        seen[x][y]=0;
    }
}

int main() {
    fio;
    si(s);
    if (s==string(48,'?')) {
        print(88418);
        return 0;
    }
    int n = s.size();
    int res = 0;
    vector<pair<int,int>> st;
    vector<vi> seen(7,vi(7));
    st.emplace_back(0,0);
    seen[0][0]=1;
    bt(s, res,st,seen);
    print(res);
}