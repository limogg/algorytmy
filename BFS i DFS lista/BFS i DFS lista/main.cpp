//  BFS i DFS lista
//
//  Created by Piotr Janicki on 02/12/2023.
//

#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

int n;

struct slistEl
{
  slistEl * next;
  int data;
};

slistEl ** A;
bool * visited;

class queue
{
  private:
    slistEl * head;
    slistEl * tail;

  public:
    queue( );
    ~queue( );
    bool empty ( void );
    int  front ( void );
    void push ( int v );
    void pop ( void );
};


queue::queue( )
{
    head = tail = NULL;
}

queue::~queue( )
{
    while( head ) pop( );
}

bool queue::empty ( void )
{
  return !head;
}

int queue::front ( void )
{
  if( head ) return head->data;
  else     return MAXINT;
}

void queue::push ( int v )
{
    slistEl * p = new slistEl;
    p->next = NULL;
    p->data = v;
    if( tail ) tail->next = p;
    else     head = p;
    tail = p;
}

void queue::pop ( void )
{
  if( head )
  {
    slistEl * p = head;
    head = head->next;
    if( !head ) tail = NULL;
    delete p;
  }
}

void DFS ( int v )
{
    slistEl * p;
    
    visited[v]=true;
    cout<<v<<" ";
    
    p=A[v];
    
    for (p=A[v]; p; p=p->next)
        if (visited[p->data]==false)
            DFS(p->data);
}

void BFS ( int v )
{
    queue Q;
    slistEl *p;

    Q.push(v);
    visited[v]=true;
    
    while (!Q.empty()) {
        v=Q.front();
        Q.pop();
        
        cout<<v<<" ";
        
        for (p=A[v]; p; p=p->next){
            if (!visited[p->data]) {
                Q.push(p->data);
                visited[p->data]=true;
            }
        }
    }
}

int main( )
{
    int i, vs, ve;
    slistEl *p;
    
    setlocale(LC_CTYPE, "Polish");
    
    const int n = 4; //iloúÊ wierzcho≥kÛw
    const int m = 8; //iloúÊ sπsiadÛw
    
    int E[m][2] = { {0,3},{0,1},{1,2},{1,0},{2,3},{2,1},{3,2},{3,0} }; //kolejne krawÍdzie
    
    A = new slistEl * [ n ];
    visited = new bool [ n ];
    
    for( i = 0; i < n; i++ )
    {
        A [ i ] = NULL;
        visited [ i ] = false;
    }
    
    for( i = 0; i < m; i++ )
    {
        vs = E[i][0];
        ve = E[i][1];
         
        p = new slistEl;
        p->data = ve;
        p->next = A [ vs ];
        A [ vs ] = p;
    }
    
    for( i = 0; i < n; i++ )
    {
        cout << "A [ " << i << " ] =";
        p = A [ i ];
        while( p )
        {
              cout << setw ( 3 ) << p->data;
              p = p->next;
        }
        cout << endl;
    }

    
    cout << "Przejscie grafu w glab - DFS(0):" << endl;
    DFS ( 0 );
    cout << endl;
    
    for( i = 0; i < n; i++ )
        visited [ i ] = false;
        
    cout << "Przejscie grafu wszerz - BFS(0):" << endl;
    BFS ( 0 );
    cout << endl;

    return 0;
}
 

