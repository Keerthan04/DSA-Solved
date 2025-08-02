class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {{digitSum(nums[i]), nums[i]}, i};
        }
        //since here we have if 2 have same digit number then based on number so we do like this so if same then sort based on nums[i]
        
        // we are making a array with number and its index where it is now
        sort(arr.begin(), arr.end());
        // sort based on value so we get final values and index now of each tells actual index
        int swaps = 0;
        vector<bool> visited(n, false);
        // so this is If you model the array as a graph where each index points to the index where the value should be, then the number of swaps required to sort the array is (sum of cycle lengths - 1) for each cycle.
        for (int i = 0; i < n; i++)
        {
            // so if already present proper i.e actual(initial) = index(i) then continue
            if (visited[i] || arr[i].second == i)
                continue;

            // if it is not then find how many cycles by going from current to all its proper positions and find length
            int j = i;
            int cycle_length = 0;
            while (!visited[j])
            {
                cycle_length++;
                visited[j] = true;
                j = arr[j].second;
            }
            // if we get cycle then that length -1 is required swaps for it to get to proper position
            if (cycle_length > 1)
            {
                swaps += (cycle_length - 1);
            }
        }
        return swaps; // return final swaps
    }
};