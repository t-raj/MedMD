//
//  main.cpp
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>

#include "Window Manager.h"
#include "Symptoms Import.h"
#include "User Interactions.h"

int main(int argc, const char * argv[]) { //asks the user to input symptoms, calculates the ranking of which conditions are most likely and the percent of syptoms of that condition the user input, and prints it
    
    WindowManager window;
    UserInteractions user;
    
    std::string currSymptom;
    std::vector<std::string> userSymptoms;

    while (!user.quit){
        window.printSymptoms();
        currSymptom = user.askSymptom();
        if (!user.quit){
            if (window.RSymptoms(currSymptom)){
                userSymptoms.push_back(currSymptom);
            }
        }
        window.clear();
        currSymptom = "";
    }
    
    window.printResults(userSymptoms);

}