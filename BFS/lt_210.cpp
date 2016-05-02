class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if(numCourses <= 0)
            return res;
        int indegree[numCourses];
        memset(indegree,0,sizeof(indegree));
        queue<int> q;
        int edge=0;
        vector<vector<int>> graph(numCourses);  //此处分配空间要注意
        for(int i = 0;i<prerequisites.size();i++)
        {
            int head = prerequisites[i].second;
            int tail = prerequisites[i].first;
            graph[head].push_back(tail);
            indegree[tail]++;                   //入度
        }
        
        for(int i,j=0;j<numCourses;j++)         //每次找一个入度为0的顶点
        {
            for(i=0;i<numCourses && indegree[i] != 0;++i);
            if(i == numCourses)
                return {};
            indegree[i] = -1;
            res.push_back(i);
            for(int k=0;k < graph[i].size();k++)
            {
                --indegree[graph[i][k]];
            }
        }
        return res;
    }
};