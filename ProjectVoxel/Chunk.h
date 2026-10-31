#pragma once
#include "raylib.h"
#include "BlockState.h"
#include <iostream>
#include <vector>
#include "BlockMeshConfigs.h"
#include "raymath.h"
class Chunk {
	int posX = 0;
	int posZ = 0;


	Material mat;
	Matrix matrix;
	std::vector<float> vertices;
	std::vector<unsigned short> indices;
	std::vector<unsigned char> colors;

public:
	Mesh mesh = { 0 };
	static const int WIDTH = 16, HEIGHT = 64, DEPTH = 16;
	BlockState blockList[WIDTH * HEIGHT * DEPTH];

	void generateBlocks();
	Chunk(int x, int z,BlockState initialBlock);

	int getPosX() {
		return posX;
	}

	int getPosZ() {
		return posZ;
	}


	bool inChunk(int x, int y, int z) {
		return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && z >= 0 && z < DEPTH;
	}

	BlockState getBlock(int x, int y, int z) {
		if (inChunk(x, y, z)) {
			return blockList[x + y * WIDTH + z * WIDTH * HEIGHT];
		}
		return BlockState::None;
	}

	void setBlock(int x, int y ,int z, BlockState block) {
		int index = x + y * WIDTH + z * WIDTH * HEIGHT;
		blockList[index] = block;
	}


	void construct();
	void render();
};

