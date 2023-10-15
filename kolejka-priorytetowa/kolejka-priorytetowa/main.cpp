// Janicki Piotr
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX = 2147483647;

const int N = 100;


struct QueueEl
{
    
    int priority, data;
};


class priorityqueue
{
    private:
        QueueEl T[ N ];
        int n;

    public:
        priorityqueue( );
        ~priorityqueue( );
        bool empty ( void );
        int findmaxdata ( void );
        int findmaxpriority ( void );
        void insert ( int priority, int data );
        void deletemax ( void );
        void print ( void);
};


priorityqueue::priorityqueue( )
{
    n=0;
}

priorityqueue::~priorityqueue( )
{

}


bool priorityqueue::empty ( void )
{
    return !n;
}

int priorityqueue::findmaxdata ( void )
{
    if (n) return T[1].data;
    else        return MAX;
}

int priorityqueue::findmaxpriority ( void )
{
    if (n) return T[1].priority;
    else        return MAX;
}

void priorityqueue::insert ( int priority, int data )
{
    int i, j;
    int counter = 0;

    n++;
    i=n;

    //do T[i] wstaw element z argumentu funkcji
    T[i].priority = priority;
    T[i].data = data;

    //do j wstaw ojca i (ze wzoru)
    j = i/2;
    //dopÛki (i nie jest korzeniem oraz priorytet elementu wstawianego jest wiÍkszy od priorytetu elementu pod indeksem j (to ojciec)
    while (i>1 && ++counter && T[i].priority>T[j].priority) {
        swap(T[i], T[j]);
        i = j;
        j=i/2;
    }
    cout<<"Porownan: "<<counter<<endl;
    //    {
       //      zamieÒ T[i] i T[j] miejscami
    //       do i wstaw j
    //    do j wstaw ojca i
    //    }

}


void priorityqueue::deletemax ( void )
{
    int i, d, p, older; //starszy syn

        p = T [ n ].priority;
        d = T [ n ].data;

        n--;
    if (!empty()) {
        //jeøeli kopiec nie jest pusty
        {
            
            i=1;
            T [ i ].priority = p;
            T [ i ].data = d;
            
            while( i < n )
            {
                // do older wstaw indeks starszego syna (pilnuj czy sπ obaj synowie)
                if (2*i<=n)
                    older= 2*i;
                if (2*i+1<= n)
                    if (T[2*i].priority<T[2*i+1].priority)
                        older = 2*i + 1;
            
                
                // jeøeli p jest mniejsze od priorytetu starszego syna
                if (p < T[older].priority)
                {
                    swap(T[i], T[older]);
                    i=older;
                }
                    
                    
                else
                    i = n;
                //{
                //zamieÒ miejscami wÍze≥ spod indeksu i z jego straszym synem
                //do i wstaw indeks starszego syna
                //}
                // w przeciwnym wypadku wychodzimy z pÍtli np. i=n;
            }
        }
    }
}


int main( )
{
    priorityqueue Q;
    int i, p, v;
    
    setlocale(LC_CTYPE, "Polish");

    srand ( time ( NULL ) );

    cout << "wprowadzone elementy w postaci element:priorytet\n";
    
    for( i = 1; i <= 10; i++ )
    {
        v = i;
        p = rand( ) % 100;
        cout << v << "|" << p << endl;
        Q.insert (p, v);
    }
    
    //øeby sprawdziÊ czy dzia≥a samo insert naleøy usunπÊ poniøsze

    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";

    while ( !Q.empty( ) )
   {
       cout << Q.findmaxdata( ) << "|" << Q.findmaxpriority( ) << endl;
       Q.deletemax( );
   }
    
}
// Janicki Piotr
