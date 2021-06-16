

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int a[100][100]={0};
        int count=0;
        DFS(a,m,n,0,0,k,count);
        return count;
    }

    void DFS(int a[100][100],int m,int n,int i,int j,int k,int &count){
        if (i<0||i>=m||j<0||j>=n) return;
        int value=i%10+i/10+j%10+j/10;
        if (value>k) return;
        if (a[i][j]==0){
            a[i][j]=1;
            count++;
        }
        else return;
        DFS(a,m,n,i+1,j,k,count);
        DFS(a,m,n,i-1,j,k,count);
        DFS(a,m,n,i,j-1,k,count);
        DFS(a,m,n,i,j+1,k,count);
    }
};

int main(){
    int m=2,n=3,k=1;
    Solution s;
    int x=s.movingCount(m,n,k);
    return 0;
}