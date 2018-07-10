//
//  User Interactions.h
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#ifndef __Final_Project__User_Interactions__
#define __Final_Project__User_Interactions__

#include <stdio.h>
#include <fstream>
#include <iostream>

class UserInteractions{
private:
    bool cinIsBuggy;
public:
    UserInteractions();
    std::string askSymptom();
    bool quit;
    
};

#endif /* defined(__Final_Project__User_Interactions__) */
