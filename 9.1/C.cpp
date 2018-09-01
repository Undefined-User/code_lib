#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int maxm = 20005;
const int maxn = 205;
int T,n,m;
int card_stack[maxm],card[maxn][15],cnt[maxn],tot,ans[maxn];
//�ƿ� ���� ÿ���˵������� ��ǰ�ƿ�״̬ ��
void init()
{
    tot = 0;
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));
    memset(card,0,sizeof(card));
    memset(card_stack,0,sizeof(card));
}
void print(int x)
{
    printf("Case #%d:\n",x);
    for(int i = 0; i < n; i++)
        if(ans[i]) printf("%d\n",ans[i]);
        else printf("Winner\n");
}
void start(int x, int num)//���ƣ��ӵ�x���˿�ʼ����һ�ֳ��ƣ�ÿ�˳�num����
{
    if(tot>=m)return;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < num; j++)
        if(tot<m)
        {
            card[(x+i)%n][card_stack[tot++]]++,cnt[(x+i)%n]++;
        }
}
pair<int,int> play(pair<int,int> pre, int x)//first:��һ������id second:��һ�ų�����
{
    //cout<<pre.first<<' '<<pre.second<<' '<<x<<endl;
    if(pre.second == -1)//û��ǰһ����
    {
        pre.first = x;
        for(int i = 0; i < 13; i++)
        {
            int t = (3+i)>13?3+i-13:3+i;
            if(card[x][t])
            {
                cnt[x]--;
                card[x][t]--;
                pre.second = t;
                break;
            }
        }
        if(cnt[x]==0) return make_pair(x,0);
        else return pre;
    }
    int t = pre.second==13?1:pre.second+1;
    if(x==pre.first)
    {
        start(x,1);
        return play(make_pair(0,-1),x);
    }
    if(pre.second == 2 || (card[x][t]==0 && card[x][2]==0))//�޷�����
    {
        if(x==pre.first)
        {
            start(x,1);
            return play(make_pair(0,-1),x);
        }
        return pre;
    }
    pre.first = x;
    cnt[x]--;
    if(card[x][t])
    {
        card[x][t]--;
        pre.second = t;
    }
    else {
        card[x][2]--;
        pre.second = 2;
    }
    if(cnt[x]==0) pre.second = 0;
    return pre;
}
void solve()
{
    start(0,5);
    int x = 0;
    pair<int,int> y = make_pair(0,-1);
    while(y.second != 0)
    {
        y = play(y,x);
        x = (x+1)%n;
    }
    //����
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= 13; j++)
            ans[i] += card[i][j]*j;
}
int main()
{
    scanf("%d",&T);
    for(int i = 1; i <= T; i++)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int j = 0; j < m; j++)
            scanf("%d",&card_stack[j]);
        solve();
        print(i);
    }
}
