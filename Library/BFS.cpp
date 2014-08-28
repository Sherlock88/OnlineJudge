#include <iostream>
#include <vector>
#include <list>

using namespace std;


// This class represents a (un)-directed graph using adjacency list representation
class Graph
{
    int V;    		   			// No. of vertices
    list<int> *adj;    			// Pointer to an array containing adjacency lists
	
	public:
    Graph(int V);  	   			// Constructor
    void addEdge(int v, int w); // Function to add an edge to graph
    bool BFS(int s, int t);     // Prints BFS traversal from a given source 's'
};


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);		// Add w to v’s list
	adj[w].push_back(v);		// Add v to w’s list
}


bool Graph::BFS(int s, int t)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
		cout << s << ' ';
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex 's'
        // If an adjacent vertex has not been visited, then mark
        // it visited and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
			if(*i == t)
				return true;
			if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
	cout << endl;
	return false;
}


/* Driver Routine */
int main()
{
	Graph graph(5);
	
	// Vertices are indexed from zero	
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(2, 0);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);
	graph.BFS(1, 4);
	
	return 0;
}