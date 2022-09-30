class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> lrWalls;
        for(auto i: buildings) {
            lrWalls.push_back(make_pair(i[0], -i[2]));
            lrWalls.push_back(make_pair(i[1], i[2]));
        }
        
        sort(lrWalls.begin(), lrWalls.end(), [](pair<int,int> a, pair<int,int> b) {
            if(a.first != b.first) return a.first < b.first;
            else return a.second < b.second;
        });
        //for(auto i: lrWalls) printf("%d %d\n", i.first, i.second);
        
        multiset<int> orderedHeight;
        int currentTopHeight = -0x3f3f3f3f;
        vector<vector<int>> ans;
        for(int ind = 0; ind < lrWalls.size(); ++ind) {
            pair<int, int> i = lrWalls[ind];
            if(i.second < 0) orderedHeight.insert(-i.second);
            else orderedHeight.erase(orderedHeight.find(i.second));
            
          //  for(auto x: orderedHeight) printf("%d ", x); printf("\n");
            if(orderedHeight.empty()) {
                if(ind + 1 != lrWalls.size() && lrWalls[ind + 1].first == lrWalls[ind].first) {
            //        printf("ind = %d", ind);
                    continue;
                }
                currentTopHeight = 0;
                ans.push_back(vector<int>{i.first, currentTopHeight});
            } else {
                if(currentTopHeight != *orderedHeight.rbegin()) {
                    currentTopHeight = *orderedHeight.rbegin();
                    ans.push_back(vector<int>{i.first, currentTopHeight});
                }
            }
        }
        return ans;
    }
};