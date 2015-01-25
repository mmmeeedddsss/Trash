#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int adj[30][30];
int V,E;
int max_c;
char path[30];
char visit[30];

void printPath(char cur, ostream& oup)
{
    if(path[cur] == cur)
    {
        oup << (char)(cur+'A');
        return;
    }
    printPath(path[cur], oup);
    oup << "-" << (char)(cur+'A');
}

void dfs(char cur, char end, int c, char *cpath)
{
    if(visit[cur] == 1)
        return;
    if(cur==end)
    {
        if(c>max_c)
        {
            max_c = c;
            memcpy(path, cpath, 30);
        }
        return;
    }
    visit[cur] = 1;
    for(int i=0;i<30;i++)
    {
        if(adj[cur][i] != 0)
        {
            char old = cpath[i];
            cpath[i] = cur;
            dfs(i, end, c+adj[cur][i], cpath);
            cpath[i] = old;
        }
    }
    visit[cur]= 0;
}

int main()
{
    ifstream inp("alavere.gir");
    ofstream oup("alavere.cik");
    inp >> V >> E;
    char e1,e2;
    int cost;
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)
            adj[i][j] = 0;
    for(int i=0;i<E;i++)
    {
        inp >> e1 >> e2 >> cost;
        adj[e1-'A'][e2-'A'] = adj[e2-'A'][e1-'A'] = cost;
    }
    inp >> e1 >> e2;
    dfs(e1-'A', e2-'A', 0, new char[30]);
    path[e1-'A'] = e1-'A';
    printPath(e2-'A', oup);
    oup << " : " << max_c << endl;
    return 0;
}
