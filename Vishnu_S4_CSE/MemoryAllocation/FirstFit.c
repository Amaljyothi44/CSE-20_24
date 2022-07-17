#include <stdio.h>

int main() {

  int numberOfBlocks, numberOfProcesses;

  printf("Blocks: ");
  scanf("%d", &numberOfBlocks);

  int blockSize[numberOfBlocks];

  printf("\nBlock Sizes:\n\n");
  for (int i = 0; i < numberOfBlocks; i++) {

    printf("%dth Block: ", i);
    scanf("%d", &blockSize[i]);
  }

  printf("\nProcesses: ");
  scanf("%d", &numberOfProcesses);

  int processSize[numberOfProcesses], allocate[numberOfProcesses];

  for (int i = 0; i < numberOfProcesses; i++)
    allocate[i] = -1;

  printf("\nProcess Sizes:\n\n");
  for (int i = 0; i < numberOfProcesses; i++) {

    printf("%dth Process: ", i);
    scanf("%d", &processSize[i]);
  }

  for (int i = 0; i < numberOfProcesses; i++)
    for (int j = 0; j < numberOfBlocks; j++)
      if (blockSize[j] >= processSize[i]) {
        allocate[i] = j;

        blockSize[j] -= processSize[i];

        break;
      }

  printf("\nProcess\tProcessSize\tBlock\n");

  for (int i = 0; i < numberOfProcesses; i++) {

    printf("%d\t%d\t\t", i, processSize[i]);

    if (allocate[i] != -1)
      printf("%d\n", allocate[i]);
    else
      printf("NotAllocated\n");
  }

  printf("\n\n");

  return 0;
}

/*

FirstFit $ gcc -o FirstFit FirstFit.c && ./FirstFit
Blocks: 3

Block Sizes:

0th Block: 5
1th Block: 4
2th Block: 6

Processes: 3

Process Sizes:

0th Process: 5
1th Process: 3
2th Process: 5

Process ProcessSize     Block
0       5               0
1       3               1
2       5               2


FirstFit $ gcc -o FirstFit FirstFit.c && ./FirstFit
Blocks: 4

Block Sizes:

0th Block: 5
1th Block: 4
2th Block: 4
3th Block: 10

Processes: 5

Process Sizes:

0th Process: 5
1th Process: 10
2th Process: 3
3th Process: 6
4th Process: 4

Process ProcessSize     Block
0       5               0
1       10              3
2       3               1
3       6               NotAllocated
4       4               2

*/