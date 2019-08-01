														//Muhammad Anas Shahid
															//260786586

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

 #define rows 5
 #define cols 5


void fillMatrix(int matrix[rows][cols]){
 srand(time(NULL));										//Sets seed to 0
	for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				matrix[i][j] = rand() % 100 + 1;		//randomizes the number to be between 1-100
			}
	}
}



void printMatrix(int matrix[rows][cols]){
	
printf("\n\t ************\n \n");

	for(int i=0;i<rows;i++){
			for(int j=0;j<rows;j++){
				printf(" %d\t", matrix[i][j]);
			}
		printf("\n");
	}
	printf("\n");
}





void transposeMatrix(int matrix[rows][cols]){
	
	
	 for(int i=0;i<rows;i++){
	 		for(int j=0;j<rows;j++){
	 			if(i==j){								//No need to transpose this because the diagonal stays the same
 				break;
	 			}

				else{
					int *p;
					int *k;
					p=*(matrix+i)+j;
					k=*(matrix+j)+i;
					int temp=0;
					
					temp=*p;							//Swapping Algorithm
					*p=*k;								//Swapping Algorithm
					*k=temp;							//Swapping Algorithm
				}
			}
	}

}



void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int
resultMatrix[rows][cols]){

int i=0;
int j=0;
int k=0;
int *ptr1;												// These are used for use in the pointer notation									
int *ptr2;												// These are used for use in the pointer notation	
int *result;											// These are used for use in the pointer notation

for (int k = 0; k < 2; k++)
{
	
	for (int j = 0; j < cols; j++)
	{
		
		for (int i = 0; i < rows; i++)
		{
			ptr1 	= *(m1+k)+i;						//Did these steps for simplicity of the code and better readibiltiy
			ptr2 	= *(m2+i)+j;						//Did these steps for simplicity of the code and better readibiltiy
			result	= *(resultMatrix+k)+j;				//Did these steps for simplicity of the code and better readibiltiy
			*result +=*ptr1 * *ptr2;					//Did these steps for simplicity of the code and better readibiltiy
		}
	}
}


}


int main(){

	int matrix[rows][cols]= {0};
	fillMatrix(matrix);
	printMatrix(matrix);
	transposeMatrix(matrix);
	printMatrix(matrix);
	int matrix2[2][cols]={0,1,2,3,4,5,6,7,8,9};
	int resultMatrix[rows][cols]={0};
	multiplyMatrix(matrix2, matrix, resultMatrix);
	printMatrix(resultMatrix);
}



