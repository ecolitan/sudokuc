#include <stdio.h>

int grid[9][9] = {
    {0,8,0,4,7,9,0,0,2},
    {0,0,7,0,0,2,0,0,0},
    {0,0,0,5,0,0,0,6,4},
    {2,4,3,0,0,7,0,0,0},
    {8,0,0,9,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,0},
    {6,0,0,3,0,5,0,0,0},
    {0,0,8,0,0,0,0,0,9},
    {3,7,0,0,9,1,2,0,0},
};
//
//int grid[9][9] = {
//    {0,0,0,8,0,5,4,2,7},
//    {0,0,7,2,0,3,9,0,5},
//    {0,2,4,7,0,1,0,0,0},
//    {7,4,0,0,8,6,1,0,0},
//    {0,0,8,9,1,0,7,0,4},
//    {0,1,0,0,3,0,0,9,8},
//    {0,0,0,0,0,0,0,0,1},
//    {9,0,1,3,7,0,0,0,6},
//    {2,0,0,0,5,0,3,4,0},
//};

//int grid[9][9] = {
//    {1,9,3,8,6,5,4,2,7},
//    {8,6,7,2,4,3,9,1,5},
//    {5,2,4,7,9,1,6,8,3},
//    {7,4,9,5,8,6,1,3,2},
//    {3,5,8,9,1,2,7,6,4},
//    {6,1,2,4,3,7,5,9,8},
//    {4,3,5,6,2,9,8,7,1},
//    {9,8,1,3,7,4,2,5,6},
//    {2,7,6,1,5,8,3,0,0},
//};

void printGrid();
void solve();
int possible(int x, int y, int n);

int main( int argc, const char* argv[] ) {
    printGrid();
    solve();
    return 0;
}

void solve() {
    int x,y,n;
    for (y=0; y<9; y++) {
        for (x=0; x<9; x++) {
	    if (grid[y][x] == 0) {
//		printf("\nCoord: (%d,%d)", y, x);
//		printGrid();
	        for (n=1; n<10; n++) {
//		    printf("trying n=%d\n", n);
		    if (possible(y,x,n) == 1) {
		        grid[y][x] = n;
			solve();
			grid[y][x] = 0;
		    }
		}
		return;
	    }
	}
    }
    printGrid();
    return;
}

int possible(int y, int x, int n) {
    int i, j, x0, y0;
    for (i=0; i<9; i++) {
    	if (grid[y][i] == n) {
	    return 0;
	}
	if (grid[i][x] == n) {
	    return 0;
	}
    }
    y0 = (y/3)*3;
    x0 = (x/3)*3;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (grid[y0+i][x0+j] == n) {
                return 0;
            }
	}
    }
    return 1;
}

void printGrid() {
    int i,j;
    printf("\n");
    for (i=0; i<9; i++) {
        for (j=0; j<9; j++) {
            printf("%d", grid[i][j] );
	    if (j != 8) {
	        printf(",");
	    }
        }
            printf("\n");
    }
}
