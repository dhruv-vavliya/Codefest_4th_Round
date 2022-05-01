//  TALK IS CHEAP. SHOW ME THE </CODE>.
//  @author : Dhruv_Vavliya.

#include <bits/stdc++.h>
using    namespace std;
#define  lli  long long int
#define  ulli unsigned lli
#define  ld   long double
#define  pb   push_back
#define  vi   vector<int>
#define  vl   vector<lli>
#define  all(v) v.begin(),v.end()
#define  fix    fixed<<setprecision(15)
bool     comp(lli a,lli b) { return a>b; }
lli      cd(lli a ,lli b)  {return a%b == 0 ? a/b : a/b+1;}
#define  mod 1000000007
const    int N = 2e5 + 5;

int test=1;
template< typename type >
void display( type val ){
    cout << "Case #" << test << ": " << val << endl;
    test++;
}

void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char ,vector<char>> mp;
    mp['O'] = {'R' ,'Y'};
    mp['P'] = {'R' ,'B'};
    mp['G'] = {'Y' ,'B'};
    mp['A'] = {'R' ,'Y' ,'B'};
    mp['R'] = {'R'};
    mp['Y'] = {'Y'};
    mp['B'] = {'B'};

    vector<set<char>> v(n);
    int ans = 0;
    for( int i=0 ;i<n ;i++ ){
        if( s[i] != 'U' ){
            for( char &u : mp[s[i]] ){
                if( i-1 >= 0 and v[i-1].find(u) != v[i-1].end() ){
                
                }else{
                    ans++;
                }
                v[i].insert(u);
            }
        }
    } 
    display(ans);
}

int32_t main(){   
    cin.tie(0), cin.sync_with_stdio(0);

    freopen("C:\\Users\\dell\\Documents\\Practice\\codefest\\Round_4\\Problem_1\\ts2_input.txt", "r" , stdin);
    freopen("ts2_output.txt", "w", stdout);

    int t=1;
    cin >> t;

    while(t--){
        solve();
    }
}