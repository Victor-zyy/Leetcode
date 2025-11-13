#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstdlib>

using namespace std;

#define METHOD1 1
#define METHOD2 0
#define METHOD3 0


#if METHOD1
/**
 * METHOD1: manually heapify insert
 */
class Solution {
public:
    void heapdown(vector<pair<int, int>>& freq, int i, int n){
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int minset = i;
        if( l < n && freq[l].second <= freq[minset].second ){
            minset = l;
        }
        if( r < n && freq[r].second <= freq[minset].second ){
            minset = r;
        }
        if( minset != i ){
            swap(freq[minset], freq[i]);
            heapdown(freq, minset, n);
        }
    }
    void heapify(vector<pair<int,int>>& freq, int i, int n){
        // ending condition
        if( n == 1 )
            return;
        int parent = ( i - 1 ) / 2;
        int largest = i;

        if( parent >= 0 && freq[parent].second >= freq[largest].second ){
            largest = parent;
        }

        if( largest != i ){
            swap(freq[largest], freq[i]);
            heapify(freq, largest, n);    
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        /**
         * Statistic the frequency of the each element 
         */
        for(const auto &num : nums ){
            freq[num]++;
        }

        vector<pair<int, int>> vec;
        int index = 0;
        for( auto & vc : freq)
        {
            vec.push_back(vc);
            heapify(vec, index, vec.size());
            index++;
            if(vec.size() > k ){
                index--;
                swap(vec.front(), vec[vec.size() - 1]);
                vec.pop_back();
                heapdown(vec, 0, vec.size());
            }
        }
        
        /**
         *  min Heapify to contain k elements
         */
        for( const auto &val : vec ){
            ans.push_back(val.first);
        }
        
        return ans;
    }
};
#elif METHOD2

/**
 * Using Heap Method But use api function of c++ priority_queue
 */
class Solution {
private:
    static bool cmp(pair<int, int>&m, pair<int, int>& n){
        return m.second > n.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        /**
         * Statistic the frequency of the each element 
         */
        for(const auto &num : nums ){
            freq[num]++;
        }
        // Type
        // Contianer
        // Comparasion > minHeap < maxHeap
        // q(cmp) stands for constructor function
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for( auto& [num, count] : freq ){
            if(q.size() == k){
                if(q.top().second < count){
                    q.pop();
                    q.emplace(num, count);
                }
            }else{
                q.emplace(num, count);
            }
        }
        while (!q.empty())
        {
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;    
    }
};

#elif METHOD3
/**
 *  METHOD3: quick-sort
 */

class Solution {
public:
    void quicksort(vector<pair<int,int>>& vec, int start, int end, vector<int>& ret, int k){
        int picked = rand() % (end - start + 1) + start;
        swap(vec[start], vec[picked]);

        int pivot = vec[start].second;
        int index = start;
        // smaller is placed by the right side
        for( int i = start + 1; i <= end; i++ ){
            if( vec[i].second >= pivot ){
                swap(vec[index + 1], vec[i]);
                index++;
            }
        }
        swap(vec[start], vec[index]);

        if( k <= index - start ){
            quicksort(vec, start, index - 1, ret, k );
        }else{
            for( int i = start; i <= index; i++ ){
                ret.push_back(vec[i].first);
            }
            if( k > index - start + 1 ){
                quicksort( vec, index + 1, end, ret, k - (index - start + 1));
            }
        }
        
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        /**
         * Statistic the frequency of the each element 
         */
        for(const auto &num : nums ){
            freq[num]++;
        }
        vector<pair<int, int>> vec;
        for(const auto &v : freq){
            vec.push_back(v);
        }
        quicksort(vec, 0, vec.size() - 1, ans, k);
        return ans;    
    }
};

#endif


int main(){
    Solution mysolve;
    //vector<int> v = {5,-3,9,1,7,7,9,10,2,2,10,10,3,-1,3,7,-9,-1,3,3};
    vector<int> v = {-1,1,4,-4,3,5,4,-2,3,-1};
    int k = 3;
    mysolve.topKFrequent(v, k);
    vector<int> sz = { 1, 2, 3, 4};
    cout << sz.size() << endl;
    sz.pop_back();
    cout << sz.size() << endl;
    sz.pop_back();
    cout << sz.size() << endl;
}