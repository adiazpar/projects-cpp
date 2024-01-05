#pragma once

// Specification file for the roomcarpet class:
#ifndef RoomCarpet_h
#define RoomCarpet_h
#include "RoomDimension.h"

// Include Headers:


class RoomCarpet {
private:
    RoomDimension dimensions;   // The room dimensions
    double cost;                // Cost per square foot
    
public:
    // Constructor:
    RoomCarpet(RoomDimension rd, double c)
    {
        dimensions = rd;
        cost = c;
    }
    
    // Get the total cost with this function:
    double getTotalCost()
    {
        double area = dimensions.getArea();
        return area * cost;
    }
};

#endif
