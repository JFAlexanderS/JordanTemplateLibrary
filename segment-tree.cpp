const int MAXN=0, DEFAULT=0;

int N;
int segmentTree[MAXN*2+5];

void build(int combine(int, int) )
{
    for(int i=N-1; i; i--)
        segmentTree[i]=combine(segmentTree[i*2], segmentTree[i*2+1]);
}

void update(int p, int v, int combine(int, int))
{
    segmentTree[p+N]=v;
    for(int i=(p+N)/2; i; i/=2)
        segmentTree[i]=combine(segmentTree[i*2], segmentTree[i*2+1]);
}

int query(int l, int r, int combine(int, int))
{
    int leftRes=DEFAULT, rightRes=DEFAULT;
    for(l+=N, r+=N; l<r; l/=2, r/=2)
    {
        if(l&1)
            leftRes=combine(leftRes, segmentTree[l++]);
        if(r&1)
            rightRes=combine(segmentTree[--r], rightRes);
    }
    return combine(leftRes, rightRes);
}
