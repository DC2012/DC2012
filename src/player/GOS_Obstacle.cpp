#include "GOS_Obstacle.h"

size_t GOS_Obstacle::obstacleCount_;

// constructor
GOS_Obstacle::GOS_Obstacle(ObjectType type, int objID, double degree, double posX, double posY)
: GameObjectStationary(type, objID, degree, posX, posY)
{
    obstacleCount_++;
}

void GOS_Obstacle::update(const std::string &str)
{
    std::istringstream istr(str);
    char endCheck;
    int type = -1;
    int objID, degree, posX, posY;
    
    istr >> type;
    switch(ObjectType(type))
    {
    case OBSTACLE:
        istr >> objID >> degree >> posX >> posY >> endCheck;
        
        if(!istr.good() || endCheck != OBSTACLE_STR)
            break;
            
        type_ = ObjectType(type);
        objID_ = objID;
        degree_.setDegree(double(degree));
        pos_.setX(double(posX));
        pos_.setY(double(posY));
        break;
    }
}

std::string GOS_Obstacle::toString() const
{
    std::ostringstream ostr;
    
    ostr << int(type_) << " ";
    ostr << objID_ << " ";
    ostr << int(degree_.getDegree()) << " ";
    ostr << int(pos_.getX()) << " ";
    ostr << int(pos_.getY()) << " ";
    ostr << OBSTACLE_STR;
    
    return ostr.str();
}

void GOS_Obstacle::print(std::ostream& os)const
{
    os << "Number #" << obstacleCount_ << " obstacle" << std::endl;
    GameObjectStationary::print(os);
    os << std::endl << std::endl;
}
