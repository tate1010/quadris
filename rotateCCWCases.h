//
//  rotateCCWCases.hpp
//  a5_5
//
//  Created by Aurora Dai on 2017-12-02.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#ifndef rotateCCWCases_hpp
#define rotateCCWCases_hpp

#include <vector>

class rotateCCWCases
{
    char pieceType;
    std::vector<std::vector<char>> area;
    
public:
    rotateCCWCases(char pieceType, std::vector<std::vector<char>> area);
    bool CCWRotate();
};

#endif /* rotateCCWCases_hpp */
