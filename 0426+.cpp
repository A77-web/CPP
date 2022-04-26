class Solution {
public:
    bool isPalindrome(int x) {
        int sum=0;
        if(x<0 || (x/10!=0 && x%10==0))
        {
            return false;
        }
        else{
           while(x>sum)
           {
               sum  = sum * 10 + x%10;
               x = x/10;
           }
        }
        /*若整数为偶数*/
        if(sum == x)
        {
            return true;
        }
        /*若整数位数为奇数*/
        if(sum/10 == x)
        {
            return true;
        }
        return false;
    }
};
