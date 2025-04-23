class Solution:
    def count_sum(self, n: int) -> int:
        return sum(int(digit) for digit in str(n))

    def countLargestGroup(self, n: int) -> int:
        group_counts = defaultdict(int)
        for i in range(1, n + 1):
            group_counts[self.count_sum(i)] += 1
        max_count = max(group_counts.values())
        return sum(c == max_count for c in group_counts.values())
