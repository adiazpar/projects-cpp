#pragma once

// Specification file for the RoomDimension class:
#ifndef RoomDimension_h
#define RoomDimension_h
#include "FeetInches.h"

class RoomDimension {
private:
    FeetInches length;  // The length of the room
    FeetInches width;   // The width of the room
    FeetInches area;    // The room's area
    
public:
    // Default constructor:
    RoomDimension() {}
    
    // Constructor:
    RoomDimension(FeetInches len, FeetInches w)
    {
        length = len;
        width = w;
        area = len.multiply(w);
    }
    
    // Copy Constructor:
    RoomDimension(const RoomDimension& obj)
    {
        length = obj.length;
        width = obj.width;
        area = obj.area;
    }
    
    // getArea function:
    FeetInches getArea()
    {
        return area;
    }
};

#endif
