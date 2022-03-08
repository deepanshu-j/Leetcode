class Solution:
    
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        sorted_clips = sorted(clips, key=lambda element: [element[0], element[1]])
        clips = sorted_clips
        n=len(clips)
        inf=102048900
        memo=[ [None for x in range(n)] for x in range(n) ] 

        @cache
        def fn(t, i):
            if i==-1:
                return 0 if t==0 else inf
                # if t==0:
                #     return 0
                # else:
                #     return inf
            ans=inf
            if clips[i][1]>=t:
                ans=min(ans, 1+fn(clips[i][0], i-1) )
            ans=min(ans, fn(t, i-1))
            return ans
        res = fn(time,n-1)
        return res if res!=inf else -1
    