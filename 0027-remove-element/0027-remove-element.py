class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow = 0

        for num in nums:
            if (num != val):
                nums[slow] = num
                slow = slow + 1
        return slow