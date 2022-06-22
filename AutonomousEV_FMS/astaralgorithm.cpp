#include "astaralgorithm.h"

node::node()
{

}
void node::initMapDormData(mapPic &mapPicDorm, astar_parameter &astarParam)
{
//    mapPicDorm.imageRaw = QImage(":/image/testKTXMatlab.png");
//    mapPicDorm.imageSrc = QImage(":/image/testKTX.jpg");
//    mapPicDorm.imageShow = QImage(":/image/testKTX.jpg");
//    mapPicDorm.imageTemp = QImage(":/image/testKTX.jpg");
//    mapPicDorm.imageDir = QImage(":/image/testKTX.jpg");

//    mapPicDorm.imageRaw = QImage(":/image/testDVAMatlab.png");
//    mapPicDorm.imageSrc = QImage(":/image/testDVAEditted.jpg");
//    mapPicDorm.imageShow = QImage(":/image/testDVAEditted.jpg");
//    mapPicDorm.imageTemp = QImage(":/image/testDVAEditted.jpg");
//    mapPicDorm.imageDir = QImage(":/image/testDVAEditted.jpg");

//    mapPicDorm.imageRaw = QImage(":/image/Road27AMatlab.png");
//    mapPicDorm.imageSrc = QImage(":/image/Road27A.png");
//    mapPicDorm.imageShow = QImage(":/image/Road27A.png");
//    mapPicDorm.imageTemp = QImage(":/image/Road27A.png");
//    mapPicDorm.imageDir = QImage(":/image/Road27A.png");

    mapPicDorm.imageRaw = QImage(":/image/BKMatlab.png");
    mapPicDorm.imageSrc = QImage(":/image/BK.png");
    mapPicDorm.imageShow = QImage(":/image/BK.png");
    mapPicDorm.imageTemp = QImage(":/image/BK.png");
    mapPicDorm.imageDir = QImage(":/image/BK.png");

    mapPicDorm.h = mapPicDorm.imageRaw.height();
    mapPicDorm.w = mapPicDorm.imageRaw.width();

//    mapPicDorm.latStart = 10.76053;
//    mapPicDorm.lngStart = 106.66084;
//    mapPicDorm.deltaLat = (10.76053 - 10.75941)/(mapPicDorm.h);
//    mapPicDorm.deltaLng = (106.66275 - 106.66084)/(mapPicDorm.w);

//    mapPicDorm.latStart = 10.799588423122847;
//    mapPicDorm.lngStart = 106.74227620212109;
//    mapPicDorm.deltaLat = (10.799588423122847 - 10.798257894893037)/(mapPicDorm.h);
//    mapPicDorm.deltaLng = (106.74463118748565 - 106.74227620212109)/(mapPicDorm.w);

    /**10.79690689837185, 106.74219036634582
    10.795249650646346, 106.74524003786846

    10.796904832816487, 106.74219453207655
    10.795254767946368, 106.74522013926098**/

//    mapPicDorm.latStart = 10.79690689837185;
//    mapPicDorm.lngStart = 106.74219036634582;
//    mapPicDorm.deltaLat = (10.79690689837185 - 10.795249650646346)/(mapPicDorm.h);
//    mapPicDorm.deltaLng = (106.74524003786846 - 106.74219036634582)/(mapPicDorm.w);

//    mapPicDorm.latStart = 10.796901;
//    mapPicDorm.lngStart = 106.74219;
//    mapPicDorm.deltaLat = (10.796901 - 10.79521)/(mapPicDorm.h);
//    mapPicDorm.deltaLng = (106.74522 - 106.74219)/(mapPicDorm.w);

    /*10.774735149612809, 106.65714632447755
    10.771341352195568, 106.66222642813969*/

    mapPicDorm.latStart = 10.77474;
    mapPicDorm.lngStart = 106.65715;
    mapPicDorm.deltaLat = (10.77474 - 10.77134)/(mapPicDorm.h);
    mapPicDorm.deltaLng = (106.66223 - 106.65715)/(mapPicDorm.w);

    astarParam.maps.resize(mapPicDorm.w);
    astarParam.open_nodes_map.resize(mapPicDorm.w);
    astarParam.closed_nodes_map.resize(mapPicDorm.w);
    astarParam.dir_map.resize(mapPicDorm.w);
    astarParam.reset.resize(mapPicDorm.w);

    for (int i = 0; i < mapPicDorm.w; i++)
    {
        astarParam.maps.at(i).resize(mapPicDorm.h);
        astarParam.open_nodes_map.at(i).resize(mapPicDorm.h);
        astarParam.closed_nodes_map.at(i).resize(mapPicDorm.h);
        astarParam.dir_map.at(i).resize(mapPicDorm.h);
        astarParam.reset.at(i).resize(mapPicDorm.h);

    }

    for ( int y = 0; y < mapPicDorm.h; ++y)
        for ( int x = 0; x < mapPicDorm.w; ++x)
        {
            QColor clrCurrent(mapPicDorm.imageRaw.pixel(x, y));

            astarParam.maps.at(x).at(y) = clrCurrent.red();
        }

    astarParam.dir = 8;
    astarParam.grayScale = 255;


}

