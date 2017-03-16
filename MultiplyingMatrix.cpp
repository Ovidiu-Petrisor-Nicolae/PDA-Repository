#include <iostream>
#include<time.h>
#include <stdlib.h>
#define SIZE 5
int i,j,k,firstMat[SIZE][SIZE], secondMat[SIZE][SIZE], rezMat[SIZE][SIZE];
using namespace std;

// Multiplying of 2 matrices

void createMat(){

  srand(time(NULL));

//Filling first matrix with random values
for( i = 0; i < SIZE; i++)
    for( j = 0; j < SIZE; j++) {
      firstMat[i][j] = rand() & 10;
    }
	
//Filling second matrix with random values
  for( i = 0; i < SIZE; i++)
    for( j = 0; j < SIZE; j++) {
      secondMat[i][j] = rand() & 10;
    }
}

void showMat(){

//Show first matrix 
 for( i = 0; i < SIZE; i++){
    for( j = 0; j < SIZE; j++) {
      cout<<firstMat[i][j]<<" ";
    }
    cout<<"\n";
  }

  cout<<"\n\n";

//Show second matrix
   for( i = 0; i < SIZE; i++){
    for( j = 0; j < SIZE; j++) {
      cout<<secondMat[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void multiplyMat(){

//Filling rezulting matrix with '0'
    for( i = 0; i < SIZE; i++)
        for( j = 0; j < SIZE; j++)
            rezMat[i][j] = 0;

// Multipling of 2 matrix and put the rezult in rezMat[][]
    for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			for (int k = 0; k < SIZE; k++)
                rezMat[i][j] += firstMat[i][k] * secondMat[k][j];

    cout<<"\n";
	
// Show rezult of rezMat[][]
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            cout<<rezMat[i][j]<<" ";
        }
        cout<<"\n";
        }
}

int main(){

    createMat();
    showMat();
    multiplyMat();
    return 0;
}
