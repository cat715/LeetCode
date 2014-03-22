//
//  main.cpp
//  MaxPointOnALine
//
//  Created by CAT on 14-3-17.
//  Copyright (c) 2014年 Bian GuanLin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point> &points) {
//        for (Point p : points) {
//            cout << p.x << " " << p.y << endl;
//        }
        map<float, int> lines;
        int max = 0;
        int duplicate = 0;
        for (int i = 0; i < points.size(); i++) {
            lines.clear();
            lines[INT32_MIN] = 0;
            duplicate = 1;
            //cout << points[i].x << " " << points[i].y << endl;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) {
                    continue;
                }
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                lines[k]++;
            }
            map<float, int>::iterator it = lines.begin();
            for(; it != lines.end(); it++)
                if(it->second + duplicate > max)
                    max = it->second + duplicate;
            
        }
        return max;
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    Solution s;
    vector<Point> points(3);
    points[0]= *new Point(1,2);
    points[1]= *new Point(100,2);
    points[2]= *new Point(1,200);
    s.maxPoints(points);
    return 0;
}

