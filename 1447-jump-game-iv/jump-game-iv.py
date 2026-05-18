# class Solution:
#     def minJumps(self, arr: List[int]) -> int:
        
from collections import defaultdict, deque
from typing import List

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 1:
            return 0

        value_to_indices = defaultdict(list)
        for i, val in enumerate(arr):
            value_to_indices[val].append(i)

        queue = deque([0])
        visited = {0}
        steps = 0

        while queue:
            for _ in range(len(queue)):
                i = queue.popleft()

                if i == n - 1:
                    return steps

                neighbors = []

                if i + 1 < n:
                    neighbors.append(i + 1)

                if i - 1 >= 0:
                    neighbors.append(i - 1)

                neighbors.extend(value_to_indices[arr[i]])

                for j in neighbors:
                    if j not in visited:
                        if j == n - 1:
                            return steps + 1
                        visited.add(j)
                        queue.append(j)

                # Important optimization:
                # Once we use all same-value jumps for arr[i],
                # clear them so we don't process them again.
                value_to_indices[arr[i]].clear()

            steps += 1

        return -1