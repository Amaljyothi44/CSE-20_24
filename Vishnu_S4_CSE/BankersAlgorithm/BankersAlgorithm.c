#include <stdbool.h>
#include <stdio.h>

bool bankersAlgorithm(int n, int m, int alloc[n][m], int max[n][m],
                      int need[n][m], int avail[m], bool isResourceRequest) {

  int visited[n], sequence[n], index = 0;

  for (int i = 0; i < n; i++)
    visited[i] = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];

  int y = 0;

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      if (visited[i] == 0) {

        int flag = 0;

        for (int j = 0; j < m; j++)
          if (need[i][j] > avail[j]) {
            flag = 1;
            break;
          }

        if (flag == 0) {

          sequence[index++] = i;

          for (int y = 0; y < m; y++)
            avail[y] += alloc[i][y];

          visited[i] = 1;
        }
      }

  int flag = 1;

  for (int i = 0; i < n; i++)
    if (visited[i] == 0) {
      flag = 0;
      printf("System not SAFE");

      if (isResourceRequest)
        printf(" => New request can't be allocated");

      return false;
    }

  if (flag == 1) {

    printf("SAFE Sequence: ");

    for (int i = 0; i < n - 1; i++)
      printf("P%d ->\t", sequence[i]);

    printf("P%d\t", sequence[n - 1]);

    if (isResourceRequest)
      printf("\n => New request can be allocated");
  }

  return true;
}

void resourceRequestAlgorithm(int n, int m, int alloc[n][m], int max[n][m],
                              int need[n][m], int avail[m], int request[m], int new) {

  for (int i = 0; i < m; i++) {
    if (request[i] > need[new][i]) {
      printf(
          "Invalid request: Request > Need => New request can't be allocated");
      return;
    }

    if (request[i] > avail[i]) {
      printf(
          "Invalid request: Request > Avail => New request can't be allocated");
      return;
    }
  }

  bankersAlgorithm(n, m, alloc, max, need, avail, true);
}

int main() {

  int n = 0, m = 0;

  printf("Enter the number of processes (n): ");
  scanf("%d", &n);

  printf("Enter the number of resources (m): ");
  scanf("%d", &m);

  int alloc[n][m], max[n][m], avail[m], need[n][m];

  printf("Enter the allocation matrix [n x m]:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &alloc[i][j]);

  printf("Enter the maximum matrix [n x m]:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &max[i][j]);

  printf("Enter the avail matrix [1 x m]:\n");
  for (int i = 0; i < m; i++)
    scanf("%d", &avail[i]);

  bool result = bankersAlgorithm(n, m, alloc, max, need, avail, false);

  if (!result)
    return 0;

  int new, request[m];

  printf("\n\nPID of the process requesting next: ");
  scanf("%d", &new);

  printf("Enter the need vector of the next request [1 x m]: ");
  for (int i = 0; i < m; i++)
    scanf("%d", &request[i]);

  resourceRequestAlgorithm(n, m, alloc, max, need, avail, request, new);

  printf("\n\n");

  return 0;
}
