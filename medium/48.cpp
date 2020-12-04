class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //左上角(post1,post1),右上角(post1,post2),右下角(post2,post2),左下角(post2,post1)
        int pos1 = 0, pos2 = matrix.size() - 1;
        int add, temp;
        while(pos1 < pos2){
            add = 0;
            while(add < pos2 - pos1){
                temp = matrix[pos2-add][pos1];
                matrix[pos2-add][pos1] = matrix[pos2][pos2-add];
                matrix[pos2][pos2-add] = matrix[pos1+add][pos2];
                matrix[pos1+add][pos2] = matrix[pos1][pos1+add];
                matrix[pos1][pos1+add] = temp;
                add++;
            }
            pos1++;
            pos2--;
        }
    }
};