class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] map = new int[256];
        Arrays.fill(map, -1);
        int res = 0, st = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            st = Math.max(st, map[s.charAt(i)]);
            map[s.charAt(i)] = i;
            res = Math.max(res, i - st);
        }
        
        return res;
    }
}