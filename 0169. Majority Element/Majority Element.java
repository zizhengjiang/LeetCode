class Solution {
    public int majorityElement(int[] nums) {
        int res = 0, cnt = 0;
        
        for (int num : nums) {
            if (cnt == 0) {cnt++; res = num;}
            else if (res == num) cnt++;
            else cnt--;
        }
        
        return res;
    }
}