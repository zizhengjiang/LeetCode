class Solution {
    private void backtracking(int[] nums, List<Integer> tmp, List<List<Integer>> res) {
        if (tmp.size() == nums.length) {
            res.add(new ArrayList<>(tmp));
        } else {
            for (int num : nums) {
                if (tmp.contains(num)) continue;
                tmp.add(num);
                backtracking(nums, tmp, res);
                tmp.remove(tmp.size() - 1);
            }
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtracking(nums, new ArrayList<>(), res);
        return res;
    }
}