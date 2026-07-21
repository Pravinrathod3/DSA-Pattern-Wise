class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<tuple<int, int, int>> pairs;  //end, {start, pos}
        
        int n = s.size();
        
        for(int i=0; i<n; i++){
            pairs.push_back({f[i], s[i], i+1});
        }
        
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            if(get<0>(a) == get<0>(b)){
                return get<2>(a) < get<2>(b);
            }
            
            return get<0>(a) < get<0>(b);
        });
        
        int finsish_time = -1;
        
        vector<int> ans;
        
        for(auto &[end, start, pos]: pairs){
            if(start > finsish_time){
                ans.push_back(pos);
                finsish_time = end;
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};