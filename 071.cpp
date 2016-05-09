// 重复连续出现的'/'，只按1个处理，即跳过重复连续出现的'/'；
// 如果路径名是"."，则不处理；
// 如果路径名是".."，则需要弹栈，如果栈为空，则不做处理；
// 如果路径名为其他字符串，入栈。
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        int i=0;
        while (i<path.size())
        {
            while (i<path.size() && path[i]=='/')
            {
                i++;
            }
            string str="";
            while (i<path.size() && path[i]!='/')
            {
                str+=path[i];
                i++;
            }
            if (str==".." && ss.empty()==false)
            {
                ss.pop();
            }
            if (str!="" && str!="." && str!="..")
            {
                ss.push(str);
            }
        }

        if (ss.empty()==true)
        { // 如果栈为空，说明为根目录，只有斜线'/'
            return "/";
        }
        string ret="";
        while (ss.empty()==false)
        {
            ret="/"+ss.top()+ret;
            ss.pop();
        }
        return ret;
    }
};