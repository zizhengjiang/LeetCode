class Solution {
    private void backtracking(int[] nums, List<Integer> tmp, List<List<Integer>> res, boolean[] visited) {
        if (tmp.size() == nums.length) {
            res.add(new ArrayList<>(tmp));
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (visited[i] || i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) continue;
                visited[i] = true;
                tmp.add(nums[i]);
                backtracking(nums, tmp, res, visited);
                visited[i] = false;
                tmp.remove(tmp.size() - 1);
            }
        }
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        backtracking(nums, new ArrayList<>(), res, new boolean[nums.length]);
        return res;
    }
}