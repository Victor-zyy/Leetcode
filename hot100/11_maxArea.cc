#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution{
public:
    int maxArea(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int max_area = 0;
      while(left < right){
	int area = ( right - left ) * min(height[left], height[right]);
	max_area = area > max_area ? area : max_area;
	if(height[left] > height[right])
	  right--;
	else if(height[left] <= height[right])
	  left++;
      }
      return max_area;
    }
};
#if 0
// exceed the time limit
class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size();

      if(height.size() <= 1)
	return 0;

      if(height.size() == 2)
	return min(height[0], height[1]);

      int max_val = -1;
      while(left < right){
	int index = left + 1;
	int temp_ = 0;
	if(index == right) // corner
	  break;

	while(index < right){
	  temp_ = (index - left) * min(height[index], height[left]);
	  max_val = temp_ > max_val ? temp_ : max_val;
	  index++;
	}
	left ++ ;
      }
      return max_val;
    }
};

// by the height and width
// |-------------------|
// |                   |
// |-------------------|
class Solution2{
public:
    int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size();

      if(height.size() <= 1)
	return 0;

      if(height.size() == 2)
	return min(height[0], height[1]);

      int max_val = -1;
      while(left < right){
	int index = right - 1;
	int temp_ = 0;
	if(index == left) // corner
	  break;

	while(index > left){
	  temp_ = (index - left) * min(height[index], height[left]);
	  max_val = temp_ > max_val ? temp_ : max_val;
	  if(height[index] > height[left])
	    break;
	  index--;
	}
	left ++ ;
      }
      return max_val;
    }
};
// two pointers : right and left move the pointer of the least short edge to maximize
// the big area
class Solution3{
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};
#endif
ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

int main(){
  Solution solve;
  vector<int> test{ 1,8,6,2,5,4,8,3,7};
  cout << test << endl;
  cout << "maxArea : " << solve.maxArea(test) << endl;
  return 0;
}
