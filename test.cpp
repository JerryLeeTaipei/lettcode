#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> r0, c0;
        int i=0, j=0;
        //cout << matrix.size() << " x " << matrix[0].size() << endl;

        for ( i =0; i < matrix.size(); i++ )
            r0.push_back(0); // reset for each row's flag
        for ( i =0; i < matrix[0].size(); i++ )
            c0.push_back(0); // reset for each column's flag
                
        for (i=0; i < r0.size(); i++) {
            for ( j=0; j < c0.size(); j++) {
                //cout << "Test: " <<i << "," << j << "=" << matrix[i][j] << endl;
                if ( matrix[i][j] == 0 ) {
                    //cout << "Set: " <<i << "," << j << endl;
                    c0[j] = 1;
                    r0[i] = 1;                    
                }

            }
        }
        //cout << "change output\n";
        for (i=0; i < r0.size(); i++) {
            //cout << "i=" << i << "-->" << endl;
            vector<int> &r=matrix[i];
            for ( j=0; j < r.size(); j++) {
                //cout << i << "," << j << endl;
                if ( r0[i] == 1 ) {
                    //cout << "Clear row#" << i << endl;
                    r[j] = 0;
                } else {
                    if ( c0[j] == 1){
                        //cout << "Clear column#" << j << endl;
                        r[j] = 0;
                    }
                }
                //cout << "<--j=" << j << endl;
            }
            //cout << "<--i=" << i << endl;
        }
        return;
    }
};

int main(){
    Solution test;
    vector<vector<int>> matrix;

    int r1[]={0,1};
    vector<int> v1(r1,r1+2);
    matrix.push_back(v1);
#if 0
    int r1[]={0,1,2,0},r2[]={3,4,5,2},r3[]={1,3,1,5};

    vector<int> v1(r1,r1+4);
    vector<int> v2(r2,r2+4);
    vector<int> v3(r3,r3+4);
    
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
#endif


    test.setZeroes(matrix) ;   //1836311903
    return 0;
}
