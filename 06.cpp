// Maximum of all subarrays of size k

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && dq.back()<arr[i]){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
        for(int i=k;i<n;i++){
            ans.push_back(dq.front());
            if(dq.front()==arr[i-k]){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back()<arr[i]){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());
        return ans;
    }
};
