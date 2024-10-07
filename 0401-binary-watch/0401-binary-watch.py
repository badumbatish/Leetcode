class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        def count_bits(n: int) -> int:
            return bin(n).count('1')
        
        def generate_times() -> List[str]:
            for h in range(12):
                for m in range(60):
                    if count_bits(h) + count_bits(m) == turnedOn:
                        yield f"{h}:{m:02d}"
        
        return list(generate_times()) 