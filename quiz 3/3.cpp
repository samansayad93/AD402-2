#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Edge{
    int src,dest,weight;
};

struct Subset
{
    int rank,parent;
};

int find(vector<Subset> &subsets, int i){
    if(subsets[i].parent != i){
        return find(subsets,subsets[i].parent);
    }
    return i;
}

void Union(vector<Subset> &subsets,int x,int y){
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

bool compareEdge(const Edge &edge1, const Edge &edge2){
    return edge1.weight > edge2.weight;
}

int findMST(vector<Edge> &edges,int n, int from, int to){
    sort(edges.begin(),edges.end(),compareEdge);

    vector<Subset> subsets(n);
    for(int i=0;i<n;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int speed = INT32_MAX;

    for(const Edge edge : edges){
        int x = find(subsets,edge.src);
        int y = find(subsets,edge.dest);

        if(find(subsets,from) == find(subsets,to)){
            return speed;
        }

        if(x != y){
            Union(subsets,x,y);
            if(speed > edge.weight){
                speed = edge.weight;
            }
        }
    }
    return -1;
}


int main(){
    int n,m;
    cin>>n>>m;

    int src,dest,weight;

    vector<Edge> edges(m);

    for(int i=0;i<m;i++){
        cin>>src>>dest>>weight;

        edges[i].src = src-1;
        edges[i].dest = dest-1;
        edges[i].weight = weight;
    }

    cout<<findMST(edges,n,0,n-1)<<endl;
}