//TSP-DP

#include<cstdio>
#include <iostream>
#include<climits>
#include<cmath>
#include<algorithm>
// #define N 16
using namespace std;

int main(){

    int N;
    cin >> N;
    
    double dis[N][N];
    memset(dis, 0 , sizeof(dis));
    double x[N],y[N];
    int res[N];//path
    
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
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
    
    int cities[N];
    for(int i = 0; i < N; i++){
        cities[i] = i;
    }
    
    double least_dis = INT_MAX, temp_dis = 0;
    
    for (int i = 0; i < N - 1; i++) {
        temp_dis += dis[cities[i]][cities[i+1]];
    }
    temp_dis += dis[cities[0]][cities[N-1]];
    least_dis = temp_dis;
    
    while (next_permutation(cities, cities+N)) {
        temp_dis = 0;
        for(int i = 0; i < N - 1; i++){
            temp_dis += dis[cities[i]][cities[i+1]];
        }
        temp_dis += dis[cities[0]][cities[N-1]];
        if(temp_dis < least_dis){
            least_dis = temp_dis;
            for(int k = 0; k < N; k++){
                res[k] = cities[k];
            }
        }
    }
    
    cout << least_dis << endl;
    
    printf("%s\n", "index");
    for(int i = 0; i < N; i++){
        printf("%d\n", res[i]);
    }
    
    return 0;
}