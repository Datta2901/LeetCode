#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
class Solution {

public:

    int orientation(vector<int> p, vector<int> q, vector<int> r){
        int val = (q[1] - p[1]) * (r[0] - q[0]) -(q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0; 
        return (val > 0)? 1: 2; 
    }

    vector<vector<int> > outerTrees(vector<vector<int> >& trees) {
        int n = trees.size();
        vector<vector<int> > hull;
        if(n < 3){
            return hull;
        }
        int l = 0;
        for(int i = 0; i < n; i++){
            if(trees[i][0] < trees[l][0]){
                l = i;
            }
        }
        int p = 0,q,count = 0;

        while(p != l){
            if(count == 0){
                p = l;
                count++;
            } 
            vector<int>a;
            a.push_back(trees[p][0]);
            a.push_back(trees[p][1]);
            hull.push_back(a);

            q = (p + 1) % n;

            for(int i = 0; i < n; i++){
                if(orientation(trees[p],trees[i],trees[q]) == 2){
                    q = i;
                }
                p = q;
            }
        }
        // do{
        //     hull.push_back(trees[p]);
        //     q = (p+1)%n;
        //     for (int i = 0; i < n; i++)
        //     {
        //     if (orientation(trees[p], trees[i], trees[q]) == 2)
        //         q = i;
        //     }

        //     p = q;

        // }while (p != l);

        return hull;
    }

};