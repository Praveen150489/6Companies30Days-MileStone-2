// Which among them forms a perfect Sudoku Pattern ?

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0;i<9;i++){
            set<int> s;
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    continue;
                }
                else if(s.find(mat[i][j])==s.end()){
                    s.insert(mat[i][j]);
                }
                else{
                    return 0;
                }
            }
        }

        for(int j=0;j<9;j++){
            set<int> s;
            for(int i=0;i<9;i++){
                if(mat[i][j]==0){
                    continue;
                }
                else if(s.find(mat[i][j])==s.end()){
                    s.insert(mat[i][j]);
                }
                else{
                    return 0;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<int> s;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(mat[k][l]==0){
                            continue;
                        }
                        else if(s.find(mat[k][l])==s.end()){
                            s.insert(mat[k][l]);
                        }
                        else{
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};
