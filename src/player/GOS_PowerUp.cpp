#include "GOS_PowerUp.h"

size_t GOS_PowerUp::powerUpCount_ = 0;

// constructor
GOS_PowerUp::GOS_PowerUp(ObjectType type, int objID, double degree, double posX, double posY)
: GameObjectStationary(type, objID, degree, posX, posY)
{
    powerUpCount_++;
}

void GOS_PowerUp::update(const std::string &str)
{
    std::istringstream istr(str);
    char endCheck;
    int type = -1;
    int objID, degree, posX, posY;
    
    istr >> type;
    switch(ObjectType(type))
    {
    case POWERUP:
        istr >> objID >> degree >> posX >> posY >> endCheck;
        
        if(!istr.good() || endCheck != POWERUP_STR)
            break;
            
        type_ = ObjectType(type);
        objID_ = objID;
        degree_.setDegree(double(degree));
        pos_.setX(double(posX));
        pos_.setY(double(posY));
        break;
    }
}

std::string GOS_PowerUp::toString() const
{
    std::ostringstream ostr;
    
    ostr << int(type_) << " ";
    ostr << objID_ << " ";
    ostr << int(degree_.getDegree()) << " ";
    ostr << int(pos_.getX()) << " ";
    ostr << int(pos_.getY()) << " ";
    ostr << POWERUP_STR;
    
    return ostr.str();
}

void GOS_PowerUp::print(std::ostream& os)const
{
    os << "Number #" << powerUpCount_ << " power up" << std::endl;
    GameObjectStationary::print(os);
    os << std::endl << std::endl;
}

