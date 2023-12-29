#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct thread_data {
	int thread_id;
	int result;
};

int row_size;
int col_size;

/*** Insert your own matrix & vector data, functions ***/
int **matrix;
int *vector;
int *result;

void matrixMake(int rowS, int colS, int **matrix){
	for(int i = 0; i < rowS; i++){
		for(int j = 0; j < colS; j++){
			matrix[i][j] = rand() % 10;
		}
	}
}
void vectorMake(int size, int *vector){
	for(int i = 0; i < size; i++){
		vector[i] = rand() % 10;
	}
}
void matrixPrint(int rowS, int colS, int **matrix){
	printf(" *** Matrix ***\n");
	for(int i = 0; i < rowS; i++){
                for(int j = 0; j < colS; j++){
                        printf("[ %d ] ", matrix[i][j]);
                }
		printf("\n");
        }
}
void vectorPrint(int size, int *vector){
	printf(" *** Vector ***\n");
	for(int i = 0; i < size; i++){
              printf("[ %d ]\n", vector[i]);
        }
	//printf("\n");
}
void resultPrint(int size, /*struct thread_data *t_data*/int *result){
	printf(" *** Result ***\n");
	for(int i = 0; i < size; i++){
              printf("[ %d ]\n", result[i]);
	      //printf("[ %d ]\n", t_data[i].result);
        }
	//printf("\n");
}


void *thread_mvm(void *arg) {
	/*** Insert your code ***/
	long id = (long) arg;
	struct thread_data t_data[row_size];
	for(int i = 0; i < col_size; i++){
		t_data[t_data->thread_id].result += matrix[t_data->thread_id][i] * vector[i];
		//arg[id].[1] = matrix[id][i] * vector[i];
		//printf("ok : %d\n", t_data[t_data->thread_id].result);
		//result[id] = t_data[t_data->thread_id].result;
		result[id] += matrix[id][i] * vector[i];
	}

	//pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

	if (argc != 3) {
		printf("Usage: %s <row> <column>\n", argv[0]);
		exit(1);
	}

	row_size = atoi(argv[1]);
	col_size = atoi(argv[2]);
	pthread_t tid[row_size];	
	struct thread_data t_data[row_size];

	/*** Insert your code ***/
	matrix = (int**)malloc(sizeof(int*)*row_size);
	for(int i = 0; i < row_size; i++)
		matrix[i] = (int*)malloc(sizeof(int)*col_size);
	vector = (int*)malloc(sizeof(int)*col_size);
	result = (int*)malloc(sizeof(int)*row_size);
	srand(time(NULL));
	matrixMake(row_size, col_size, matrix);
	matrixPrint(row_size, col_size, matrix);
	vectorMake(col_size, vector);
	vectorPrint(col_size, vector);
	
	
	long t;
	for(t = 0; t < row_size; t++){
		if(pthread_create(&tid[t], NULL, thread_mvm, (void*)t)){
		       
			printf("ERROR: pthread creation failed. \n");
	 		//exit(1);
		}
		//printf("t : %ld\n", t);
	}		
	for(t = 0; t < row_size; t++){
		pthread_join(tid[t], NULL);
	}
	resultPrint(row_size, /*t_data*/result);

	return 0;
}

