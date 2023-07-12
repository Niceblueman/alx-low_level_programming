#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: the grid
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
	int s;

	for (s = 0; s < height; s++)
	{
	free(grid[s]);
	}
	free(grid);
}
