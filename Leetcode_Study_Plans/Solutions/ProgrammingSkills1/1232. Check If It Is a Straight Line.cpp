class Solution {
    bool getArea(vector<int>p1,vector<int>p2,vector<int>p3){
        int x1 = p1[0],x2 =p2[0], x3 =p3[0] ;
        int y1 = p1[1],y2 =p2[1], y3 = p3[1];
        int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        return area == 0;
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        for(int i = 0; i <= n - 3; i++){
            if(!getArea(coordinates[i],coordinates[i + 1],coordinates[i + 2])){
                return false;
            }
        }
        return true;
    }
};

