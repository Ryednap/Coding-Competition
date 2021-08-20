#include<bits/stdc++.h>
using namespace std;

const int maxA = 1e3;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int max_count[maxA+1][maxA+1];
	memset(max_count, -1, sizeof(max_count));
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		int a[n];
		int occInd[n];
		
		map<int,int> occ_map;
		
		for(int i=0;i<n;i++){
			cin>>a[i];
			
			occInd[i] = occ_map[a[i]];
			occ_map[a[i]]++;
			
			for(int j=0;j<=k;j++) max_count[j][a[i]] = -1;
		}
				
		int DP[n+1][k+1];
		
		for(int j=0;j<=k;j++) DP[n][j] = 0;
		
		for(int i=n-1;i>=0;i--)
		{
			DP[i][0] = max(DP[i+1][0], occ_map[a[i]] - occInd[i]);
			
			for(int j=1;j<=k;j++)
			{
				DP[i][j] = max(DP[i+1][j], 1 + DP[i+1][j-1]);
				
				if(max_count[j-1][a[i]] != -1)
					DP[i][j] = max(DP[i][j], max_count[j-1][a[i]] - occInd[i] + 1);
				
				max_count[j-1][a[i]] = max(max_count[j-1][a[i]], DP[i+1][j-1] + occInd[i]);
			}
			
			max_count[k][a[i]] = max(max_count[k][a[i]], DP[i+1][k-1] + occInd[i]);
		}
		
		
		int ans = 0;
		for(int j=0;j<=k;j++)
			ans = max(ans, DP[0][j]);
		
		cout<<ans<<endl;
	}
	
	return 0;
}