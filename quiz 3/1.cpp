#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int src,dest,weight;

    //Edge(int _src,int _dest,int _weight) : src(_src), dest(_dest), weight(_weight) {}
};


struct subset{
    int rank,parent;
};

int find(vector<subset> &subsets,int x){
    if(subsets[x].parent != x){
        return find(subsets,subsets[x].parent);
    }
    return x;
}

void Union(vector<subset> &subsets, int x, int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdge(const Edge &edge1,const Edge &edge2){
    return edge1.weight < edge2.weight;
}

int FindMST(vector<Edge> &edges,int n){
    sort(edges.begin(),edges.end(),compareEdge);

    vector<subset> subsets(n);
    for(int i=0;i<n;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int cost = 0;
    for(const Edge &edge : edges){
        int x = find(subsets,edge.src);
        int y = find(subsets,edge.dest);

        if(x != y){
            Union(subsets,x,y);
            cost += edge.weight;
        }
    }

    return cost;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<Edge> edges(m+n);

    int src,dest,weight;

    for(int i=1;i<=n;i++){
        cin>>weight;
        edges[i-1].src = 0;
        edges[i-1].dest = i;
        edges[i-1].weight = weight;
    }

    for(int i=n;i<m+n;i++){
        cin>>src>>dest>>weight;
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }

    int cost = FindMST(edges,n+1);

    cout<<cost<<endl;
}