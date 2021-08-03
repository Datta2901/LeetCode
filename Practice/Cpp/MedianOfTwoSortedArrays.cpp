#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void printVector(vector<int> a){
    for(auto i : a){
        cout << i << " ";
    }
    cout << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double answer;
    int gap = ceil(float(nums1.size() + nums2.size()) / 2),start,end;
    while(gap > 0){
        start = 0;
        end = gap;
        while(end < nums1.size() + nums2.size()){
            if(start < nums1.size() && end < nums1.size()){
                if(nums1[end] > nums1[start]){
                    swap(&nums1[start],&nums1[end]);
                }
            }else if(start < nums1.size() && end > nums2.size()){
                if(nums2[end % nums2.size()] > nums1[start]){
                    swap(&nums1[start],&nums2[end % nums2.size()]);
                }
            }else{
                if(nums2[end % nums2.size()] > nums1[start]){
                    swap(&nums2[end % nums2.size()],&nums1[start]);
                }
            }
            start += 1;
            end += gap;
        }
        gap = ceil( gap / 2);
    }

    printVector(nums1);
    printVector(nums2);
    int mid = (nums1.size() + nums2.size());
    if(mid % 2 == 0){
        mid = ceil(float(mid)/2);
        mid -= 1;
        if(mid <  nums1.size() && mid + 1 < nums1.size()){
            answer += nums1[mid] + nums1[mid + 1];
        }else if(mid < nums1.size() && mid + 1 == nums1.size()){
            answer += nums1[mid] + nums2[(mid + 1) % nums2.size()];
        }else{ 
            answer += nums2[mid % nums2.size()] + nums2[(mid + 1) % nums2.size()];
        }
        answer = double(answer) / 2;
    }else{
        mid = (nums1.size() + nums2.size()) / 2;
        mid -= 1;
        if(mid < nums1.size()){
            answer += nums1[mid];
        }else{
            answer += nums2[mid % nums2.size()];
        }
    }
    return answer;
}

int main(){
    int size1,size2;
    cin >> size1 >> size2;
    vector<int>a,b;
    for(int i = 0; i < size1; i++){
        int c;
        cin >> c;
        a.push_back(c);
    }
    for(int i = 0; i < size2; i++){
        int c;
        cin >> c;
        b.push_back(c);
    }
    cout << findMedianSortedArrays(a,b) << endl;
    return 0;
}