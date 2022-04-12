#pragma once
#include "Bar.h"
#include <vector>
#include <iostream>

class Sorters{
public:
    sf::Text DelayTimeText;
    sf::RenderWindow *Window = nullptr;
    int PauseTime = 2; //milliseconds
    bool End = false;
    std::vector<Bar> MainArray;
    Sorters(){}
    Sorters(sf::RenderWindow *window){
        Window = window;
    }
    void GenerateRandomArray(int size);
    void DrawBarArray();
    void Pause(int time);
    virtual void SortFunction() = 0;
};

class MergeSorter : public Sorters{
public:
    MergeSorter(){
        DelayTimeText.setString("Delay = "+std::to_string(PauseTime)+"ms"+"\nMerge Sorter");
        DelayTimeText.setPosition(100,50);
    }
    MergeSorter(sf::RenderWindow *window, sf::Font &font){
        DelayTimeText.setFont(font);
        //DelayTimeText.setString("Delay = "+std::to_string(PauseTime)+"ms"+"\nMerge Sorter");
        DelayTimeText.setCharacterSize(24);
        sf::FloatRect rect = DelayTimeText.getLocalBounds();
        DelayTimeText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
        DelayTimeText.setColor(sf::Color::Black);
        DelayTimeText.setPosition(20,50);
        Window = window;
    }
    void SortFunction(){
        DelayTimeText.setString(DelayTimeText.getString()+"\nMerge Sorter");
        MergeSort(MainArray,0,MainArray.size()-1);
        End = false;
        PauseTime = 10;
        for(int i=0; i<MainArray.size(); i++){
            MainArray[i].m_Color = sf::Color::Black;
        }
    }
    void Merge(std::vector<Bar>&v, int l, int m, int r){
        std::vector<Bar> v1;
        int i1=l, i2=m+1;
        while(i1<=m && i2<=r){
            if(v[i1].m_Height < v[i2].m_Height){
                v1.push_back(v[i1]);
                v[i1].m_Color = sf::Color::Yellow;
                v[l].m_Color = sf::Color::Blue;
                v[r].m_Color = sf::Color::Blue;
                v[m].m_Color = sf::Color::Red;
                DrawBarArray();
                i1++;
            }
            else{
                v1.push_back(v[i2]);
                v[i2].m_Color = sf::Color::Yellow;
                v[l].m_Color = sf::Color::Blue;
                v[r].m_Color = sf::Color::Blue;
                v[m].m_Color = sf::Color::Red;
                DrawBarArray();
                i2++;
            }
        }
        while(i2<=r){
            v1.push_back(v[i2]);
            v[i2].m_Color = sf::Color::Yellow;
            v[l].m_Color = sf::Color::Blue;
            v[r].m_Color = sf::Color::Blue;
            v[m].m_Color = sf::Color::Red;
            DrawBarArray();
            i2++;
        }
        while(i1<=m){
            v1.push_back(v[i1]);
            v[i1].m_Color = sf::Color::Green;
            v[l].m_Color = sf::Color::Blue;
            v[r].m_Color = sf::Color::Blue;
            v[m].m_Color = sf::Color::Red;
            DrawBarArray();
            i1++;
        }
        for(int i=l; i<=r; i++){
            v[i].m_Height = v1[i-l].m_Height;
            v[i].m_Color = sf::Color::Green;
            v[l].m_Color = sf::Color::Blue;
            v[r].m_Color = sf::Color::Blue;
            v[m].m_Color = sf::Color::Red;
            DrawBarArray();
        }
    }

    void MergeSort(std::vector<Bar> &v, int l, int r){
        if(l < r){
            int m = (l+r)/2;
            MergeSort(v,l,m);
            MergeSort(v,m+1,r);
            Merge(v,l,m,r);
        }
        return;
    }
};

