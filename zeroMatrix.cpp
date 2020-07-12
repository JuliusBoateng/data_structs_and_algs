#include <iostream>
#include <vector>
#include <set>

void zeroMatrix(std::vector<std::vector<int>> matrix) {
    std::vector<int> blank_row(matrix[matrix.size() - 1].size(), 0);
    std::set<int> zero_col_index;

    for (int row = matrix.size() - 1; row >= 0; row--){
        for (int col = matrix[row].size() - 1; col >= 0; col--){
            if (matrix[row][col] == 0){
                matrix[row].clear();
                matrix[row] = blank_row;
                zero_col_index.insert(col);
                break;
            }
        }
    }

    for (auto col : zero_col_index){
        for (int row = matrix.size() - 1; row >= 0; row--){
            matrix[row][col] = 0;
        }
    }
    
    for (int row = matrix.size() - 1; row >= 0; row--){
        std::string result = "";

        for (int col = matrix[row].size() - 1; col >= 0; col--){
            if (col == (matrix[row].size() - 1)){
                 result += std::to_string(matrix[row][col]); 
            }
            else {
                result += ' ' + std::to_string(matrix[row][col]);
            }
        }

        std::cout << result << std::endl;
    }


}

int main(){
    std::vector<std::vector<int>> matrix = { {1,2,3,4}, {5,6,0,7}, {8,9,10,11} };

    zeroMatrix(matrix);

    return 0;
}