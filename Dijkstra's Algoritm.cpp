//Dijkstra's algorithm for directed graph.
#include<iostream>
#include"Priority Queue.cpp"
#include<fstream>
#define s 10
using namespace std;
int V;
int E;
int start;
int graph[s][s];
void input(){
    ifstream fp("Dijkstra Input Matrix.txt");
    fp>>V;
    fp>>E;
    fp>>start;
    graph[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            fp>>graph[i][j];
    //Printing the adjacency matrix
    cout<<"The adjacency matrix is :\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dijkstra(){
    int dist[V];
    int pred[V];
    bool sptSet[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        pred[i]=0;
        sptSet[i]=false;
    }
    dist[start]=0;
    for(int i=0;i<V;i++)
        insertKey(dist[i]);
    while(!isEmpty()){
        int u=extractMinimum();
        int x;
        for(x=0;x<V;x++){
            if(dist[x]==u && sptSet[x]==false){
                break;
            }
        }
        sptSet[x]=true;
        for(int i=0;i<V;i++){
            if(graph[x][i]!=0){
                if(sptSet[i]==false && dist[x]+graph[x][i]<dist[i]){
                    dist[i]=dist[x]+graph[x][i];
                    decreaseKey(i,dist[i]);
                    pred[i]=x;
                }
            }
        }
    }
    //Printing
    cout<<"The source is : "<<start<<endl;
    cout<<"vertex       Dist. from source\n";
    for(int i=0;i<V;i++){
        cout<<i<<"            "<<dist[i]<<endl;
    }
}
int main(){
    input();
    dijkstra();
}

