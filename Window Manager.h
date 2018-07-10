//
//  Window Manager.h
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#ifndef __Final_Project__Window_Manager__
#define __Final_Project__Window_Manager__

#include <stdio.h>
#include <string>
#include <vector>
#include "Symptoms Import.h"

class WindowManager{
    
private:
    std::string userName;
    std::vector<std::string> diseaseList[5];
    int maxLine;
    SymptomsImport list;
public:
    WindowManager();
    
    void clear();
    
    void printSymptoms();
    bool RSymptoms(std::string symptom);
    
    std::string welcomeScreen();
    void printResults(std::vector<std::string> userSymptoms);
    
    int CountComma(std::string input);
};


#endif /* defined(__Final_Project__Window_Manager__) */
