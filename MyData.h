#pragma once
#include<iostream>
using namespace std;
enum Priority { LOW, MEDIUM, HIGH };

template<class T>
class MyData
{
public:
	T value;
	MyData* next = nullptr;
	MyData* prev = nullptr;
	Priority pre = LOW;
	MyData() {}
};