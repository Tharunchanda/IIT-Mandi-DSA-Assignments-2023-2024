#include <iostream>
#include <vector>

using namespace std;

class Graph_Matrix {
private:
    int size;
    vector<vector<int>> adjMatrix;
    bool directed;

public:
    Graph_Matrix(int n, bool isDirected) : size(n), directed(isDirected){
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    void addEdge(int v1, int v2){
        adjMatrix[v1][v2] = 1;
        if (!directed){
            adjMatrix[v2][v1] = 1;}
    }

    void removeEdge(int v1, int v2){
        adjMatrix[v1][v2] = 0;
        if (!directed){
            adjMatrix[v2][v1] = 0;}
    }

    void printMatrix() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << adjMatrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    int inDegree(int v) {
        int degree = 0;
        for (int i = 0; i < size; ++i){
            degree += adjMatrix[i][v];
        }
        return degree;
    }

    int outDegree(int v){
        int degree = 0;
        for (int j = 0; j < size; ++j) {
            degree += adjMatrix[v][j];
        }
        return degree;
    }
};

class Graph_List {
private:
    int size;
    vector<vector<int>> adjList;
    bool directed;

public:
    Graph_List(int n, bool isDirected) : size(n), directed(isDirected) {
        adjList.resize(n);
    }

    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        if (!directed)
            adjList[v2].push_back(v1);
    }

    void printList() {
        for (int i = 0; i < size; ++i) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << ' ';
            }
            cout << '\n';
        }
    }

    int inDegree(int v) {
        int degree = 0;
        for (int i = 0; i < size; ++i) {
            for (int neighbor : adjList[i]) {
                if (neighbor == v)
                    degree++;
            }
        }
        return degree;
    }

    int outDegree(int v) {
        return adjList[v].size();
    }
};

int main() {
    Graph_Matrix directedMatrix(4, true);
    directedMatrix.addEdge(0, 1);
    directedMatrix.addEdge(1, 2);
    directedMatrix.addEdge(2, 3);
    directedMatrix.printMatrix();

    for (int i = 0; i < 4; ++i) {
        cout << "In-degree of vertex " << i << ": " << directedMatrix.inDegree(i) << endl;
        cout << "Out-degree of vertex " << i << ": " << directedMatrix.outDegree(i) << endl;
    }

    Graph_Matrix undirectedMatrix(4, false);
    undirectedMatrix.addEdge(0, 1);
    undirectedMatrix.addEdge(1, 2);
    undirectedMatrix.addEdge(2, 3);
    undirectedMatrix.printMatrix();

    for (int i = 0; i < 4; ++i) {
        cout << "In-degree of vertex " << i << ": " << undirectedMatrix.inDegree(i) << endl;
        cout << "Out-degree of vertex " << i << ": " << undirectedMatrix.outDegree(i) << endl;
    }

    Graph_List directedList(4, true);
    directedList.addEdge(0, 1);
    directedList.addEdge(1, 2);
    directedList.addEdge(2, 3);
    directedList.printList();

    for (int i = 0; i < 4; ++i) {
        cout << "In-degree of vertex " << i << ": " << directedList.inDegree(i) << endl;
        cout << "Out-degree of vertex " << i << ": " << directedList.outDegree(i) << endl;
    }

    Graph_List undirectedList(4, false);
    undirectedList.addEdge(0, 1);
    undirectedList.addEdge(1, 2);
    undirectedList.addEdge(2, 3);
    undirectedList.printList();

    for (int i = 0; i < 4; ++i) {
        cout << "In-degree of vertex " << i << ": " << undirectedList.inDegree(i) << endl;
        cout << "Out-degree of vertex " << i << ": " << undirectedList.outDegree(i) << endl;
    }

    return 0;
}
