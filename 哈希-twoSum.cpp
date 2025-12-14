#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    // 测试用例1：基础用例
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution sol; 
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "测试用例1:" << endl;
    cout << "输入:nums = [2,7,11,15], target = 9" << endl;
    cout << "预期输出：[0, 1]" << endl;
    cout << "实际输出：[" << res1[0] << ", " << res1[1] << "]" << endl << endl;

    // 测试用例2：含负数的用例
    vector<int> nums2 = {3, 2, -4};
    int target2 = -1;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "测试用例2:" << endl;
    cout << "输入:nums = [3,2,-4], target = -1" << endl;
    cout << "预期输出：[1, 2]" << endl;
    cout << "实际输出：[" << res2[0] << ", " << res2[1] << "]" << endl << endl;

    // 测试用例3：重复元素的用例
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = sol.twoSum(nums3, target3);
    cout << "测试用例3:" << endl;
    cout << "输入:nums = [3,3], target = 6" << endl;
    cout << "预期输出：[0, 1]" << endl;
    cout << "实际输出：[" << res3[0] << ", " << res3[1] << "]" << endl;

    return 0;
}
