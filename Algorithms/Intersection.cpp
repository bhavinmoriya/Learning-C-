// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using Point = pair<double, double>;

vector<Point> intersection(Point A, Point B)
{
    vector<Point> result;
    double x1 = A.first, y1 = A.second;
    double x2 = B.first, y2 = B.second;
    double m, numerator = y2 - y1, denominator = x2 - x1;
    if (denominator != 0)
    {
        m = numerator / denominator;
        double c = y1 - m * x1;

        if (m == 0)
        {
            cout << "Line is horizontal" << endl;
            if (c == 0)
            {
                result = {{0, 0},
                          {1, 0}};
                cout << "The equation of the line is: Y=0" << endl;
                return result;
            }
            if (c == 1)
            {
                result = {{0, 1},
                          {1, 1}};
                cout << "The equation of the line is: Y=1" << endl;
                return result;
            }
            if (c < 1 && c > 0)
            {
                result = {{0, c},
                          {1, c}};
                cout << "The equation of the line is: Y=" << c << endl;
                return result;
            }
            else
            {
                // result={{0,1},{1,1}}
                cout << "The equation of the line is: Y=" << c << endl;
                cout << "The line does not intersect the cube\n";
                return result;
            }
        }
        else
        {
            cout << "Line is not horizontal" << endl;
            if (c >= 0 && c <= 1)
                result.push_back({0, c});
            double x = (1 - c) / m;
            if (x >= 0 && x <= 1)
                result.push_back({x, 1});
            double y = c + m;
            if (y >= 0 && y <= 1 && (int)result.size() != 2)
                result.push_back({1, y});
            x = -c / m;
            if (x >= 0 && x <= 1 && (int)result.size() != 2)
                result.push_back({x, 0});

            cout << "The equation of the line is: Y=" << m << "X + " << c << endl;

            return result;
        }
    }
    else
    {
        cout << "Line is vertical. And the equation of the line is: X=" << x1 << endl;
        if (x1 >= 0 && x1 <= 1)
        {
            result = {{x1, 0}, {x1, 1}};
            if (x1 == 1 || x1 == 0)
                cout << "The whole vertical segment is in the intersection\n";
            return result;
        }
        else
        {
            // result={{0,1},{1,1}}
            cout << "The line does not intersect the cube\n";
            return result;
        }
    }
}

int main()
{
    // Write C++ code here

    Point A = {0, 0}, B = {1, 1};
    cout << "Please give two different points\n";
    auto x = intersection(A, B);
    // auto x = extendLineToBorders(A,B);
    if ((int)x.size() != 0)
    {
        cout << "The intersection points are as follows, \n";
        for (int t = 0; t < (int)x.size(); t++)
            cout << x[t].first << " " << x[t].second << endl;
    }
    else
        cout << "Line does not intersect the cube\n";

    return 0;
}