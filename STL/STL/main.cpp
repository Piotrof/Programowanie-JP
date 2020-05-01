#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int wektor(vector<int> nums) {
    std::string line;
    int number;
    std::vector<int> numbers;

    std::cout << "Enter numbers separated by spaces: ";
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
        numbers.push_back(number);
    nums = numbers;
    make_heap(numbers.begin(), numbers.end());
};

int max(vector<int> nums){
    make_heap(nums.begin(), nums.end());
    cout << "Najwiekszy element to: ";
    cout << nums.front();
};

vector<int> dod(vector<int> nums) {
    int a;
    make_heap(nums.begin(), nums.end());
    cout << "Podaj liczbe ktora chcesz dodac" << endl;
    cin >> a;
    nums.push_back(a);
    return nums;
};

vector<int> usuwanie(vector<int> nums) {
    make_heap(nums.begin(), nums.end());
    pop_heap(nums.begin(), nums.end());
    nums.pop_back();
    return nums;
};

vector<int> sortowanie(vector<int> nums) {
    make_heap(nums.begin(), nums.end());
    sort_heap(nums.begin(), nums.end());
    return nums;
};


int main()
{
    int selection;
    vector<int> nums; 
    do
    {
        cout << "1. utwórz wektor + konwersja";
        cout << "2. sortuj"; 
        cout << "3. dodaj element";
        cout << "4. wyswietl najwiekszy element"; 
        cout << "5.usun najwiekszy element";
        cout << "6.zakoncz program";
        cin >> selection;
        cout << endl;

        switch (selection)
        {
        case '1':
            wektor(nums);
            break;

        case '4':
            max(nums);
            break;

        case '3':
            nums = dod(nums);
            break;

        case '5':
            nums = usuwanie(nums);
            break;

        case '2':
            nums = sortowanie(nums);
            break;

        case '6':
            cout << "Koniec dzialania programu.\n";
            break;

        default: 
            break;
        }

    } while (selection != 6);

    return 0;
}