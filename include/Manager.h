#pragma once
#include "Sorter.h"


enum ACTION{
    Sort, MergeSort, QuickSort, BubbleSort,InsertionSort, 
    IncreaseSize, DecreaseSize, IncreaseSpeed, DecreaseSpeed, Reset
};
class Button;
class Manager{
public:
    sf::RenderWindow *m_Window;
    MergeSorter m_MSorter;
    InsertionSorter m_ISorter;
    BubbleSorter m_BSorter;
    QuickSorter m_QSorter;
    Sorters *m_CurrentSorter = nullptr;
    std::vector<Button> *m_ButtonArray = nullptr;
    int Size = 50;
    int PauseTime = 2; //ms
    Manager(){}
    Manager(sf::RenderWindow *window,sf::Font &font);
    void PerformAction(ACTION action);
    void DrawThings();
};