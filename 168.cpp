class Solution {
public:
    string convertToTitle(int n) {
      string ans;
      while (n)
      {
          int temp=(n-1)%26;
          ans+=temp+'A';
          n=(n-1)/26;
      }
      return string(ans.rbegin(), ans.rend());
    }
};