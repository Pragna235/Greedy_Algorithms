#include<iostream>
#include<limits.h>
using namespace std;
#define V 9

// If there is no path, then it is represented by 0 (in this program)

int min_distance(int dist[], bool sptSet[])
{
    int min=INT_MAX, min_index;

    for(int i=0;i<V;i++){
        if(sptSet[i]==false && dist[i]<=min) // Intially, min_index will be the source vertex
            min=dist[i],min_index=i;
    }

    return min_index;

}

void printSolution(int dist[],int src)
{
    cout << "\nFinal Array with Shortest Paths is \n" << endl;
    for (int i = 0; i < V; i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

void dijkstra(int graph[V][V],int src)
{
    int dist[V];
    bool sptSet[V];

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<V-1;i++){

        int u = min_distance(dist,sptSet);

        sptSet[u]=true;

        for(int v=0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]  )
                dist[v]=dist[u]+graph[u][v];

        }

    }
     printSolution(dist,src);




}

int main()
{
     int src, graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, //no path is represented with 0
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


     cout<<"Enter the Source Vertex : "<<endl;
     cin>>src;
     dijkstra(graph,src);
}
