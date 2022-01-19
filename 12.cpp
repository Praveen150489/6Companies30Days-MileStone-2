// Column name from a given column number

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        string y;
        while(n!=0){
            n--;
            int x=n%26;
            y=ans;
            ans="";
            ans+=(x+'A');
            ans+=y;
            n=n/26;
        }
        return ans;
    }
};
