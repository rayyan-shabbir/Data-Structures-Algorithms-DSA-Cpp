#include "iostream"
using namespace std;


int main() {
    int mat1[3][3] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9}};

    int mat2[2][2] = {{5, 6}, {8, 9}};

    int sr = 0;
    int j = 0;
    int sc = 0;
    int count = 0;

    for(int i = 0; i < 3; i++) {

        while(j < 3) {
            int m = 0;
            while(mat1[i][j] == mat2[sr][sc] && m < 2) {
                int index = j;
                sc++, j++;
                count++;
                m++;
            }

            if(count == 2) {
                sr++;
                i++;
                continue;
            // }else 
            //     break;

            j++;
        }
    }


    return 0;
}   