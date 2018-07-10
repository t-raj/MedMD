//
//  Window Manager.cpp
//  Final Project
//
//  Created by Salomon Smeke on 12/3/14.
//  Copyright (c) 2014 Salomon & Tara. All rights reserved.
//

#include "Window Manager.h"
#include <fstream>
#include <iostream>
#include "Symptoms Import.h"
#include <map>

WindowManager::WindowManager(){		//creates a window manager      
    maxLine = 22;
    userName = this->welcomeScreen();
    this->clear();
    //import symptoms
};

void WindowManager::clear(){	//clears the window manager
    for (int i = 0; i<maxLine; i++) std::cout<<std::endl;
};

void WindowManager::printSymptoms(){  //prints the list of symptoms the user can choose from
    std::cout <<"List of available symptoms: " << std::endl;
    for (int i = 0; i<list.symptoms.size(); i++){
        std::cout << list.symptoms[i] << " : ";
    }
    std::cout << std::endl;
};

bool WindowManager::RSymptoms(std::string symptom){	//prints the list of symptoms the user hasn't input yet
    std::vector<std::string> usableSymptoms;
    
    bool found = false;
    
    for (int i = 0; i<list.symptoms.size(); i++){
        if (list.symptoms[i] != symptom){
            usableSymptoms.push_back(list.symptoms[i]);
        } else {
            found = true;
        }
    }
    list.symptoms = usableSymptoms;
    return found;
};

std::string WindowManager::welcomeScreen(){	//reads information from the welcome file
    std::string name;
    std::string temp;
    
    std::ifstream in;
    in.open("Welcome.t");
    
    if(!in.is_open()){
        std::cout << "Error: Welcome file not found, make sure file \"Welcome.t\" is in the relative path. Exit now" << std::endl;
        return "VOID";
    }
    
    while (in.peek() != EOF){
        temp += in.get();
    }
    
    in.clear();
    in.close();
    
    std::cout << temp;
    
    std::cin>>name;
    return name;
};

void WindowManager::printResults(std::vector<std::string> userSymptoms){	//prints the conditions in order from most to least likely, the percent of symptoms of that condition the user input, and whether they're likely to die from a condition (over 50% of symptoms)
    std::map<std::string,std::vector<std::string>> dictionary = list.diseaseDict;
    
    std::map<std::string,double> foundSymptoms;
    std::map<std::string,double> totalSymptoms;
    
    for (auto& x: dictionary) {
        foundSymptoms[x.first]=0;
    }
    
    for (auto& x: dictionary) {
        totalSymptoms[x.first]=0;
    }
    
    std::string currentSymptom;
    
    for (int i = 0; i < userSymptoms.size(); i++){
        currentSymptom = userSymptoms[i];
        for (auto& y: dictionary) {
            for (int j = 0; j<y.second.size(); j++){
                if (y.second[j] == currentSymptom){
                    foundSymptoms[y.first]+=1;
                }
            }
        }
    }
    
    for (auto& z: dictionary) {
        totalSymptoms[z.first]=(int)z.second.size();
    }
    
    std::string imminentDeath;
    bool dead = false;
    
    for (auto& z: dictionary) {
        std::cout << z.first << " Matches " << (foundSymptoms[z.first]/totalSymptoms[z.first])*100 << "% of symptoms" << std::endl;
        if ((foundSymptoms[z.first]/totalSymptoms[z.first])*100 >= 50){
            dead = true;
            imminentDeath += z.first;
            imminentDeath += " ";
        }
    }
    
    if (dead){
        std::cout << "Oh man, it seems youre likely to die from: " << imminentDeath << "tough break dude." << std::endl;
    }
    
};

int WindowManager::CountComma(std::string input){
    
    return 0;
}