//
//  User Interactions.cpp
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#include "User Interactions.h"
#include <stdio.h>
#include <fstream>
#include <iostream>

UserInteractions::UserInteractions(){ //creates a UserInteractions object
    quit = false;
    cinIsBuggy = true;
};

std::string UserInteractions::askSymptom(){ //prompt the user to enter symptoms until they type Q to quit
    std::string input = "";
    std::string temp = "";
    
    while (input == ""){
            std::cout << std::endl << "Add a symptom (see above), or type Q to quit" << std::endl;
        if (cinIsBuggy){
            getline(std::cin, input);
            cinIsBuggy = false;
        }
            getline(std::cin, input);
    }
    temp = input;
    if (temp == "Q"){
        quit = true;
    }
    input = "";
    return temp;
};