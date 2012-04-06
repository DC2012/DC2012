#include "servermain.h"

Point getStartPoint(const std::map<int, GameObject *> &ships)
{
    static const Point points[] =
    {
        Point(900, 375),
        Point(1350, 775),
        Point(1725, 1025),
        Point(1250, 1275),
        Point(550, 1300),
        Point(125, 950),
        Point(500, 550)
    };
    std::map<int, GameObject *>::const_iterator it;
    std::vector<double> minDistances;
    int furthestIndex = 0;
    double distance;
    
    minDistances.assign(MAX_PLAYERS, std::numeric_limits<double>::max());
    
    for(int i = 0; i < MAX_PLAYERS; i++)
    {
        for(it = ships.begin(); it != ships.end(); it++)
        {
            distance = points[i].getDistance(it->second->getPosition());
            if(distance < minDistances[i])
            {
                minDistances[i] = distance;
            }
        }
        
        if(minDistances[i] > minDistances[furthestIndex])
        {
            furthestIndex = i;
        }
    }
    
    return points[furthestIndex];
}