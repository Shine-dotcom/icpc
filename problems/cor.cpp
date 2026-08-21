#include <iostream>
#include <cstdio>
using namespace std;
int t,x,y,z,f[2007][15][35],m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
//，m数组存储每个月有多少天
bool vis[2007][15][35];
bool check(int year,int month,int day){//判断是否超过目标日期
	if(year<2006)
		return true;
	if(year==2006 && month<11)
		return true;
	if(year==2006 && month==11 && day<4)
		return true;
    return false;
}
int dfs(int year,int month,int day){
    if((year%4!=0 || year==1900) && month==2 && day==29)
		return 1;
    if(day>m[month])//若天数超过当前月的，则说明到了下一个月
		month++,day=1;//月份++，从1号重新开始
    if(month>12)//若已经超过了12个月，说明到了下一年
		year++,month=1;//年份++，从1月重新开始
    //说句闲话：相当于进位（？）
    if(vis[year][month][day])//如果已经查找过直接返回结果即可
		return f[year][month][day];
	vis[year][month][day]=1;//标记为已查找
    if(day<=m[month+1] && check(year,month+1,day))//注意，这里有个小细节：如果要改变月份，应先判断一下当前天数是否下一个月的天数（因为每个月的天数不一样）
		f[year][month][day]=((dfs(year,month+1,day))^1);//^1相当于取反，若是为1则返回0，若是为0则返回1
    if(check(year,month,day+1))
		f[year][month][day]|=((dfs(year,month,day+1)^1));
    return f[year][month][day];
}

int main(){
    f[2006][11][3]=1;
    dfs(1900,1,1);//从1900年1月1日开始搜索
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&z);
        if(f[x][y][z])
        	printf("YES\n");
        else
        	printf("NO\n");
    }
    return 0;
}
