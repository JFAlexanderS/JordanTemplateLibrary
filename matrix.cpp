const int MAXS;

struct matrix
{
  long long m[MAXS][MAXS];

  void add(const matrix &a)
  {
    for(int i=0; i<MAXS; i++)
      for(int j=0; j<MAXS; j++)
        m[i][j]+=a.m[i][j];
  }

  void copy(const matrix &a)
  {
    for(int i=0; i<MAXS; i++)
      for(int j=0; j<MAXS; j++)
        m[i][j]=a.m[i][j];
  }

  void multiply(const matrix &a, matrix h)
  {
    for(int i=0; i<MAXS; i++)
      for(int j=0; j<MAXS; j++)
        for(int k=0; k<MAXS; k++)
          h.m[i][j]+=(m[i][k]*a.m[k][j]);
    copy(h);
  }

  void pow(matrix s, long long p, matrix e)
  {
    for(p--; p; p/=2)
    {
      if(p%2)
        multiply(s, e);
      s.multiply(s, e);
    }
  }
}
