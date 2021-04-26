#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int> selectionSort(std::vector<int> list){
    //logic to sort array
    int min = INT_MAX;
    int minIndex = -1;
    //std::vector<int> sortedList = unsortedList;

    for(int i = 0; i<list.size(); i++){
        min = INT_MAX;
        for(int j = i; j<list.size(); j++){
            if(list[j]<min){
                min = list[j];
                minIndex = j;
            }
        }
        //swap to sort in place.
        if(minIndex!=i){
            std::swap(list[i],list[minIndex]);
        }
    }

    return list;
}

std::vector<int> bubbleSort(std::vector<int> list){
    //logic to sort array
    int minIndex = 0;
    bool swapped = true;
    
    while(swapped){
        swapped = false;
        for(int i = 0; i<list.size()-1; i++){
            if(list[i]>list[i+1]){
                std::swap(list[i],list[i+1]);
                swapped = true;
            }
        }
    }
    return list;
}

void displayList(std::vector<int> list){
    std::cout<<"[";
    for(int i=0; i<list.size(); i++){
        if(i == list.size()-1){
            std::cout<<list[i];
        } else {
            std::cout<<list[i]<<",";
        }
    }
    std::cout<<"]"<<std::endl;
}

std::vector<int> randomList(int n){
    std::vector<int> list(n);
    for(int i=0; i<n; i++){
        list[i] = (rand()%n)+1;
    }
    return list;
}

std::vector<int> randomList(int n, int limit){
    std::vector<int> list(n);
    for(int i=0; i<n; i++){
        list[i] = (rand()%limit)+1;
    }
    return list;
}

int main(int, char**) {
    std::vector<int> list = randomList(10,25); 
    std::vector<int> ss_list; //selection sort list
    std::vector<int> bs_list; //bubble sort list
    
    std::cout<<"Unsorted List: ";
    displayList(list);
    
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    ss_list = selectionSort(list);
    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout<<"Sorted List (Selection Sort - "<< ms.count() <<"ns ): \t";
    displayList(ss_list);

    start = std::chrono::steady_clock::now();
    bs_list = bubbleSort(list);
    end = std::chrono::steady_clock::now();
    ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout<<"Sorted List (Bubble Sort - "<< ms.count() <<"ns ): \t";
    displayList(bs_list);
}


