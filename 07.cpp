// First non-repeating character in a stream.

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> v1(26,0);
		    vector<int> index(26,INT_MAX);
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        v1[A[i]-'a']++;
		        index[A[i]-'a']=i;
		        int x=INT_MAX;
		        for(int j=0;j<26;j++){
		            if(v1[j]==1){
		                if(index[j]<x){
		                    x=index[j];
		                }
		            }
		        }
		        if(x==INT_MAX){
		            ans+='#';
		        }
		        else{
		            ans+=A[x];
		        }
		    }
		    return ans;
		}
};
