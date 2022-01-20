// Calculating Maximum Profit.

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int t[K+1][N];
        for(int i=0;i<=K;i++){
            for(int j=0;j<N;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }

        for(int i=1;i<=K;i++){
            for(int j=1;j<N;j++){
                int x=t[i][j-1];
                for(int y=j-1;y>=0;y--){
                    x=max(x , (t[i-1][y]+A[j]-A[y]) );
                }
                t[i][j]=x;
            }
        }
        return t[K][N-1];
    }
};
