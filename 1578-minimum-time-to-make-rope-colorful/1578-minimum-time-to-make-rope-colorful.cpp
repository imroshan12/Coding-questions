class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int min_overall_time=neededTime[0], max_time=neededTime[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                min_overall_time+=neededTime[i];
                if(neededTime[i]>max_time) max_time = neededTime[i];
            }
            else{
                min_overall_time-=max_time;
                max_time=neededTime[i];
                min_overall_time+=neededTime[i];
            }
            
        }
        min_overall_time-=max_time;
        return min_overall_time;
    }
};