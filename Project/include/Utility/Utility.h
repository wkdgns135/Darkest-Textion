#pragma once
#include <random>
#include <vector>
using namespace std;

// PRNG로 지정한 범위의 값을 랜덤으로 생성해주는 함수
template <typename T>
T GetRandomValue(T min, T max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<T> dist(min, max);
    return dist(gen);
}

// 벡터의 원소를 하나 랜덤으로 꺼내는 함수
template <typename T>
T GetRandomElement(const vector<T>& vec) {
    if (vec.empty()) {
        throw out_of_range("Vector is empty");
    }
    size_t index = GetRandomValue<size_t>(0, vec.size() - 1);
    return vec[index];
}
