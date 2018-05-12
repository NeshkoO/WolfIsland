//
// Created by Alex Orlovskyi on 21.04.18.
//

#ifndef CPP_CONTROLLER_H
#define CPP_CONTROLLER_H

#include <iostream>
#include <algorithm>
#include <TGUI/TGUI.hpp>
#include "../model/include/Field.h"
#include "../view/ConsoleView.h"
#include "../view/GUIView.h"
#include "../view/BaseView.h"
#include "../utils/utils.h"

class Controller {
public:
    Controller();
    virtual ~Controller();

    void execute(int numberOfSteps = 0);
    std::vector<int> makeListOfAvailableStepsForRabbit(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_W(int cellNumb);
    std::vector<int> makeListOfAvailableStepsForWolf_M(int cellNumb);

    GUIView* getPGUIView();
private:
    Field field;
    BaseView* pView;
    int currentStepNumber;
    String windowTitle;
    int nRabbits;
    int nMWolves;
    int nWWolves;
    int cOfFences;
    int countOfStepsToPerform;
    bool useGUI;
    unsigned int FPS;
    Time delayTimeInSeconds;

    void initSimulationParams();
    void initializeField(int nRabbits, int nWWolves, int nMWolves, int cOfFences);
    void displayField();
    void nextStep();
    std::vector<int> calculateNeighbourCellsWithoutFences(int cellNumb);

    void calculateMoveDecisions();
    void performMoves();

    // rabbits stuff
    void rabbitSpread();

    // wolves stuff
    void wolfTryToEatOrDie();
    void Wolf_MMakeOffspring();
};

#endif //CPP_CONTROLLER_H
