#include <bits/stdc++.h>
using    namespace std;
#define  lli long long int
#define  all(v) v.begin(),v.end()

int test=1;
template< typename type >
void display( type val ){
    cout << "Case #" << test << ": " << val << endl;
    test++;
}

void solve(){

    lli n,p;
    cin >> n >> p;
    
    vector<vector<lli>> a1(n ,vector<lli> (p))  ,a2(n ,vector<lli> (p));
    vector<pair<lli, lli>> dp(2 ,make_pair(0,0));
    
    for(int i=0 ;i<n ;i++){
        vector<pair<lli, lli>> tmp(2 ,make_pair(LLONG_MAX,LLONG_MAX));
        for( int j=0 ;j<p ;j++ ) cin >> a1[i][j];

        sort(all(a1[i]));
        a2[i]=a1[i];
        reverse(all(a2[i]));

        auto &v1=a1[i] ,&v2=a2[i];
        for(int j=0 ;j<2 ;j++){
            lli st=dp[j].first ,sc=dp[j].second;
            for(auto &x : v1){
                sc += abs(st-x);
                st = x;
            }
            if(tmp[0].second > sc){
                tmp[0] = {st,sc};
            }
        }
        
        for(int j=0 ;j<2 ;j++){
            lli st=dp[j].first ,sc=dp[j].second;
            for(auto &x : v2){
                sc += abs(st-x);
                st = x;
            }
            if(tmp[1].second>sc){
                tmp[1] = {st ,sc};
            }
        }
        dp.swap(tmp);
    }

    cout << min(dp[0].second,dp[1].second) << '\n';
}

int32_t main(){   
    cin.tie(0), cin.sync_with_stdio(0);
    int t=1;
    cin >> t;

    while(t--){
        solve();
    }
}