// Determine priority (in the priority queue)
bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}

string node::pathFind(int xStart, int yStart, int xEnd, int yEnd, astar_parameter astarParam)
{

    static priority_queue<node> pq[2]; // list of open (not-yet-tried) nodes
    static int pqi; // pq index
    static node* n0;
    static node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi = 0;

//    // reset the node maps
    astarParam.closed_nodes_map = astarParam.reset;
    astarParam.open_nodes_map = astarParam.reset;
    astarParam.dir_map = astarParam.reset;


    // create the start node and push into list of open nodes
    n0=new node(xStart, yStart, 0, 0);
    n0->updatePriority(xEnd, yEnd);
    pq[pqi].push(*n0);
    astarParam.open_nodes_map.at(xStart).at(yStart) = n0->getPriority(); // mark it on the open nodes map

    // A* search
    while(!pq[pqi].empty())
    {
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); // remove the node from the open list
        astarParam.open_nodes_map.at(x).at(y) = 0;
        // mark it on the closed nodes map
        astarParam.closed_nodes_map.at(x).at(y) = 1;

        // quit searching when the goal state is reached
        if(x == xEnd && y == yEnd)
        {
            // generate the path from finish to start
            // by following the directions
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j = astarParam.dir_map.at(x).at(y);
                c = '0' + (j + astarParam.dir/2) % astarParam.dir;
                path=c+path;
                x += astarParam.dx[j];
                y += astarParam.dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();
            return path;
        }

        // generate moves (child nodes) in all possible directions
        for(i = 0; i < astarParam.dir; i++)
        {
            xdx = x + astarParam.dx[i];
            ydy = y + astarParam.dy[i];

            if(!(xdx<0 || xdx>astarParam.dir_map.size()-1 || ydy<0 || ydy>astarParam.dir_map.at(0).size()-1 || astarParam.maps.at(xdx).at(ydy) == 255 || astarParam.closed_nodes_map.at(xdx).at(ydy)==1))
            {
                // generate a child node
                m0=new node( xdx, ydy, n0->getLevel(),
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xEnd, yEnd);

                // if it is not in the open list then add into that
                if(astarParam.open_nodes_map.at(xdx).at(ydy) == 0)
                {
                    astarParam.open_nodes_map.at(xdx).at(ydy) = m0->getPriority();
                    pq[pqi].push(*m0);
                    // mark its parent node direction
                    astarParam.dir_map.at(xdx).at(ydy) = (i + astarParam.dir/2) % astarParam.dir;
                }
                else if(astarParam.open_nodes_map.at(xdx).at(ydy) > m0->getPriority())
                {
                    // update the priority info
                    astarParam.open_nodes_map.at(xdx).at(ydy) = m0->getPriority();
                    // update the parent direction info
                    astarParam.dir_map.at(xdx).at(ydy) = (i + astarParam.dir/2) % astarParam.dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getxPos()==xdx &&
                           pq[pqi].top().getyPos()==ydy))
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pq[pqi].pop(); // remove the wanted node

                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return ""; // no route found

}

