class Solution {
public:
    int minArray(vector<int>& numbers) {
        int size=numbers.size();
         if (size == 0) {
            return 0;
        }
        int left=0,right=size-1;
        
        while(left<right)
        {
            int mid = left + (right - left) / 2;
            if(numbers[mid]>numbers[right])
            {
                left=mid+1;
            }
            else if(numbers[mid]==numbers[right])
            {
                right--;
            }
            else
            {
                right=mid;
            }
        }
        return numbers[left];
    }
};

