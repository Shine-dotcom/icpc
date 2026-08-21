#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
const int N=1e6+10,inf=1e9+7;
struct node
{
    int x,y;
    bool operator<(const node&w) const 
    {
        return y>w.y;
    }
};
node a[N];
int tr[N],len;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int k)
{
    while(x<=len)
    {
        tr[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=tr[x];
        x-=lowbit(x);
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    len=n+m;
    for(int i=n;i;i--)
    {
        add(i,1);
        cin>>a[i].y;
        a[i].x=i;
    }
    for(int i=n+1;i<=len;i++)
    {
        add(i,1);
        cin>>a[i].y;
        a[i].x=i;
    }
    sort(a+1,a+1+len);
    a[0].x=n;
    for(int i=1;i<=len;i++)
    {
        int id1=a[i].x,id2=a[i-1].x;
        add(id1,-1);
        ans+=abs(sum(id1)-sum(id2));
        cout << "111: " << sum(id1) << ' ' << sum(id2) << endl;
        cout << "222: " << id1 << ' ' << id2 << endl;
    }
    cout<<ans<<endl;
    return 0;
}