class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used) {
        
        // permutation is complete
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // already used
            if (used[i])
                continue;

            // skip duplicate
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // choose
            used[i] = true;
            current.push_back(nums[i]);

            // explore
            backtrack(nums, current, used);

            // undo
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used);

        return ans;
    }
};