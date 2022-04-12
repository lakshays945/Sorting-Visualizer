#include "Manager.h"
#include "Button.h"

Manager::Manager(sf::RenderWindow *window,sf::Font &font){
    m_Window = window;
    m_MSorter = MergeSorter(window,font);
    m_ISorter = InsertionSorter(window,font);
    m_QSorter = QuickSorter(window,font);
    m_BSorter = BubbleSorter(window,font);
    m_CurrentSorter = &m_MSorter;
    m_CurrentSorter->GenerateRandomArray(Size);
    m_CurrentSorter->DelayTimeText.setString("Delay time = "+std::to_string(PauseTime)+"ms");
}

void Manager::PerformAction(ACTION action){
    switch(action){
        case Sort:
            if(m_CurrentSorter->MainArray.size() == 0) return;
            m_CurrentSorter->DelayTimeText.setString( m_CurrentSorter->DelayTimeText.getString()+"\nPress 'E' to end Instantly");
            m_CurrentSorter->PauseTime = PauseTime;
            m_CurrentSorter->SortFunction();
            break;
        case MergeSort:
            m_MSorter.MainArray = (m_CurrentSorter->MainArray);
            m_CurrentSorter = &m_MSorter;
            break;
        case QuickSort:
            m_QSorter.MainArray = (m_CurrentSorter->MainArray);
            m_CurrentSorter = &m_QSorter;
            break;
        case InsertionSort:
            m_ISorter.MainArray = (m_CurrentSorter->MainArray);
            m_CurrentSorter = &m_ISorter;
            break;
        case BubbleSort:
            m_BSorter.MainArray = (m_CurrentSorter->MainArray);
            m_CurrentSorter = &m_BSorter;
            break;
        case IncreaseSize:
            Size += 20 + 30*(Size>=100) + 80*(Size>=500);
            Size = std::min(1000,Size);
            if(Size < 50) Size = 50;
            m_CurrentSorter->GenerateRandomArray(Size);
            break;
        case DecreaseSize:
            Size -= 20 + 30*(Size>100) + 60*(Size>500);
            if(Size > 800) Size = 800;
            Size = std::max(Size,20);
            m_CurrentSorter->GenerateRandomArray(Size);
            break;
        case IncreaseSpeed:
            PauseTime -= PauseTime/2-(PauseTime>50)*(PauseTime/3);
            PauseTime = std::max(2,PauseTime);
            break;
        case DecreaseSpeed:
        PauseTime += PauseTime/2;
        PauseTime = std::min(150,PauseTime);
            break;
        case Reset:
            m_CurrentSorter->GenerateRandomArray(Size);
            break;
    }
    if(action >= MergeSort && action <= InsertionSort){
        for(int i=MergeSort; i<=InsertionSort; i++){
            if(i == action){
                (*m_ButtonArray)[i].m_Rectangle.setFillColor(sf::Color::Green);
            }
            else{
                (*m_ButtonArray)[i].m_Rectangle.setFillColor(sf::Color::White);
            }
        }
    }
    m_CurrentSorter->DelayTimeText.setString("Delay time = "+std::to_string(PauseTime)+"ms");
    DrawThings();
}

void Manager::DrawThings(){
    m_Window->clear(sf::Color(100,100,100));
    m_CurrentSorter->DrawBarArray();
    for(int i=0; i<m_ButtonArray->size(); i++){
        (*m_ButtonArray)[i].DrawButton();
    }
    m_Window->display();
}