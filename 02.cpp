// Longest Mountain in Array.

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int count=1;
        bool flag1=false;
        bool flag2=false;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1] && flag1==true){
                count++;
                flag2=true;
            }
            else if(arr[i]>arr[i-1] && flag1==true && flag2==true){
                ans=max(ans,count);
                count=2;
                flag1=true;
                flag2=false;
            }
            else if(arr[i]==arr[i-1] && flag1==true && flag2==true){
                ans=max(ans,count);
                count=1;
                flag1=false;
                flag2=false;
            }
            else if(arr[i]>arr[i-1]){
                count++;
                flag1=true;
            }
            else if(arr[i]==arr[i-1] && flag1==true){
                count=1;
                flag1=false;
                flag2=false;
            }
        }
        if(flag1==true && flag2==true){
            ans=max(ans,count);
        }
        if(ans<3){
            return 0;
        }
        return ans;
    }
};
