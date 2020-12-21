#pragma once
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <functional>
#include "sequence.h"
using namespace std;



template <typename T>
class Sorter
{
protected:
    void swap(Sequence<T>& seq, int i1, int i2) {
        T item = seq.get(i1);
        seq.set(seq.get(i2), i1);
        seq.set(item, i2);
    }
public:
    Sorter() {};
           
    void bubblesort(Sequence<T>& seq, int(*func)(T, T), int mode = 0) {
        int size = seq.getSize();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (mode < 0) {
                    if (func(seq.get(j), seq.get(j + 1)) < 0) {
                        swap(seq, j, j + 1);
                    }
                }
                else {
                    if (func(seq.get(j), seq.get(j + 1)) > 0) {
                        swap(seq, j, j + 1);
                    }
                }
                
            }
        }
    }

    void shakersort(Sequence<T>& seq, int(*func)(T, T), int mode = 0)
    {

        int size = seq.getSize();
        int left = 0; int right = size - 1; 
        int flag = 1; //флаг наличия перемещений 
        // Выполнение цикла пока левая граница не сомкнётся с правой
        // и пока в массиве имеются перемещения
        while ((left < right) && (flag > 0))
        {
            flag = 0;
            for (int i = left; i < right; i++) { //двигаемся слева направо
                if (mode < 0) {
                    if (func(seq.get(i), seq.get(i + 1)) < 0) {
                        swap(seq, i, i + 1);
                        flag = 1; // перемещения в этом цикле были
                    }
                }
                else {
                    if (func(seq.get(i), seq.get(i + 1)) > 0) {
                        swap(seq, i, i + 1);
                        flag = 1; // перемещения в этом цикле были
                    }
                }
                
            }
            right--; // сдвигаем правую границу на предыдущий элемент

            for (int i = right; i > left; i--)  //двигаемся справа налево
            {
                if (mode < 0) {
                    if (func(seq.get(i - 1), seq.get(i)) < 0) {
                        swap(seq, i, i - 1);
                        flag = 1; // перемещения в этом цикле были
                    }
                }
                else {
                    if (func(seq.get(i - 1), seq.get(i)) > 0) {
                        swap(seq, i, i - 1);
                        flag = 1; // перемещения в этом цикле были
                    }
                }
                
            }
            left++; // сдвигаем левую границу на следующий элемент
        }
    }

    void quicksort(Sequence<T>& seq, int(*func)(T, T), int right, int mode = 0, int left = 0)
    {

        T mid; // рассматриваемый элемент 
        int midle;
        int lborder = left; // самый левый индекс
        int rborder = right; // самый правый индекс
        mid = seq.get(left);
        while (left < right) // двигаем границы, пока не станут равными 
        {
            if (mode < 0) {
                while ((!(func(seq.get(right), mid) > 0)) && (left < right)) // пока правый элемент больше, чем рассматриваемый
                    right--; // сдвигаем правую границу 
                if (left != right) // если границы не сошлись
                {
                    seq.set(seq.get(right), left); // заменяем опору правым элементом
                    left++; // сдвигаем левую границу вправо
                }
                while ((!(func(seq.get(left), mid) < 0)) && (left < right)) // пока левый элемент меньше, чем рассматриваемый
                    left++; // сдвигаем левую границу 
                if (left != right) // если границы не сомкнулись
                {
                    seq.set(seq.get(left), right);
                    right--; // сдвигаем правую границу вправо
                }
            }
            else {
                while ((!(func(seq.get(right), mid) < 0)) && (left < right)) // пока правый элемент больше, чем рассматриваемый
                    right--; // сдвигаем правую границу 
                if (left != right) // если границы не сошлись
                {
                    seq.set(seq.get(right), left); // заменяем опору правым элементом
                    left++; // сдвигаем левую границу вправо
                }
                while ((!(func(seq.get(left), mid) > 0)) && (left < right)) // пока левый элемент меньше, чем рассматриваемый
                    left++; // сдвигаем левую границу 
                if (left != right) // если границы не сомкнулись
                {
                    seq.set(seq.get(left), right);
                    right--; // сдвигаем правую границу вправо
                }
            }
            
        }
        seq.set(mid,left); // ставим опору на место
        midle = left;
        left = lborder;
        right = rborder;
        if (left < midle) // Рекурсивно вызываем сортировку для левой и правой части массива
            quicksort(seq, func, midle - 1, mode, left);
        if (right > midle)
            quicksort(seq, func, right, mode, midle + 1);
    }

    void insertionsort(Sequence<T>& seq, int(*func)(T, T), int mode = 0) // сортировка вставками
    {
        int length = seq.getSize();
        T tmp; // временная переменная для хранения значения элемента сортируемого массива
        int item; // индекс предыдущего элемента
        for (int i = 1; i < length; i++)
        {
            tmp = seq.get(i); // инициализируем временную переменную текущим значением элемента массива
            item = i - 1; // запоминаем индекс предыдущего элемента массива
            if (mode < 0) {
                while (item >= 0 && func(seq.get(item), tmp) < 0) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
                {
                    seq.set(seq.get(item), item + 1); // перестановка элементов массива
                    seq.set(tmp, item);
                    item--;
                }
            }
            else {
                while (item >= 0 && func(seq.get(item), tmp) > 0) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
                {
                    seq.set(seq.get(item), item + 1); // перестановка элементов массива
                    seq.set(tmp, item);
                    item--;
                }
            }
            
        }
    }

    void shellsort(Sequence<T>& seq, int(*func)(T, T), int mode = 0)               // * ∆k = (b∆k−1)/2  ∆0 = N
    {
        int step, i, j;
        int size = seq.getSize();

        // Выбор шага
        for (step = size / 2; step > 0; step /= 2)
            // Перечисление элементов, которые сортируются на определённом шаге
            for (i = step; i < size; i++)
                // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
                if (mode < 0) {
                    for (j = i - step; j >= 0 && func(seq.get(j), seq.get(j + step)) < 0; j -= step)
                    {
                        swap(seq, j, j + step);
                    }
                }
                else {
                    for (j = i - step; j >= 0 && func(seq.get(j), seq.get(j + step)) > 0; j -= step)
                    {
                        swap(seq, j, j + step);
                    }
                }
                
    }

};


#endif // SORT_H
