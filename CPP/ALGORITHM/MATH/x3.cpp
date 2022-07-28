#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

double a, b, c, d;

void solve() {
	double x, x1, x2, x3;
	double A=b*b-3*a*c;  //第一重根判别式
    double B=b*c-9*a*d;  //第二重根判别式
    double C=c*c-3*b*d;  //第三重根判别式
    double del=B*B-4*A*C;  //总判别式
    if(A==B&&A==0)    //如果A=0且B=0
    {
        x1=x2=x3=(-1*b/(3*a));  //x1,x2,x3的值相同......
    }
    else if(del==0)   //如果△=0,x2与x3相同......
    {
        x1=(-1*b/a)+B/A;
        x2=x3=-1*B/A/2;
    }
    else if(del<0)  //如果△<0，有三实根......
    {
        double T=(2*A*b-3*B*a)/(2*A*sqrt(A));
        double _xt=acos(T);
        double xt=_xt/3;
        x1=(-1*b-2*sqrt(A)*cos(xt))/(3*a);
        x2=(-1*b+sqrt(A)*(cos(xt)+sqrt(3)*sin(xt)))/(3*a);
        x3=(-1*b+sqrt(A)*(cos(xt)-sqrt(3)*sin(xt)))/(3*a);
    }//由于题目说了只会出现实根，因此只有以上三种情况
    if(x1>x2)
    {
        x=x1;
        x1=x2;
        x2=x;
    }
    if(x1>x3)
    {
        x=x3;
        x3=x1;
        x1=x;
    }
    if(x2>x3)
    {
        x=x3;
        x3=x2;
        x2=x;
    }//题目要求从小到大输出三实根，进行排序。
    printf("%.2lf %.2lf %.2lf",x1,x2,x3);
}

signed main() {
	//freopen("C:\\Users\\Luther\\iCloudDrive\\CODEs\\VSCode\\in.txt", "r", stdin);

	//std::ios::sync_with_stdio(false);
	//cin.tie(NULL), cout.tie(NULL);

	solve();

	//fclose(stdin);
	return 0;
}
