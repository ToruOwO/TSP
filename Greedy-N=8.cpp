#include<iostream>
#include<cstdio>
#include<climits>
#include<unordered_set>
#define N 8
using namespace std;

int main(){
    //Greedy Algorithm
    double dis[N][N];
    memset(dis, 0 , sizeof(dis));
    double x[N],y[N];
//    int res[N] = {0,0,0,0,0}; //path
    
    string s; //read x,y
    cin >> s;
    for(int i = 0; i < N; i++){
        scanf("%lf,%lf",&x[i],&y[i]);
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
    
    // cout << dis[0][1] << " " << dis[3][2] << endl;
    
    double least_dis = INT_MAX, temp_dis = 0;
    
    for(int i = 0; i < N; i++){ //each time start from i
        temp_dis = 0;
        int curr = i;
        bool vis[N];
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        for(int j = 0; j < N; j++){
            int i_l_dis = INT_MAX; //each time find the nearest, and go there
            for(int k = 0; k < N; k++){
                if(curr == k || vis[k] == true) continue; //skip itself and visited vertex
                else if(dis[j][k] <= i_l_dis){
                    i_l_dis = dis[curr][k];
                    curr = k;
                }
            }
            temp_dis += i_l_dis;
        }
        temp_dis += dis[curr][i];
        if(temp_dis <= least_dis) least_dis = temp_dis;
    }
    
    cout << least_dis << endl;
    
    return 0;
}
