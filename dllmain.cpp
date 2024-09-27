// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "FastNoiseLite.h"
#include <array>
#define func extern "C" __declspec(dllexport)
 
func double NoiseGetInCoord(double t, double seed, double x, double y) {

	FastNoiseLite Noise;
	FastNoiseLite::NoiseType types[5] = { FastNoiseLite::NoiseType_Perlin,FastNoiseLite::NoiseType_Cellular,FastNoiseLite::NoiseType_OpenSimplex2,FastNoiseLite::NoiseType_Value,FastNoiseLite::NoiseType_ValueCubic};
	Noise.SetNoiseType(types[(int)t]);
	Noise.SetSeed(seed);
	return (double)Noise.GetNoise((float)x, (float)y);


}