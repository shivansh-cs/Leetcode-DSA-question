class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int, int)> solve = [&](int i, int target) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }

            if (i == candidates.size() || target < 0)
                return;

            // Take the current number (can be used again)
            if (candidates[i] <= target) {
                temp.push_back(candidates[i]);
                solve(i, target - candidates[i]);
                temp.pop_back();
            }

            // Skip the current number
            solve(i + 1, target);
        };

        solve(0, target);
        return ans;
    }
};