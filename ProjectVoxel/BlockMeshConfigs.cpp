#include "BlockMeshConfigs.h"

void BlockMeshConfigs::addUpperFaceVertices(float x, float y, float z, std::vector<float> &vertices) {
	// vertex 1
	vertices.push_back(1 + x);
	vertices.push_back(1 + y);
	vertices.push_back(0 + z);
	//vertex 2
	vertices.push_back(0 + x);
	vertices.push_back(1 + y);
	vertices.push_back(0 + z);
	//vertex 3
	vertices.push_back(1 + x);
	vertices.push_back(1 + y);
	vertices.push_back(1 + z);
	//vertex 4
	vertices.push_back(0 + x);
	vertices.push_back(1 + y);
	vertices.push_back(1 + z);
}

void BlockMeshConfigs::addDownFaceVertices(float x, float y, float z, std::vector<float> &vertices) {
	//vertex 3
	vertices.push_back(1 + x);
	vertices.push_back(0 + y);
	vertices.push_back(1 + z);
	//vertex 4
	vertices.push_back(0 + x);
	vertices.push_back(0 + y);
	vertices.push_back(1 + z);
	// vertex 1
	vertices.push_back(1 + x);
	vertices.push_back(0 + y);
	vertices.push_back(0 + z);
	//vertex 2
	vertices.push_back(0 + x);
	vertices.push_back(0 + y);
	vertices.push_back(0 + z);

}

void BlockMeshConfigs::addFrontFaceVertices(float x, float y, float z, std::vector<float> &vertices) {
	// vertex 1
	vertices.push_back(1 + x);
	vertices.push_back(1 + y);
	vertices.push_back(1 + z);
	//vertex 2
	vertices.push_back(0 + x);
	vertices.push_back(1 + y);
	vertices.push_back(1 + z);
	//vertex 3
	vertices.push_back(1 + x);
	vertices.push_back(0 + y);
	vertices.push_back(1 + z);
	//vertex 4
	vertices.push_back(0 + x);
	vertices.push_back(0 + y);
	vertices.push_back(1 + z);

}

void BlockMeshConfigs::addBackFaceVertices(float x, float y, float z, std::vector<float> &vertices) {
	//vertex 3
	vertices.push_back(1 + x);
	vertices.push_back(0 + y);
	vertices.push_back(0 + z);
	//vertex 4
	vertices.push_back(0 + x);
	vertices.push_back(0 + y);
	vertices.push_back(0 + z);
	// vertex 1
	vertices.push_back(1 + x);
	vertices.push_back(1 + y);
	vertices.push_back(0 + z);
	//vertex 2
	vertices.push_back(0 + x);
	vertices.push_back(1 + y);
	vertices.push_back(0 + z);
}

void BlockMeshConfigs::addRightFaceVertices(float x, float y, float z, std::vector<float> &vertices) {
	//vertex 3
	vertices.push_back(0 + x);
	vertices.push_back(0 + y);
	vertices.push_back(0 + z);
	//vertex 4
	vertices.push_back(0 + x);
	vertices.push_back(0 + y);
	vertices.push_back(1 + z);
	// vertex 1
	vertices.push_back(0 + x);
	vertices.push_back(1 + y);
	vertices.push_back(0 + z);
	//vertex 2
	vertices.push_back(0 + x);
	vertices.push_back(1 + y);
	vertices.push_back(1 + z);
}

void BlockMeshConfigs::addLeftFaceVertices(float x, float y, float z, std::vector<float> &vertices) {
	// vertex 1
	vertices.push_back(1 + x);
	vertices.push_back(1 + y);
	vertices.push_back(0 + z);
	//vertex 2
	vertices.push_back(1 + x);
	vertices.push_back(1 + y);
	vertices.push_back(1 + z);
	//vertex 3
	vertices.push_back(1 + x);
	vertices.push_back(0 + y);
	vertices.push_back(0 + z);
	//vertex 4
	vertices.push_back(1 + x);
	vertices.push_back(0 + y);
	vertices.push_back(1 + z);
}

void BlockMeshConfigs::addFaceTriangles(int vertexCount, std::vector<unsigned short>& indices) {
	indices.push_back(0 + vertexCount);
	indices.push_back(1 + vertexCount);
	indices.push_back(2 + vertexCount);

	indices.push_back(3 + vertexCount);
	indices.push_back(2 + vertexCount);
	indices.push_back(1 + vertexCount);
}

void BlockMeshConfigs::addFaceBrightness(float brightness, std::vector<unsigned char>& colors) {
	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255);

	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255);

	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255);

	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255 * brightness);
	colors.push_back(255);
}