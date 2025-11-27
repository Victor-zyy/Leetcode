#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


#define METHOD1 0
#define METHOD2 0
#define METHOD3 0
#define METHOD4 0
#define METHOD5 1

#if METHOD1
/**
 * METHOD1: HashMap -- O(n) O(n)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> _map;
        int count = 0;
        int ele;
        for(const auto& num : nums){
            _map[num]++;
            if(_map[num] > count){
                count = _map[num];
                ele = num;
            }
        }
        return ele; 
    }
};

#elif METHOD2
 /**
  * METHOD2: Sort mid element if we use our own sort algo
  * O(n) O(1)
  */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};
#elif METHOD3
/**
 * METHOD3: Random
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true)
        {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for(const auto& num : nums ){
                if( num == candidate )
                    ++count;
            }
            if( count > nums.size() / 2 ){
                return candidate;
            }
        }
        return -1;
    }
};
#elif METHOD4
/**
 * METHOD4: Partition and Traceback
 * 
 */
class Solution {
private:
    int count_in_range(vector<int>& nums, int target, int lo, int hi){
        int count = 0;
        for(int i = lo; i <= hi; ++i){
            if( nums[i] == target )
                ++count;
        }
        return count;
    }
    int majority_element_rec(vector<int> &nums, int lo, int hi){
        if(lo == hi){
            return nums[lo];
        }
        int mid = (lo + hi) >> 1;
        int leftmajority = majority_element_rec(nums, lo, mid);  
        int rightmajority = majority_element_rec(nums, mid + 1, hi);  
        if(count_in_range(nums, leftmajority, lo, hi) > (hi - lo + 1 ) >> 1){
            return leftmajority;
        }
        if(count_in_range(nums, rightmajority, lo, hi) > (hi - lo + 1 ) >> 1){
            return rightmajority;
        }
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        majority_element_rec(nums, 0, nums.size() - 1);
    }
};

#elif METHOD5
/**
 * METHOD5: Boyer-Moore
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(const auto & num : nums){
            if( num == candidate ){
                ++count;
            }else if(--count < 0){
                count = 1;
                candidate = num;
            }
        }
        return candidate;
    }
};
#endif

int main()
{
    vector<int> nums = { 3, 3, 4 };
    Solution mysolve;
    mysolve.majorityElement(nums);
}