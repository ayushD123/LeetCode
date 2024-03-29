class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        buckets = [[] for _ in range(len(nums) + 1)]
        for val, freq in cnt.items():
            buckets[freq].append(val)
        
        res = []
        for bucket in reversed(buckets):
            for val in bucket:
                res.append(val)
                k -=1
                if k == 0:
                    return res