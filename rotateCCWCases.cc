//
//  rotateCCWCases.cpp
//  a5_5
//
//  Created by Aurora Dai on 2017-12-02.
//  Copyright © 2017 Aurora Dai. All rights reserved.
//

#include "rotateCCWCases.h"

rotateCCWCases::rotateCCWCases(char pieceType, std::vector<std::vector<char>> area): pieceType(pieceType), area(area)
{
    int dim = (int)area.size();
    
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            if (area[i][j] == 'e')
                area[i][j] = ' ';
}
                               
bool rotateCCWCases::CCWRotate()
{
    switch(pieceType)
    {
        case 'O' :
            return true;
        case 'I' :
        {
            if (area[0][0] == ' ')
                return true;
            else
            {
                for (int i = 0; i < 3; i++) // 4-1
                    for (int j = 1; j < 4; j++)
                        if (area[i][j] != ' ')
                            return false;
                
                return true;
            }
            
        }
        case 'S' :
        {
            if (area[2][0] == 'S')
            {
                if ((area[0][0] == ' ') && (area[0][1] == ' ') && (area[0][2] == ' ') && (area[1][0] == ' '))
                    return true;
                else
                    return false;
            }
            
            else
            {
                if ((area[2][0] == ' ') && (area[2][2] == ' '))
                    return true;
                else
                    return false;
            }
        }
        case 'Z' :
        {
             if (area[2][0] == 'Z')
             {
                 if ((area[0][0] == ' ') && (area[2][1] == ' ') && (area[2][2] == ' '))
                     return true;
                 else
                     return false;
             }
            else
            {
                if ((area[0][1] == ' ') && (area[0][2] == ' ') && (area[1][2] == ' ') && (area[2][1] == ' '))
                    return true;
                else
                    return false;
            }
        }
        case 'L' :
        {
            if (area[1][1] == ' ')
            {
                {
                    if ((area[1][2] == ' ') && (area[2][2] == ' '))
                        return true;
                    else
                        return false;
                }
                else
                {
                    if ((area[0][0] == ' ') && (area[0][1] == ' ') && (area[0][2] == ' ') && (area[1][1] == ' '))
                        return true;
                    else
                        return false;
                }
            }
            else
            {
                if (area[0][0] == 'L')
                {
                    if ((area[1][0] == ' ') && (area[1][2] == ' ') && (area[2][0] == ' ') && (area[2][2] == ' '))
                        return true;
                    else
                        return false;
                }
                else
                {
                    if ((area[0][0] == ' ') && (area[0][1] == ' ') && (area[0][2] == ' ') && (area[2][1] == ' '))
                        return true;
                    else
                        return false;
                }
            }
        }
        case 'J' :
        {
            if (area[1][1] == 'J')
            {
                if (area[0][1] == 'J')
                {
                    if ((area[0][0] == ' ') && (area[1][0] == ' ') && (area[1][2] == ' ') && (area[2][2] == ' '))
                        return true;
                    else
                        return false;
                }
                else
                {
                    if ((area[0][0] == ' ') && (area[0][1] == ' ') && (area[0][2] == ' ') && (area[2][1] == ' '))
                        return true;
                    else
                        return false;
                }
            }
            else
            {
                if (area[0][1] == 'J')
                {
                    if ((area[2][1] == ' ') && (area[2][2] == ' '))
                        return true;
                    else
                        return false;
                }
                else
                {
                    if ((area[0][1] == ' ') && (area[0][2] == ' ') && (area[1][1] == ' ') && (area[1][2] == ' '))
                        return true;
                    else
                        return false;
                }
            }
        }
        
        case 'T' :
        {
            
        }
            
            
    }
}
