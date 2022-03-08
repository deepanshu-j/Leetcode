class Solution:
clips = []
inf=1020489
​
def fn(self, t, i):
if i==-1:
# return 0 if t==-1 else inf
if t>0:
return 0
else:
return inf
ans=self.inf
if self.clips[i][1]>=t:
ans=min(ans, 1+self.fn(self.clips[i][0], i-1) )
ans=min(ans, self.fn(t, i-1))
return ans
def videoStitching(self, clips: List[List[int]], time: int) -> int:
sorted_clips = sorted(clips, key=lambda element: [element[0], element[1]])
self.clips = sorted_clips
n=len(clips)
memo=[ [None for x in range(n)] for x in range(n) ]
​
# return x
# return stupid
return self.fn(time,n-1)