//
//  Symptoms Import.h
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#ifndef __Final_Project__Symptoms_Import__
#define __Final_Project__Symptoms_Import__

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

class SymptomsImport{
private:
    
public:
    SymptomsImport();
    void grabDiseases();
    void grabSymptoms();
    std::vector<std::string> diseases;
    std::vector<std::string> symptoms;
    std::map<std::string,std::vector<std::string>> diseaseDict;
};

#endif /* defined(__Final_Project__Symptoms_Import__) */
