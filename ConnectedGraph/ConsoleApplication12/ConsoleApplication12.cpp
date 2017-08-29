// ConsoleApplication12.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stack>
#include <list>  
  
   
  
bool visitedg[ 100000 ];  
   
class givGraph  
{  
    int V;      
    bool directedgraph;  
    std::list<int> *adjacent;      
   
    
    void DFSgr(int v, bool visited[]);  
public:  
      
     givGraph(int V, bool directedgraph)   
    {   
        this->V = V;    
        this->directedgraph = directedgraph;  
        adjacent = new std::list<int>[V];  
    }  
    ~ givGraph() { delete [] adjacent; }  
   
      
    void addededg(int v, int w);  
   
      
    bool isSC();  
   
    
     givGraph* getTranspose();  
};  
   
 
void  givGraph::DFSgr(int v, bool visitedg[])  
{  
   
    visitedg[v] = true;  
   
   
   
    std::list<int>::iterator i;  
    for (i = adjacent[v].begin(); i != adjacent[v].end(); ++i)  
        if (!visitedg[*i])  
            DFSgr(*i, visitedg);  
}  
   
 
 givGraph*givGraph::getTranspose()  
{  
     givGraph* g = new  givGraph(V, directedgraph);  
    for (int v = 0; v < V; v++)  
    {  
        std::list<int>::iterator i;  
        for(i = adjacent[v].begin(); i != adjacent[v].end(); ++i)  
        {  
            g->adjacent[*i].push_back(v);                       
        }  
    }  
    return g;  
}  
   
void givGraph::addededg(int v, int w)  
{  
    adjacent[v].push_back(w);   
   
    if ( !directedgraph) adjacent[w].push_back(v);   
}  
   
 
bool  givGraph::isSC()  
{  
      
       
    for (int i = 0; i < V; i++)  
        visitedg[i] = false;  
   
      
    DFSgr(0, visitedg);  
   
       
    for (int i = 0; i < V; i++)  
        if (visitedg[i] == false)  
             return false;  
   
     
     givGraph* gr = getTranspose();  
   
      
    for(int i = 0; i < V; i++)  
        visitedg[i] = false;  
   
      
    gr->DFSgr(0, visitedg);  
   
      
    for (int i = 0; i < V; i++)  
        if (visitedg[i] == false)  
             return false;  
   
    return true;  
}  
   
 
int main()  
{  
       
     givGraph g1( 5, false );    
    g1.addededg(0, 1);       
    g1.addededg(0, 2);    
    g1.addededg(3, 4);    
    g1.isSC() ? std::cout << "The grpah is connected\n" :     
                std::cout << "The grpah is not connected\n";    
         
      
                 
     givGraph t3( 5, false );    
    t3.addededg(1, 0);    
    t3.addededg(4, 0);    
   t3.addededg(1, 2);    
    t3.addededg(2, 3);    
    t3.isSC() ? std::cout << "The Given graph is connected \n" :     
                std::cout << "NoT connected \n";    
      
     
   
    return 0;  
}

