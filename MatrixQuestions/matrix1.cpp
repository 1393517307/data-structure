#include<iostream>
 using namespace std;

//螺旋打印矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top=0;
    int right=matrix[0].size()-1;
    int bottom=matrix.size()-1;
    int left=0;
    vector<int> numsMap;
    while (top<=bottom||left<=right)
    {   
        //左到右
        for(int i=left;i<=right;i++)
        {
            numsMap.push_back(matrix[top][i]);
        }
        top++;
        if(top>bottom)break;
        //上到下
        for(int i=top;i<=bottom;i++)
        {
            numsMap.push_back(matrix[i][right]);
        }
        right--;
        if(left>right)break;
        //右到左
        for(int i=right;i>=left;i--)
        {
            numsMap.push_back(matrix[bottom][i]);
        }
        bottom--;
         if(top>bottom)break;
        //下到上
        for(int i=bottom;i>=top;i--)
        {
            numsMap.push_back(matrix[i][left]);
        }
        left++;
        if(left>right)break;
    }
    return numsMap;
}

//生命游戏
void gameOfLife(vector<vector<int>>& board) 
{
    //0：die 1：live   3:relive  4:dying
    int m=board.size();
    int n=board[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int live=0;
            for(int c=i-1;c<=i+1;c++)
            {   
                if(c<0||c>=m)
                {
                    continue;
                }
                for(int d=j-1;d<=j+1;d++)
                {
                    if(d<0||d>=n)
                    {
                        continue;
                    }
                    if(board[c][d]==1||board[c][d]==4)
                    {
                        live++;
                    }                     
                }
            }
            if(board[i][j]) //活着情况 2，3
            {
               if(live<3||live>4)
               {
                  board[i][j]=4;
               }
            }
            else
            {
                if(live==3)//复活
                {
                    board[i][j]=3;
                } 
            }
            
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==4)
            {
                board[i][j]=0;
            }
            else if(board[i][j]==3)
            {
                board[i][j]=1;
            }
            
        }
    }
}

//0矩阵
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m), col(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j]) {
                row[i] = col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

//逆转矩阵
void rotate(vector<vector<int>>& matrix) {
    
}
int main()
{
    vector<vector<int>> mSpiralMatrix={{1,2,3,4},{2,4,6,8},{1,3,6,9}};
    vector<int> tempMap= spiralOrder(mSpiralMatrix);
    for(int i:tempMap)
    {
          cout<<i<<"-";
    }
}