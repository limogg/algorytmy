//  grafy-macierz
//
//  Created by Piotr Janicki on 19/11/2023.
//

#include <iostream>


using namespace std;

void graph(){
    int sizeG=6;
    
    int matrix[6][6]={
        {0,1,2,3,4,5},
        {1,0,1,0,0,0},
        {2,0,0,1,0,0},
        {3,0,1,0,1,0},
        {4,0,0,0,0,0},
        {5,1,1,0,1,0}
    };
    
    for(int i=0;i<sizeG;i++){
        for(int j=0;j<sizeG;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=1;i<sizeG;i++){
        cout<<"Neibghors of "<<i<<" are: ";
        for(int j=1;j<sizeG;j++){
            
            if(matrix[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main() {
    graph();
    return 0;
}
