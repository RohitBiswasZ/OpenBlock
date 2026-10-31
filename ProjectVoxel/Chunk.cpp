#include "Chunk.h"

Chunk::Chunk(int x, int z,BlockState initialBlock) {
	posX = x;
	posZ = z;
	for (int i = 0; i < sizeof(blockList) / sizeof(BlockState); i++) {
		blockList[i] = initialBlock;
	}
	this->mat = LoadMaterialDefault();
	this->matrix = MatrixTranslate(x,0,z);
}

void Chunk::construct() {
	UnloadMesh(this->mesh);
	this->mesh = { 0 };
	int vertexCount = 0;
	int triangleCount = 0;
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			for (int z = 0; z < DEPTH; z++) {
				BlockState blockState = getBlock(x, y, z);
			
				if (blockState == BlockState::Stone) {
					BlockState upBlock = getBlock(x, y + 1, z);
					BlockState downBlock = getBlock(x, y - 1, z);
					BlockState frontBlock = getBlock(x, y, z + 1);
					BlockState backBlock = getBlock(x, y, z - 1);
					BlockState rightBlock = getBlock(x - 1, y, z);
					BlockState leftBlock = getBlock(x + 1, y, z);
					if (upBlock == BlockState::None) {
						BlockMeshConfigs::addUpperFaceVertices(x, y, z, this->vertices);
						BlockMeshConfigs::addFaceTriangles(vertexCount, indices);
						BlockMeshConfigs::addFaceBrightness(1, colors);
						vertexCount += 4;
						triangleCount += 2;
					}

					if (downBlock == BlockState::None) {
						BlockMeshConfigs::addDownFaceVertices(x, y, z, this->vertices);
						BlockMeshConfigs::addFaceTriangles(vertexCount, indices);
						BlockMeshConfigs::addFaceBrightness(0.35f, colors);
						vertexCount += 4;
						triangleCount += 2;
					}

					if (frontBlock == BlockState::None) {
						BlockMeshConfigs::addFrontFaceVertices(x, y, z, this->vertices);
						BlockMeshConfigs::addFaceTriangles(vertexCount, indices);
						BlockMeshConfigs::addFaceBrightness(0.6f, colors);
						vertexCount += 4;
						triangleCount += 2;
					}

					if (backBlock == BlockState::None) {
						BlockMeshConfigs::addBackFaceVertices(x, y, z, this->vertices);
						BlockMeshConfigs::addFaceTriangles(vertexCount, indices);
						BlockMeshConfigs::addFaceBrightness(0.6f, colors);
						vertexCount += 4;
						triangleCount += 2;
					}

					if (rightBlock == BlockState::None) {
						BlockMeshConfigs::addRightFaceVertices(x, y, z, this->vertices);
						BlockMeshConfigs::addFaceTriangles(vertexCount, indices);
						BlockMeshConfigs::addFaceBrightness(0.8f, colors);
						vertexCount += 4;
						triangleCount += 2;
					}

					if (leftBlock == BlockState::None) {
						BlockMeshConfigs::addLeftFaceVertices(x, y, z, this->vertices);
						BlockMeshConfigs::addFaceTriangles(vertexCount, indices);
						BlockMeshConfigs::addFaceBrightness(0.8f, colors);
						vertexCount += 4;
						triangleCount += 2;
					}
				}
			}
		}
	}
	mesh.vertexCount = vertexCount;
	mesh.triangleCount = triangleCount;

	this->mesh.vertices = (float*)malloc(vertices.size() * sizeof(float*));
	this->mesh.indices = (unsigned short*)malloc(indices.size() * sizeof(unsigned short*));
	this->mesh.colors = (unsigned char*)malloc(colors.size() * sizeof(unsigned char*));
	memcpy(this->mesh.vertices, vertices.data(), vertices.size() * sizeof(float));
	memcpy(this->mesh.indices, indices.data(), indices.size() * sizeof(unsigned short));
	memcpy(this->mesh.colors, colors.data(), colors.size() * sizeof(unsigned char));

	UploadMesh(&this->mesh, false);
}

void Chunk::render() {
	DrawMesh(mesh, mat, matrix);
}
