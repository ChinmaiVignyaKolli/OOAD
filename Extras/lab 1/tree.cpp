#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
#include <stdio.h>
#include <stdlib.h>


const int TABLE_SIZE = 30;
int initial_eclass[10];

class HashNode

{

    public:

     int key;

    int value;

    HashNode* next;

        HashNode(int key, int value)

        {

            this->key = key;

        this->value = value;

        this->next = NULL;

        }

};

class HashMap

{

    private:

        HashNode** htable;

    public:

        HashMap()

        {

            htable = new HashNode*[TABLE_SIZE];

            for (int i = 0; i < TABLE_SIZE; i++)

                htable[i] = NULL;

        }

        ~HashMap()

        {

            for (int i = 0; i < TABLE_SIZE; ++i)

        {

                HashNode* entry = htable[i];

                while (entry != NULL)

            {

                    HashNode* prev = entry;

                    entry = entry->next;

                    delete prev;

                }

            }

            delete[] htable;

        }

        /*

         * Hash Function

         */

        int HashFunc(int key)

        {

            return key % TABLE_SIZE;

        }

        void Insert(int key, int value)

        {

            int hash_val = HashFunc(key);

            HashNode* prev = NULL;

            HashNode* entry = htable[hash_val];

            while (entry != NULL)

            {

                prev = entry;

                entry = entry->next;

            }

            if (entry == NULL)

            {

                entry = new HashNode(key, value);

                if (prev == NULL)

            {

                    htable[hash_val] = entry;

                }

            else

            {

                    prev->next = entry;

                }

            }

            else

            {

                entry->value = value;

            }

        }

        /*

         * Remove Element at a key

         */

        int Remove(int key)

        {

            int hash_val = HashFunc(key);

            HashNode* entry = htable[hash_val];

            HashNode* prev = NULL;

            if (entry == NULL || entry->key != key)

            {

                cout<<"No Element found at key "<<key<<endl;

                return 0;

            }

            while (entry->next != NULL)

            {

                prev = entry;

                entry = entry->next;

            }

            if (prev != NULL)

            {

                prev->next = entry;

            }
            
            //return entry->dest;

            delete entry;

            cout<<"Element Deleted"<<endl;

        }

        /*

         * Search Element at a key

         */

        int Search(int key)

        {

            bool flag = false;

            int hash_val = HashFunc(key);

            HashNode* entry = htable[hash_val];

            while (entry != NULL)

        {

                if (entry->key == key)

            {

                    cout<<entry->value<<" ";

                    flag = true;

                }

                entry = entry->next;

            }

            if (!flag)

                return -1;

        }

};


 

        /*

         * Insert Element at a key

         */

// A structure to represent an adjacency list node
struct AdjListNode
{
    int dest;
    int degree;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    
     newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v <= graph->V; ++v)
    { 
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        int deg=0;
        while (pCrawl)
        {
         cout<< pCrawl->dest<<"\n";
           deg++;
            pCrawl = pCrawl->next;           
            
            
        }
        
        graph->array[v].head->degree=deg;
        printf("degree is %d  \n",deg);
    }
}

bool check_representative(AdjListNode* n) {
    if(n->degree>=3) {
        return true;
    }
    else {
        return false;
    }
}


int visited[20]={0};
std::vector<int> l;

void dfs(Graph* graph, int v)
{ 
    int i, j,key,key1,deg;
    visited[v]=1;
    static AdjListNode* rep_par=graph->array[1].head;
    static AdjListNode* normal_par=graph->array[1].head;
    static int rep_par_num = 1;
    static int normal_par_num = 1;
    AdjListNode* temp_node=graph->array[v].head;
    
    if(check_representative(normal_par)) {
        rep_par = normal_par;
        rep_par_num = normal_par_num;
        deg=rep_par->degree;
    }
    if(v->degree==1)     {
    cout<<"Present node :"<<v<<endl;
    //cout<<"Parent node : "<<normal_par_num<<endl;
    cout<<"Representative Node : "<<rep_par_num<<endl<<endl;
    hash(rep_par_num,v);
    hash1(rep_par_num,deg);
    }  
    while(temp_node!=NULL)  {
        if(!visited[temp_node->dest])         {                 
             normal_par = temp_node;
             normal_par_num = v;
            dfs(graph,temp_node->dest);   
        }                  
         temp_node=temp_node->next;        
    }   
 }
        



void set_up_eclass(struct Graph* graph)
{
   HashMap hash, hash1;

    int key, value;

    int choice;

    while (1)

    {

        cout<<"\n----------------------"<<endl;

        cout<<"Operations on Hash Table"<<endl;

        cout<<"\n----------------------"<<endl;

        cout<<"1.Insert elements into the table"<<endl;

        cout<<"2.Search element from the key"<<endl;

        cout<<"3.Delete element at a key"<<endl;

        cout<<"4.Exit"<<endl;

        cout<<"Enter your choice: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            dfs(graph,1);
            /*hash1.Insert(key, value); /*storing the degree with the representataive vertex*/
           /* hash.Insert(key,value);*/ /*storing the leaf nodes associated with representative vertex*/

            break;

        case 2:

            cout<<"Enter key of the element to be searched: ";

            cin>>key;

            cout<<"Element at key "<<key<<" : ";

            if (hash.Search(key) == -1)

            {

            cout<<"No element found at key "<<key<<endl;

            continue;

        }

            break;

        case 3:

            cout<<"Enter key of the element to be deleted: ";

            cin>>key;

            hash.Remove(key);

            break;

        case 4:

            exit(1);

        default:

           cout<<"\nEnter correct option\n";

       }

    }

}

/* int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[5] = {0};
 
    // Store count of occurrences in count[]
    for (i = 1; i < n; i++)
        count[ (arr[i]/exp)%5 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 5; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i > 0; i--)
    {
        output[count[ (arr[i]/exp)%5 ] - 1] = arr[i];
        count[ (arr[i]/exp)%5 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
    

void sort_degree(struct Graph* graph)
{
int j,v,i;
j=0;
for (v = 1; v <= graph->V; ++v)
    { 
        
        initial_active_eclass[j]=graph->array[v].head->degree;
     
        j++;
     }
    


radixsort(initial_active_eclass,20);

for(i=0;i<21;i++)
{
//initial_active_eclass[i]=initial_active_eclass[20-i];
//initial_active_eclass[20]=0;
cout<<initial_active_eclass[i]<<endl;
}

}
     

    
 
*/
int main()
{
    // make the adjacency list and store its degree
    int V = 20,j=0;
    
    struct Graph* graph = createGraph(V);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 3, 8);
    addEdge(graph, 4, 9);
    addEdge(graph, 4, 10);
    addEdge(graph, 5, 11);
    addEdge(graph, 11,16);
    addEdge(graph, 12, 9);
    addEdge(graph, 12, 17);
    addEdge(graph, 10, 13);
    addEdge(graph, 10, 14);
    addEdge(graph, 10, 15);
    addEdge(graph, 14, 18);
    addEdge(graph, 15, 19);
    addEdge(graph, 20, 18);    
    
    
    
    printGraph(graph);
    
    set_up_eclass(graph);
  
    
    
       
       
    
    
    
    
    return 0;
}
