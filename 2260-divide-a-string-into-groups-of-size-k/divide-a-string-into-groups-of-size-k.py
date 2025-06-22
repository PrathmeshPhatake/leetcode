class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        res =[]
        if len(s)%k !=0:
            missing=k-(len(s) % k)
            s+=fill*missing
        for i  in range(0,len(s),k):
            res.append(s[i:i+k])
        return res