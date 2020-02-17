//https://practice.geeksforgeeks.org/problems/you-and-your-books/1
int max_Books(int a[], int n, int k)
{
    // Your code here
    int sum=0,pos;
    for(auto i=0;i<n;i++)
    {
        if(a[i]<=k)
        {
            pos=i;   
            break;
        }
    }
    int m=-1;
    for(auto i=pos;i<n;i++)
    {
        if(a[i]<=k)
        {
            sum+=a[i];
        }
        else
            sum=0;
        m=max(sum,m);
    }
    return m;
}
