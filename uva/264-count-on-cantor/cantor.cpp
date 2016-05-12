#include <iostream>

#define M 10000000
#define DOWN 1
#define UP 0

struct CantorTable {
    int row;
    int col;
};

CantorTable orderedCantorTable[M];

/**
 * fillCantorTable
 *
 * Fills the Cantor Table based on the zig zag cantor sequence
 * Points To Notice:
 * 1. Moves right when row number is 0 and column number is even.
 * 2. Moves down-left when row number is 0 and column number is odd.
 * 3. Moves down when column number is 0 and column number is odd.
 * 4. Moves up-right when column number is 0 and column number is even.
 * 5. Diagonal traversal gets bigger by 1 unit for each down or right movements.
 */
void fillCantorTable(int size) {

    int r = 0, c = 0, direction = 0;
    for(int i = 0; i < size; ++i) {
        orderedCantorTable[i].row = r + 1;
        orderedCantorTable[i].col = c + 1;

        if(r == 0) {
            if(c % 2) {
                direction = DOWN;
                r = r + 1;
                c = c - 1;
            }
            else {
                c = c + 1;
            }
        }
        else if(c == 0) {
            if(r % 2) {
                // row is odd we will move down
                r = r + 1;
            }
            else {
                // row is even we move diagonal up
                direction = UP;
                r = r - 1;
                c = c + 1;
            }
        }
        else if(direction == UP) { //check direction and update intermediate cells
            r = r - 1;
            c = c + 1;
        }
        else {
            r = r + 1;
            c = c - 1;
        }
    }
}

void recursiveFillCantor(int index, int r, int c, int direction) {
    if(r < 0 || c < 0 || index > M)
        return;

    orderedCantorTable[index].row = r + 1;
    orderedCantorTable[index].col = c + 1;

    // Case we are at the 0th row we move right or diagonal down
    if (r == 0) {

        if(c % 2) {
            // col is odd we move diagonal down left
            direction = DOWN;
            r = r + 1;
            c = c - 1;
            ++index;
            recursiveFillCantor(index, r, c, direction);
        }
        else {
            // col is even we move right
            c = c + 1;
            ++index;
            recursiveFillCantor(index, r, c, direction);
        }
    }

    if(c == 0) {
        if(r % 2) {
            // row is odd we will move down
            r = r + 1;
            ++index;
            recursiveFillCantor(index, r, c, direction);
        }
        else {
            // row is even we move diagonal up
            direction = UP;
            r = r - 1;
            c = c + 1;
            ++index;
            recursiveFillCantor(index, r, c, direction);
        }
    }

    //check direction and update intermediate cells
    if(direction == UP) {
        ++index;
        r = r - 1;
        c = c + 1;
        recursiveFillCantor(index, r, c, direction);
    }
    else {
        ++index;
        r = r + 1;
        c = c - 1;
        recursiveFillCantor(index, r, c, direction);
    }
}



int main() {

    // Pass in row, column, index, diagonal traversal size
    fillCantorTable(M);

    int n;
    while( scanf("%d", &n) == 1 ){
        printf("TERM %d IS %d/%d\n", n, orderedCantorTable[n-1].row, orderedCantorTable[n-1].col);
    }

    return 0;
}
