#include <iostream>
#include <math.h>
#include "aStarNode.h"




ANode::ANode (int xpos, int ypos, int G, int F){
    _xCurrentPosition=xpos;
    _yCurrentPosition=ypos;
    _distanceG=G;
    _distanceF=F;
}

int ANode::getXPosition() const {
    return _xCurrentPosition;
}
int ANode::getYPosition() const {
    return _yCurrentPosition;
}
int ANode::getDistanceG() const {
    return -_distanceG;
}
int ANode::getDistanceF() const {
    return _distanceF;
}

void ANode::updateDistanceF(const int & xDest, const int & yDest)
{
    _distanceF=_distanceG+calculateHeuristic(xDest, yDest)*10; //A*
}

// give better priority to going strait instead of diagonally
void ANode::UpdateDistanceG(const int & i){ // i: direction

    if(i%2!=0)
        _distanceG+=14;
    else
        _distanceG+=10;

}

// Estimation function for the remaining distance to the goal.
const int & ANode::calculateHeuristic(const int & xDestinyPosition, const int & yDestinYPosition) const{

    static int xDistance, yDistance, finalDistance;
    xDistance=xDestinyPosition-_xCurrentPosition;
    yDistance=yDestinYPosition-_yCurrentPosition;

    // Euclidian Distance
    finalDistance=(int)(sqrt(xDistance*xDistance+yDistance*yDistance));

    // Manhattan distance
    //finalDistance=abs(xDistance)+abs(yDistance);

    // Chebyshev distance
    //finalDistance=max(abs(xDistance), abs(yDistance));

    return(finalDistance);
}

ANode::~ANode(){}

//bool ANode::operator<( ANode a, ANode b){
  //  return a.getDistanceF() < b.getDistanceF();
//}
