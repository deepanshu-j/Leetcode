class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        # Bellman-Ford # DP [node][k=jumps/hops]
        inf = 1e9
        graph = {}    
        
        # adding vertices to the graph #
        # for i in range(len(times)):
        #     if times[i][0] not in graph:
        #         graph[times[i][0]]=[]
        
        # adding edges #
        # for i in range(len(times)):
        #     graph[times[i][0]].append([ times[i][1], times[i][2] ])
        
        # return graph
        
#         _ = [None for _ in range(n)]
#         dp = [_ for x in range(n)]
        
        # dp = [  [inf for _ in range(n)] for x in range(n)]
        
        # return dp
        
        src = k
        # dp[src][0]=0
        dist = [inf for _ in range(n+1)]
        dist[src]=0
        for k in range(n+1):
            for e in times:
                u=e[0] 
                v=e[1]
                w=e[2]
                dist[v] = min(dist[v], w+dist[u])                
        
        time_taken = -1
        for i in range(1, len(dist)):
            time_taken=max(time_taken, dist[i])
        
        if time_taken>=inf:
            return -1
        else:
            return time_taken
        
        
        