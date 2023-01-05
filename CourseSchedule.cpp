class Solution
{
public:
    bool canFinish(int V, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[V]; // make adjacency list

        vector<int> indegree(V, 0); // find the indegree of every vertexes

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];

            int v = prerequisites[i][1];

            adj[v].push_back(u);

            // update indegree

            indegree[u]++;
        }

        // push all the vertices with indegree == 0, into queue

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;

        // if there will be any cycle then no. of visited vertex will not equal to total vertex

        while (!q.empty())
        {
            int u = q.front();

            q.pop();

            count++;

            // for every adjacent of u, decrement the indegree

            for (auto v : adj[u])
            {
                indegree[v]--;

                // if indegree becomes 0, then push into queue

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        if (count != V)
            return false;

        return true;
    }
};