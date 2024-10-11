#include <iostream>
#include <vector>

using namespace std;
//19:32

int numPossibleVertex = 0;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int vertex){
    for(int i = 0; i < graph[vertex].size() ; i++){
        int currV = graph[vertex][i];
        if(!visited[currV]){
            visited[currV] = true;
            numPossibleVertex++;
            DFS(graph, visited, currV);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, 0);

    for(int i = 0 ; i < m ; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int rootVertex = 1;
    visited[rootVertex] = true;
    DFS(graph, visited, rootVertex);

    cout << numPossibleVertex;

    return 0;

}