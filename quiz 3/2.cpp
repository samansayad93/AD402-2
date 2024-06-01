#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

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
    return edge1.weight < edge2.weight;
}

// bool DFS(vector<Edge> &edges,map<Edge,bool> &deleted,int from,int goal){

// }

long findMST(vector<Edge> &edges,int n, int from, int to){
    sort(edges.begin(),edges.end(),compareEdge);

    vector<Subset> subsets(n);
    for(int i=0;i<n;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    long cost = 0;

    //map<Edge,bool> deleted;

    for(const Edge edge : edges){
        int x = find(subsets,edge.src);
        int y = find(subsets,edge.dest);

        // if(DFS(edges,deleted,from,to)){
        //     return cost;
        // }

        if(find(subsets,from) == find(subsets,to)){
            return cost;
        }
        
        if(x != y){
            Union(subsets,x,y);
        }
        cost += edge.weight;
        //deleted[edge] = true;
    }
    return cost;
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

    long totalcost = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            totalcost += findMST(edges,n,i,j)%1000000000;
        }
    }

    //totalcost = findMST(edges,n,1,2);

    cout<<totalcost<<endl;
}