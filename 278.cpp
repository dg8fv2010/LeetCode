// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadVersion(int n) {
       int left=1;
       int right=n;
       while (left<right)
       {
          int mid=left+(right-left)/2; // mid=(left+right)/2会超时
          if (isBadVersion(mid)==true)
          {
              right=mid;
          }
          else
          {
              left=mid+1;
          }       
       }
        return left;
    }
};