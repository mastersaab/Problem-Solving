int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for(auto it : edges) {
            // matrix me edges ka dist dalo
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
        // diagonal bharo
		for(int i = 0; i < n; i++) dist[i][i] = 0;

		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
          // floyd warshal algo
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
    
		int cntCity = n;
		int cityNo = -1;
		for(int city = 0; city < n; city++) {
  			int cnt = 0;
      // count kr lo kitna threshold se km h
  			for(int adjCity = 0; adjCity < n; adjCity++) {
  				if(dist[city][adjCity] <= distanceThreshold)
  					cnt++;
  			}
      // agr total se km h to update kr do nhi to -1 return kr do in last
  			if(cnt <= cntCity) {
  				cntCity = cnt;
  				cityNo = city;
  			}
		}
		return cityNo;
    }
