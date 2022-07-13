#include <stdio.h>

int main() {

	int n = 0, m = 0;

	printf("Enter the number of processes (n): ");
	scanf("%d", &n);
	
	printf("Enter the number of resources (m): ");
	scanf("%d", &m);

	int alloc[n][m], max[n][m], avail[m];

	printf("Enter the allocation matrix [n x m]:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &alloc[i][j]);
		}

	printf("Enter the maximum matrix [n x m]:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &max[i][j]);

	printf("Enter the avail matrix [1 x m]:\n");
	for (int i = 0; i < m; i++)
			scanf("%d", &avail[i]);

	int visited[n], sequence[n], index = 0;
	
	for (int i = 0; i < n; i++)
		visited[i] = 0;

	int need[n][m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];

	int y = 0;
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			if (visited[i] == 0) {

				int flag = 0;

				for (int j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
				
					sequence[index++] = i;
					
					for (int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
						
					visited[i] = 1;
				}
			}

	int flag = 1;
	
	for(int i = 0; i < n; i++)
		if(visited[i] == 0) {
			flag = 0;
			printf("System not SAFE");
			break;
		}
	
	if(flag == 1) {
		printf("SAFE Sequence: ");

		for (int i = 0; i < n - 1; i++)
			printf("P%d ->\t", sequence[i]);

		printf("P%d\t", sequence[n - 1]);
	}
	
	printf("\n\n");

	return 0;
}
