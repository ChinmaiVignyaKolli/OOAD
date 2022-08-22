// A C++ program to find articulation points in an undirected graph
#include<iostream>
#include<list>

#include<fstream>
#define NIL -1
using namespace std;
#include<stdlib.h>
 
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void APUtil(int v, bool visited[], int disc[], int low[], 
                int parent[], bool ap[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void AP();    // prints articulation points
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 

void Graph::APUtil(int u, bool visited[], int disc[], 
                                      int low[], int parent[], bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
               ap[u] = true;
 
            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; // To store articulation points
 
    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
 
    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
 
    // Now ap[] contains articulation points, print them
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << endl;
}
 
// Driver program to test above function
int main()
{
	int n,a,b;
	
	/*fstream out;
	out.open("test.txt",ios::in);
	out>>n;
	Graph g1(n);
	while(!out.eof())
	{
	if(a<100)
	{
	out>>a;
	out>>b;
    g1.addEdge(a, b);
    //cout<<a<<endl<<b<<endl;
    }
    }
    g1.AP();
    
    out.close();*/
    
    /*Graph g1(6);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);*/
    Graph g(17);
    g.addEdge(0,1);//g.addEdge(1,0);
    g.addEdge(0,2);//g.addEdge(2,1);
    g.addEdge(0,3);//g.addEdge(3,1);
    g.addEdge(0,6);//g.addEdge(3,2);
    g.addEdge(5,6);//g.addEdge(4,2);
    g.addEdge(5,4);//g.addEdge(4,3);
    g.addEdge(6,4);//g.addEdge(5,1);
    g.addEdge(9,6);//g.addEdge(6,0);
    g.addEdge(7,6);//g.addEdge(6,5);
    g.addEdge(8,7);//g.addEdge(7,5);
    g.addEdge(10,9);//g.addEdge(8,5);
    g.addEdge(10,11);//g.addEdge(8,7);
    g.addEdge(10,12);//g.addEdge(9,8);
    g.addEdge(13,11);//g.addEdge(11,10);
    g.addEdge(13,14);
    g.addEdge(12,14);
    g.addEdge(14,16);
    g.addEdge(14,15);
    
    g.AP();
     
    return 0;
}
