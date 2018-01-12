#include <stdio.h>
int N = 8;
int board[8][8];
void print_matrix(){ /* prints the matrix */
    for (int i =0; i<N; i++){
        for(int  j = 0; j<N; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int valid(int i, int j){ /* method to check if position i,j is valid */
    for(int x = 0; x<N-1; x++){ /*checking if row is valid */
        if (x==j)
            continue;
        else if(board[i][x]==1)
            return 0;
    }
    for(int x =0; x<N-1; x++){ /*checking if column is valid */
        if(x==i)
            continue;
        else if(board[x][j]==1)
            return 0;
    }
    for (int x=1; x<N-1; x++){ /* checking right bottom diagonal */
        if(board[i+x][j+x]==1)
            return 0;
    }
    for (int x=1; x<N-1; x++){ /* checking left bottom diagonal */
        if(board[i+x][j-x]==1)
            return 0;
    }
    for (int x=1; x<N-1; x++){ /* checking right top  diagonal */
        if(board[i-x][j+x]==1)
            return 0;
    }
    for (int x=1; x<N-1; x++){ /* checking left top  diagonal */
        if(board[i-x][j-x]==1)
            return 0;
    }
    return 1;
}

void putall(int id){
    if(id >=N) // Base case if all queens are placed return true
        return true;

    for (int i =0; i<N; i++)
    {
        if(valid(i,id))
        {
            board[i][id]=1;
            if(putall(id+1))
                return true;
            board[i][id]=0;
        }
    }
    return false;
}
int main() {

   // print_matrix();
    //printf("is it valid: %d\n", valid(3,2));
    if(putall(0)==false)
    {
        printf("There is no solution");
        return 0;
    }
    print_matrix();
    return 0;
}
