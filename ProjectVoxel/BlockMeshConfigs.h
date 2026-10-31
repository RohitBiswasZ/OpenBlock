#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"

class BlockMeshConfigs {
public:
	static void addUpperFaceVertices(float x, float y, float z, std::vector<float>& vertices);
	static void addDownFaceVertices(float x, float y, float z, std::vector<float>& vertices);

	static void addFrontFaceVertices(float x, float y, float z, std::vector<float>& vertices);
	static void addBackFaceVertices(float x, float y, float z, std::vector<float>& vertices);

	static void addLeftFaceVertices(float x, float y, float z, std::vector<float>& vertices);
	static void addRightFaceVertices(float x, float y, float z, std::vector<float>& vertices);
	static void addFaceTriangles(int vertexCount, std::vector<unsigned short>& indices);
	static void addFaceBrightness(float brightness,std::vector<unsigned char>& colors);
};

