class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # without sort, use array of 26 lowercase letters, optimize to O(nk) time, and O(nk) space.
        # map the tuple of array to string.
        hmap = collections.defaultdict(list)
        for st in strs:
            array = [0] * 26
            for l in st:
                array[ord(l) - ord('a')] += 1
            hmap[tuple(array)].append(st)
        return list(hmap.values())