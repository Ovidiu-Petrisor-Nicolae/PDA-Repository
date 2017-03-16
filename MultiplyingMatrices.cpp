#include <iostream>
#include<time.h>
#include <stdlib.h>
#define SIZE 10
int i,j,k,firstMat[SIZE][SIZE], secondMat[SIZE][SIZE], rezMat[SIZE][SIZE];
using namespace std;

// Multiplying of 2 matrices ( with random numbers)

void createMat(){
  
  srand(time(NULL));
  for( i = 0; i < SIZE; i++)
    for( j = 0; j < SIZE; j++) {
      firstMat[i][j] = rand() & 100;
    }
  
  for( i = 0; i < SIZE; i++)
    for( j = 0; j < SIZE; j++) {
      secondMat[i][j] = rand() & 100;
    }
}

void showMat(){
  
 for( i = 0; i < SIZE; i++){
    for( j = 0; j < SIZE; j++) {
      cout<<first[i][j]<<" ";     
    }
    cout<<"\n";
  }
  
  cout<<"\n\n";
  
   for( i = 0; i < SIZE; i++){
    for( j = 0; j < SIZE; j++) {
      cout<<second[i][j]<<" ";     
    }
    cout<<"\n";
  }
}

void multiplyMat(){
  for( i = 0; i < SIZE; i++)
    for( j = 0; j < SIZE; j++) {
      rezMat[i][j] = 0;
    }
   
  
  for( i = 0; i < SIZE; i++)
    for( j = 0; j < SIZE; j++) 
      for( rezMat[i][j] += firstMat[i][k] * secondMat[k][j]; 
    }
  
  
  for( i = 0; i < SIZE; i++){
    for( j = 0; j < SIZE; j++) {
      cout<<rez[i][j]<<" ";
    }
   cout<<"\n"; 
  }
}
          
int main(){
  createRandomMat();
  showRandomMat();
  multiplyMat();
  return 0;
}
