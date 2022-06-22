#ifndef ASTARALGORITHM_H
#define ASTARALGORITHM_H

#include <QMainWindow>
#include <math.h>
#include <string>
#include <queue>


#include <QImage>
#include <QDebug>

#include <iostream>
using namespace std;

struct mapPic
{
    QImage imageRaw;
    QImage imageSrc;
    QImage imageShow;
    QImage imageTemp;
    QImage imageDir;

    int h;
    int w;

    double latStart;
    double lngStart;
    double deltaLat;
    double deltaLng;

};

struct astar_parameter
{
    vector<vector<int> > maps;
    vector<vector<int> > closed_nodes_map; // map of closed (tried-out) nodes
    vector<vector<int> > open_nodes_map; // map of open (not-yet-tried) nodes
    vector<vector<int> > mapPath;   
    vector<vector<int> > dir_map; // map of directions
    vector<vector<int> > reset;

    int dir;
    int dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
    int grayScale;
};

struct path_parameter
{
    int xS;
    int yS;
    int xE;
    int yE;
    bool startOk = false;
    vector<int> xPath;
    vector<int> yPath;

};

class node
{
public:
    node();

    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

    node(int xp, int yp, int d, int p)
        {xPos=xp; yPos=yp; level=d; priority=p;}

    int getxPos() const {return xPos;}
    int getyPos() const {return yPos;}
    int getLevel() const {return level;}
    int getPriority() const {return priority;}

    void updatePriority(const int & xDest, const int & yDest)
    {
         priority=level+estimate(xDest, yDest)*10; //A*
    }

    // give better priority to going strait instead of diagonally
    void nextLevel(const int & i) // i: direction
    {
         level+=((i%2==0)?10:14);
    }

    // Estimation function for the remaining distance to the goal.
    const int & estimate(const int & xDest, const int & yDest) const
    {
        static int xd, yd, d;
        xd=xDest-xPos;
        yd=yDest-yPos;

        // Euclidian Distance
        d=static_cast<int>(sqrt(xd*xd+yd*yd));

        // Manhattan distance
        //d=abs(xd)+abs(yd);

        // Chebyshev distance
        //d=max(abs(xd), abs(yd));

        return(d);
    }

//    mapPic mapPicDorm;
//    astar_parameter astarParam;

    void initMapDormData(mapPic &mapPicDorm, astar_parameter &astarParam);

    // A-star algorithm.
    // The route returned is a string of direction digits.
    string pathFind( int xStart, int yStart, int xEnd, int yEnd, astar_parameter astarParam);

protected:


private:

};

#endif // ASTARALGORITHM_H
