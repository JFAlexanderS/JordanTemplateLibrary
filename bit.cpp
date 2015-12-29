const int MAXN=100000;

int bit[MAXN+5];

void upd(int pos, int val)
{
    for(; pos<=MAXN; pos+=pos&-pos)
        bit[pos]+=val;
}

int csum(int pos)
{
    int res=0;
    for(; pos; pos-=pos&-pos)
        res+=bit[pos];
    return res;
}
