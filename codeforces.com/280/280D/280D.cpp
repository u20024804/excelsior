#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef vector<int> vi; 

#define REP(k,a) for(int k=0; k < (a); ++k)
#define FOR(i,a,b) for(int i=a; i < (b); ++i)
#define ALL(a) begin(a), end(a)
#define COUNT(a) (sizeof(a)/sizeof(a[0]))

const int INF = 1e9;
const int MAX_COUNT = 1e5;
const int MOD = 1e9 + 7;


#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE 

///// trace helpers /////
#define PR(...) pr(#__VA_ARGS__, __VA_ARGS__);

template<typename T>
void print_value(const string& name, const T& value) {
    if (name.find("\"") != string::npos) {
        cout << value << " ";
        return;
    }
    cout << name << ": " << value << ", ";
}

// template<>
// void print_value<Indent>(const string& name, const Indent& value) {
//     cout << value;
// }

template<typename T>
void pr(const string& name, const T& t) {
    cout << name << ": " << t << endl;
}

template<typename T, typename ... Types>
void pr(const string& names, const T& t, Types ... rest) {
    auto comma_pos = names.find(',');
    print_value(names.substr(0, comma_pos), t);
    
    auto next_name_pos = names.find_first_not_of(" \t\n", comma_pos + 1);
    pr(string(names, next_name_pos), rest ...);
}


#else
# define PR(...)
#endif


ll n, x, y;

string solve(int hp) {
    int left = hp % (x + y);

    if (left == 0) return "Both";

    PR(hp);

    ll first = 0;
    ll count = x*y;
    while (count > 0)
    {
      ll step = count/2; 
      ll it = first + step;

      ll sum = it/y + it/x;

      PR(first, step, it, count, sum);

      if (sum < left) {                 // or: if (comp(*it,val)), for version (2)
        first = ++it;
        count -= step + 1;
      }
      else 
        count=step;
    }

    if (first % x == 0 && first % y == 0) {
        return "Both";
    } else if (first % y == 0) {
        return "Vanya";
    }

    return "Vova";
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> x >>y;
    REP(i, n) {
        int hp;
        cin >> hp;
        cout << solve(hp) << endl;
    }

    return 0;
}
