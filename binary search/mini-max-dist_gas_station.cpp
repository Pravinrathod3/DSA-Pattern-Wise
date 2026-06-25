class Solution {
  public:
  
  
    int maxgap(vector<int>& st, double gap){
        int n = st.size();
        
        int station = 0; // count of extra stations needed


        //extra stations needed between each pair of existing stations
        
        for(int i=0; i<n-1; i++){
            int distance = st[i+1] - st[i];
            station += ceil(distance / gap) - 1;  //if it is perfectly divisible then we need to add one less station because we already have a station at the end of the gap
        }
        
        return station;
    }
  
  
    double minMaxDist(vector<int> &stations, int K) {
        double low = 0;  //we can add gas stations at any point along the road, so the largest distance between adjacent gas stations can be made arbitrarily small
        
        double gap = 0; //the maximum distance between adjacent gas stations in the initial configuration of the stations
         
        for(int i=0; i<stations.size()-1; i++){
            gap = max(gap, (double)(stations[i+1] - stations[i]));
        }
        
        double high = gap;
        
        while(high - low > 1e-6){  //we can use a small value like 1e-6 to ensure that we have a good approximation of the answer, since we are dealing with floating point numbers and we want to avoid precision issues
            double mid = low + (high - low) / 2.0;
            
            int extra = maxgap(stations, mid);
            
            if(extra > K ){  // increase the gap between adjacent gas stations, so we move low to mid
                low = mid ;
            }
            else{
                high = mid ;
            }
        }
        
        return high;  // we return high because it is the maximum distance between adjacent gas stations that we are trying to minimize
    }
};