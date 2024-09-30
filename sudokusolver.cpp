#include <simplecpp>

bool canbeput(int sudoku[][9], int row, int column, int o){
    int possibility[9] = {0};
    for(int i = 0; i < 9; i ++){
        if(sudoku[row][(column+i)%9] != 0){
            possibility[sudoku[row][(column+i)%9]-1] = sudoku[row][(column+i)%9];
        }
        
        if(sudoku[(row+i)%9][column] != 0){
            possibility[sudoku[(row+i)%9][column]-1] = sudoku[(row+i)%9][column];
        }
        
    }
    
    int blockrow = row/3;
    int columnrow = column/3;

    for (int i = 0; i< 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(sudoku[3*blockrow+i][3*columnrow+j] != 0){
                possibility[sudoku[3*blockrow+i][3*columnrow+j]-1] = sudoku[3*blockrow+i][3*columnrow+j];
            }
        }
    }
    
    if(possibility[o-1] == 0) return true;
    else return false;
    
}

bool solved(int sudoku[][9], int row, int column){
    if (row == 9) {
        return true;
    }
    
    else if (column == 9){
        return solved(sudoku, row+1, 0);
    }
    
    else if (sudoku[row][column] != 0){
        return solved(sudoku, row, column + 1);
    }
    
    else{
        for (int k = 1; k < 10; k++) {
            if(canbeput(sudoku, row, column, k)){
                sudoku[row][column] = k;
                if(solved(sudoku, row, column+1)){
                    return true;
                }
                sudoku[row][column] = 0;
                
            }
        }
        return false;
    }
}


main_program{
    
    int sudoku[9][9] = {{0}};
    for(int i = 0; i < 9 ; i ++){
        for(int j = 0; j < 9 ; j++){
            cin>>sudoku[i][j];
        }
    }
    
    solved(sudoku, 0, 0);
    
    cout<<"*** solved sudoku ***\n";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<< sudoku[i][j] <<" ";
        }
        cout<<"\n";

    }
    
    
    
}
