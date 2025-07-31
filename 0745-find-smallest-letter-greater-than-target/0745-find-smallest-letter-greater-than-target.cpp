class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;int end = letters.size()-1;
        while(start<=end){
            int mid = start+(end - start)/2;
            if(target>= letters[mid]) start = mid+1;//no need the mid one so
            else end = mid-1;
        }
        // start is the index of the smallest letter greater than target
        // if start == letters.size(), wrap around to the first letter
        return letters[start % letters.size()];;
    }
    //so we need to return > strictly so no if mid and do start = mid + 1 and end we do if start there then that else will be last one(as > than all we have so) then shd return the first one
};