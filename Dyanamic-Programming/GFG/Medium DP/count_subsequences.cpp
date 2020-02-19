//ttps://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1
int fun(string &s) {
    //code here
    int a=0,b=0,c=0;
    for(auto i=0;i<s.length();i++)
    {
        if(s[i]=='a')
        {
            a=1+2*a;
        }
        if(s[i]=='b')
        {
            b=a+2*b;
        }
        if(s[i]=='c')
        {
            c=b+2*c;
        }
    }
    return c;
}
