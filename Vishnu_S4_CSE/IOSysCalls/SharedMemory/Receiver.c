#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

void main() {

	int shared_memory_id = shmget((key_t) 11122, 1024, 0666);

	printf("\nShared Memory Key: %d\n", shared_memory_id);

	void *shared_memory = shmat(shared_memory_id, NULL, 0);
	
	printf("\nProcess attached to shared memory at: %p\n", shared_memory);
	
	printf("\nRetreived Data: %s\n\n", (char*) shared_memory);

}
