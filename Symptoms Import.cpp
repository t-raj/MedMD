//
//  Symptoms Import.cpp
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#include "Symptoms Import.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

SymptomsImport::SymptomsImport(){ //creates a SymptomsImport object
    this->grabDiseases();
    this->grabSymptoms();
};

void SymptomsImport::grabDiseases(){ //reads in the conditions from the diseases file
    
    std::string temp;
    
    std::ifstream in;
    in.open("Diseases.t");
    
    if(!in.is_open()){
        std::cout << "Error: Welcome file not found, make sure file \"Diseases.t\" is in the relative path. Exit now" << std::endl;
        return;
    }
    
    while (in.peek() != EOF){
        while (in.peek() != '\n' && in.peek() != EOF){
            temp += in.get();
        }
        in.get();
        diseases.push_back(temp);
        temp = "";
    }
    
    in.clear();
    in.close();
    
    int indexKey;
    int index;
    std::string subString;
    
    for (int i = 0; i<diseases.size(); i++){
        std::vector<std::string> tempVect = *new std::vector<std::string>;
            indexKey = (int)diseases[i].find_first_of(':');
            index = indexKey;
            subString = diseases[i].substr(index+1);
            while(subString.find_first_of(',')!=-1){
                index = (int)subString.find_first_of(',');
                tempVect.push_back(subString.substr(0,index));
                subString = subString.substr(index+1);
            }
        tempVect.push_back(subString);

        diseaseDict[diseases[i].substr(0,indexKey)]=tempVect;
    }
    
    return;
};

void SymptomsImport::grabSymptoms(){ //reads in the symptoms from the symptoms file
    
    std::string temp;
    
    std::ifstream in;
    in.open("Symptoms.t");
    
    if(!in.is_open()){
        std::cout << "Error: Welcome file not found, make sure file \"Symptoms.t\" is in the relative path. Exit now" << std::endl;
        return;
    }
    
    while (in.peek() != EOF){
        while (in.peek() != ',' && in.peek() != EOF){
            temp += in.get();
        }
        in.get();
        symptoms.push_back(temp);
        temp = "";
    }

    in.clear();
    in.close();
    
    return;
};