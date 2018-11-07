#include<bits/stdc++.h>
using namespace std;
#define MAX 99999999
#define ll long long
#define mx 1000000
ll arr[mx];
ll tree[3*mx];
void init(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return;
    }

    ll lnode=2*node;
    ll rnode=2*node+1;
    ll mid=(l+r)/2;
    init(lnode,l,mid);
    init(rnode,mid+1,r);
    tree[node]=min(tree[lnode],tree[rnode]);
}
ll query(ll node,ll l,ll r,ll ql,ll qr)
{
    if(ql>r||qr<l)
        return MAX;
    if(l>=ql&&r<=qr)
        return tree[node];
    ll lnode=2*node;
    ll rnode=2*node+1;
    ll mid=(l+r)/2;
    ll x=query(lnode,l,mid,ql,qr);
    ll y=query(rnode,mid+1,r,ql,qr);
    return min(x,y);
}
int main()
{
    ll t;
    scanf("%lld",&t);
    for(int i=1; i<=t; i++)
    {
        getchar();
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(int j=1; j<=n; j++)
            scanf("%ld",&arr[j]);
        printf("Case %d:\n",i);
        init(1,1,n);
        while(q--)
        {
            ll x,y;
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",query(1,1,n,x,y));

        }
    }

}

