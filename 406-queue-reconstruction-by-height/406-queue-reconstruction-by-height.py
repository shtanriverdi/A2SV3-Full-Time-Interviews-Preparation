class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # Sort by height in descending order
        def compare(a, b):
            if a[0] > b[0]:
                return -1
            elif a[0] == b[0]:
                if a[1] < b[1]:
                    return -1
                if a[1] == b[1]:
                    return 0
                if a[1] > b[1]:
                    return 1
            if a[0] < b[0]:
                return 1
        
        people.sort(key = functools.cmp_to_key(compare))
        
        reconstructed = []
        for i in range(len(people)):
            k = people[i][1]
            reconstructed.insert(k, people[i])
            
        return reconstructed