#include <bits/stdc++.h>
using namespace std;

int parent[1000],Rank[1000];

void Make_Set(int x){
    parent[x]=x;
    Rank[x]=0;
}

int Find(int x){
    if(x!=parent[x]) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(Rank[PX]>Rank[PY])
        parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(Rank[PX]==Rank[PY])
            Rank[PY]++;
    }
}

int main(){
    int t,n,succ,unsucc,a,b;
    char c;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d\n\n",&t);
    while(t--)
    {
        succ=unsucc=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) Make_Set(i);
        string line;
        cin.ignore();
        getline(cin,line);
        while(line!="")
        {
            stringstream strm;
            strm<<line;
            strm>>c;
            strm>>a;
            strm>>b;
            a--;
            b--;
            if(c=='c')
            {
                if(Find(a)!=Find(b))
                {
                    Union(a,b);
                }

            }
            if(c=='q')
            {
                if(Find(a)!=Find(b))
                {
                    unsucc++;
                }
                else
                {
                    succ++;
                }
            }
            //if(cin.peek()==EOF)
            //line="";
            //else
                getline(cin,line);
        }
        printf("%d,%d\n",succ,unsucc);
        if(t!=0)
            printf("\n");
    }

    return 0;
}
