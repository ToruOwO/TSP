#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include <cmath>
// #define N 8
using namespace std;

int main(){
    //Greedy Algorithm
    int N;
    cin >> N;

    double dis[N][N];
    memset(dis, 0 , sizeof(dis));
    double x[N],y[N];
    
    for(int i = 0; i < N; i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    
//    cout << x[0] <<" "<< y[0] << endl;
    
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
    
//    cout << dis[0][1] << " " << dis[3][2] << endl;
    
    int path[N][N]; //N cases, each starting from N
    int path_id;
    double res = 1000000;
    
    for(int i = 0; i < N; i++){ //starting point
        
        bool vis[N];
        int last = i;
        int temp_res = 0;
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        
        for(int j = 0; j < N-1; j++){ //go through the rest of the cities
            double least_dis = 1000000;
            int least_id;
            for(int k = 0; k < N; k++){
                if(vis[k]) continue;
                if(dis[last][k] < least_dis){
                    least_dis = dis[last][k];
                    least_id = k;
                }
            }
            last = least_id;
            vis[last] = true;
            path[i][j] = last;
            temp_res += least_dis;
        }
        
        temp_res += dis[i][last];
        path[i][N-1] = i;
        
        if(temp_res < res) {
            res = temp_res; //least distance
            path_id = i;
        }
        
    }
    
    cout << path_id << endl;
    for(int i = 0; i < N; i++) cout << path[path_id][i] << endl;
    
    cout << res << endl;
    
    return 0;
}
