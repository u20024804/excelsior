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
const int MAX_COUNT = 1e5+1;
const int MOD = 1e9 + 7;


// #define ONLINE_JUDGE

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


int n, pos;
char data[MAX_COUNT];

int calc_distance(char a, char b) {
    int distance = max(a, b) - min(a, b);
    if (distance > 13) {
        distance = 26 - distance;
    }

    return distance;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> pos;
    pos--;
    REP(i, n) {
        cin >> data[i];
    }

    int total_delta = 0;
    int min_pos = MAX_COUNT;
    int max_pos = -1;
    REP(i, n/2) {
        PR(i, data[i], calc_distance(data[i], data[n-i-1]), total_delta);
        total_delta += calc_distance(data[i], data[n-i-1]);

        if (data[i] != data[n-i-1]) {
            min_pos = min(min_pos, i);
            max_pos = max(max_pos, i);
        }
    }

    if (total_delta == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (pos >= n/2) {
        pos = n - pos - 1;
    }

    PR(pos, min_pos, max_pos, total_delta);

    int total_actions = total_delta;

    if (pos >= max_pos) {
        total_actions += pos - min_pos;
    } else if (pos <= min_pos){
        total_actions += max_pos - pos;
    } else {
        total_actions += min(abs(max_pos - pos), abs(pos - min_pos));
        total_actions += max_pos - min_pos;
    }

    cout << total_actions << endl;

    return 0;
}