class BubbleSorter : public Sorters{
public:
    BubbleSorter(sf::RenderWindow *window, sf::Font &font){
        DelayTimeText.setFont(font);
        //DelayTimeText.setString("Delay = "+std::to_string(PauseTime)+"ms"+"\nBubble Sorter");
        DelayTimeText.setCharacterSize(24);
        sf::FloatRect rect = DelayTimeText.getLocalBounds();
        DelayTimeText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
        DelayTimeText.setColor(sf::Color::Black);
        DelayTimeText.setPosition(20,50);
        Window = window;
    }
    BubbleSorter(){}
    void SortFunction(){
        DelayTimeText.setString(DelayTimeText.getString()+"\nBubble Sorter");
        BubbleSort(MainArray);
        End = false;
        PauseTime = 10;
        for(int i=0; i<MainArray.size(); i++){
            MainArray[i].m_Color = sf::Color::Black;
        }
    }
    void BubbleSort(std::vector<Bar> &v){
        int swapped = false;
        for(int i=0; i<v.size()-1; i++){
            if(v[i].m_Height > v[i+1].m_Height){
                swapped = true;
                int temp = v[i].m_Height;
                v[i].m_Height = v[i+1].m_Height;
                v[i+1].m_Height = temp;
                v[i].m_Color = sf::Color::Blue;
                v[i+1].m_Color = sf::Color::Green;
                DrawBarArray();
            }
        }
        if(swapped){
            BubbleSort(v);
        }
    }
};

class InsertionSorter : public Sorters{
public:
    InsertionSorter(){}
    InsertionSorter(sf::RenderWindow *window, sf::Font &font){
        DelayTimeText.setFont(font);
        //DelayTimeText.setString("Delay = "+std::to_string(PauseTime)+"ms"+"\nInsertion Sorter");
        DelayTimeText.setCharacterSize(24);
        sf::FloatRect rect = DelayTimeText.getLocalBounds();
        DelayTimeText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
        DelayTimeText.setColor(sf::Color::Black);
        DelayTimeText.setPosition(20,50);
        Window = window;
    }
    void SortFunction(){
        DelayTimeText.setString(DelayTimeText.getString()+"\nInsertion Sorter");
        InsertionSort(MainArray);
        End = false;
        PauseTime = 10;
        for(int i=0; i<MainArray.size(); i++){
            MainArray[i].m_Color = sf::Color::Black;
        }
        DrawBarArray();
    }
    void InsertionSort(std::vector<Bar> &v){
        int key,j;
        for(int i=1; i<v.size(); i++){
            key = v[i].m_Height;
            j = i-1;
            while(j >= 0 && v[j].m_Height > key){
                v[j+1].m_Height = v[j].m_Height;
                v[j+1].m_Color = sf::Color::Green;
                DrawBarArray();
                j--;
            }
            v[j+1].m_Height = key;
            v[j+1].m_Color = sf::Color::Green;
            DrawBarArray();
        }
    }
};

class QuickSorter : public Sorters{
public:
    QuickSorter(){}
    QuickSorter(sf::RenderWindow *window, sf::Font &font){
        DelayTimeText.setFont(font);
        //DelayTimeText.setString("Delay = "+std::to_string(PauseTime)+"ms"+"\nQuick Sorter");
        DelayTimeText.setCharacterSize(24);
        sf::FloatRect rect = DelayTimeText.getLocalBounds();
        DelayTimeText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
        DelayTimeText.setColor(sf::Color::Black);
        DelayTimeText.setPosition(20,50);
        Window = window;
    }
    void SortFunction(){
        DelayTimeText.setString(DelayTimeText.getString()+"\nQuick Sorter");
        QuickSort(MainArray,0,MainArray.size()-1);
        End = false;
        PauseTime = 10;
        for(int i=0; i<MainArray.size(); i++){
            MainArray[i].m_Color = sf::Color::Black;
        }
    }
    void Swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
        return;
    }
    int Partiton(std::vector<Bar> &v, int l, int r){
        int i=l, j=r;
        int pivot = v[l].m_Height;
        while(j>i){
            while(pivot>=v[i].m_Height && i<v.size()-1){
                v[i].m_Color = sf::Color::Yellow;
                v[l].m_Color = sf::Color::Blue;
                v[r].m_Color = sf::Color::Blue;
                DrawBarArray();
                i++;
            }
            while(pivot<v[j].m_Height){
                v[j].m_Color = sf::Color::Yellow;
                v[l].m_Color = sf::Color::Blue;
                v[r].m_Color = sf::Color::Blue;
                DrawBarArray();
                j--;
            }
            if(i<j){
                Swap(v[i].m_Height,v[j].m_Height);
                v[i].m_Color = sf::Color::Green;
                v[j].m_Color = sf::Color::Green;
                DrawBarArray();
            }
        }
        Swap(v[l].m_Height,v[j].m_Height);
        v[j].m_Color = sf::Color::Green;
        DrawBarArray();
        return j;
    }
    void QuickSort(std::vector<Bar> &v, int l, int r){
        if(r>l){
            int p = Partiton(v,l,r);
            QuickSort(v,l,p-1);
            QuickSort(v,p+1,r);
        }
        return;
    }
};