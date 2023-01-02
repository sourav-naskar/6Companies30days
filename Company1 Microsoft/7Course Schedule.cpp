class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        for(auto i : prerequisites){
            g[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(degree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int current=q.front();
            q.pop();
            numCourses--;
            for(auto i:g[current]){
                if(--degree[i]==0) q.push(i);
            }
        }
        return numCourses==0;
    }
private:
    typedef vector<vector<int>> graph;
};