 #include <iostream>
 using namespace std;
 
int Tot_Ways(int n, int k, int *dp)
{    
       dp[0] = 1;
       for(int i = 1;i <= k;i++){ /// line 5-10 for solving the dp[n] for n <= k in O(n*k)
            dp[i] = 0;
            for(int j = 1;j <= k;j++){
                 if (i-j >= 0)
                 dp[i] = dp[i] + dp[i-j];}
               }  /// line 10
       for(int i = k+1;i <= n;i++){  /// solved for n > k using recurrence relation dp[n+1] = dp[n] - dp[n-k] in O(n)
            dp[i] =2*dp[i-1] - dp[i-1-k];
             }
 return dp[n];}

int main(){
     int n , k;
     cin >> n >> k;
     int dp[1000];
     for(int i=0; i<1000; i++){
         dp[i] = -1; }
     cout << Tot_Ways(n ,k ,dp);
 }
