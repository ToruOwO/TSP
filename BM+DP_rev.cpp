#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
//#define N 8
using namespace std;


int main(){
    
    int N;
    cin >> N;
    
    double dis[N][N];
    memset(dis,0,sizeof(dis));
    double x[N],y[N]; //path
    double dp[1<<N][N];
    
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    
    //distance btw every cities
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j || dis[i][j] != 0) continue;
            else {
                double xl = abs(x[i]-x[j]), yl = abs(y[i]-y[j]);
                dis[i][j] = sqrt(xl*xl + yl*yl);
                dis[j][i] = dis[i][j];
            }
        }
    }
    
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <=(1<<N)-1; i++){ //iterate through all sets
        for (int j = 0; j < N; j++){
            if(dp[i][j] == -1) continue;
            
            for (int k = 0; k < N; k++){
                if ((i & (1 << k))) continue; //check if k is in set i
                if (!(i >> k & 1)) dp[i][k] = min(dp[i | 1 << k][k] + dis[j][k], dp[i][j]);
            }
        }
    }
    
    // memset(dp,-1,sizeof(dp));
    // dp[(1<<N)-1][0] = 0;
    // for (int i = (1<<N) - 2; i >= 0; i++){
    // 	 for (int j = 0; j < N; j++){
    // 	 	if(dp[i][j] == -1) continue;
    
    // 		for (int k = 0; k < N; k++){
    // 			if (!(i >> k & 1)) dp[i][k] = min(dp[i | 1 << k][k] + dis[j][k], dp[i][j]);
    // 		 }
    // 	 }
    // }
    
    double res = INT_MAX;
    
    for(int i = 1; i < N; i++){
        if (dp[(1<<N)-1][i] > 0) res = min(res, dp[(1<<N)-1][i]+dis[i][0]);
    }
    
    cout << res << endl;
    return 0;
}