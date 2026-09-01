class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int frst = m-1, sec = n-1;
        int lst = nums1.size()-1;
        while(frst>=0 && sec>=0){
            if(nums1[frst]>=nums2[sec]){
                nums1[lst] = nums1[frst];
                lst--,frst--;
            }else{
                nums1[lst] = nums2[sec];
                lst--,sec--;
            }
        }

        while(sec>=0){
            nums1[lst] = nums2[sec];
            lst--,sec--;
        }

    }
};