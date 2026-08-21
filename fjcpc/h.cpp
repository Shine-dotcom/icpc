#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        int ans1=0,ans2=0;
        int tep = m;
        
        if(m >= n % 3 && n %3 != 0){
            m -= n % 3;
            ans1++;
        }
        ans1+=m/3;
        cout << ans1 << " ";

        int k2 = (n+9)/10;
        if(n%10<6 && n%10!=0){
            k2--;
        }
        ans2 = min(tep/6,k2);
         cout << ans2 << endl;

        
        
    }

    



    return 0;
}