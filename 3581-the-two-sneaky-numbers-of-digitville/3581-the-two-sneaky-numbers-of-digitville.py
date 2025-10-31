class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        mp = defaultdict(int)
        res = []
        for num in nums:
            mp[num] += 1
            if mp[num] == 2:
                res.append(num)
        return res