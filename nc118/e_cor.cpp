#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9; 

int n,m,da[N],db[N],t,a,b;
vector<int>g[N];

void dfs(int st,int num,int d[]){
	//for(int i=0;i<=n;i++) d[i]=-1;
	for(int i=0;i<g[st].size();i++){
		if(d[g[st][i]]==-1){
			d[g[st][i]]=num;
			num++;
			dfs(g[st][i],num,d);
			num--;
		}
	}
} 

void bfs(int st,int d[]){
    // 求各个点到st距离 d[]存
    for(int i=0;i<=n;i++) d[i]=-1;  
    queue<int>q;
    q.push(st);
    d[st]=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto i:g[t]){
            if(d[i]==-1){  
                d[i]=d[t]+1;
                q.push(i);
            }
        }
    }
}

signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int c1,c2;
            cin>>c1>>c2;
            g[c1].push_back(c2);
            g[c2].push_back(c1);
        }
        for(int i=0;i<=n;i++) da[i]=-1;
        da[a]=0;
        for(int i=0;i<=n;i++) db[i]=-1;
        db[b]=0;
        dfs(a,1,da);
        dfs(b,1,db);
        /*for(int i=0;i<=n;i++) cout<<da[i]<<' ';
        cout<<endl;
        for(int i=0;i<=n;i++) cout<<db[i]<<' ';
        bfs(a,da);
        bfs(b,db);
        for(int i=0;i<=n;i++) cout<<da[i]<<' ';
        cout<<endl;
        for(int i=0;i<=n;i++) cout<<db[i]<<' ';*/
        bool fd=0;
        // 检查所有叶子节点
        for(int i=1;i<=n;i++){
            if(g[i].size()==1)
            if(da[i]*2<=db[i]){
                fd=1;
                break;
            }
        }
        
        if(fd) cout<<"red\n";
        else cout<<"purple\n";
    }
    return 0;
	
}