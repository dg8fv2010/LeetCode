class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res=(C-A)*(D-B)+(G-E)*(H-F);
        int a=max(A,E);
        int b=max(B,F);
        int c=min(C,G);
        int d=min(D,H);

        if(c<=a || d<=b)
        {
            return res;
        }
        return res-(c-a)*(d-b);
    }
};
