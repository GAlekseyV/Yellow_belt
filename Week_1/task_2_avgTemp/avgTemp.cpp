//
// Created by GAlekseyV on 12.09.2018.
//
/*
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней
 * (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
 * Гарантируется, что среднее арифметическое значений температуры является целым числом.
 * Формат ввода
 * Вводится число N, затем N целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
 * Гарантируется, что N не превышает миллиона (10^6), а значения температуры, измеряющиеся в миллионных
 * долях градусов по Цельсию, лежат в диапазоне от −10^8 до 10^8. Проверять соблюдение этих ограничений не
 * нужно: вы можете ориентироваться на них при выборе наиболее подходящих типов для переменных.
 * Формат вывода
 * Первое число K — количество дней, значение температуры в которых выше среднего арифметического.
 * Затем K целых чисел — номера этих дней.
 */
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main(){
    unsigned N;
    int value;
    vector<int> temp_values;
    int64_t sum = 0;
    // Ввод значений
    cin >> N;
    while(N > 0){
        cin >> value;
        temp_values.push_back(value);
        sum += value;
        N--;
    }
    // Расчет среднего
    int avg = sum / static_cast<int>(temp_values.size());

    // Вывод
    cout << count_if(begin(temp_values), end(temp_values),[avg](auto i){return i > avg;}) << endl;
    for(size_t i = 0; i < temp_values.size(); ++i){
        if(temp_values[i] > avg){
            cout << i << " ";
        }
    }
    return 0;
}