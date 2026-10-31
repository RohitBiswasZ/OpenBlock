#pragma once
#include <iostream>
#include <vector>
#include "Chunk.h"
#include <map>
class World {
	std::map<std::pair<int, int>, Chunk*> chunkMap;
	std::vector<Chunk*> activeChunks;
public:
	World(int width, int depth);
	void constructAllChunks();
	void renderAllChunks();

	Vector3 getChunkCoord(float x, float z) {
		float cx = std::floor(x / (float)Chunk::WIDTH) * Chunk::WIDTH;
		float cz = std::floor(z / (float)Chunk::DEPTH) * Chunk::DEPTH;

		return Vector3{ cx,0,cz };
	}

	void deleteAllChunks() {
		for (int i = 0; i < activeChunks.size(); i++){
			delete activeChunks[i];
		}
	}

	Chunk* getChunk(int x, int z) {
		Vector3 chunkCoord = getChunkCoord((float)x, (float)z);
		int cx = (int)chunkCoord.x;
		int cz = (int)chunkCoord.z;
		return chunkMap[{cx, cz}];
	}

	BlockState getBlock(int x, int y, int z) {
		Chunk*	chunk = getChunk(x, z);
		if (chunk != nullptr) {
			int lx = x - chunk->getPosX();
			int lz = z - chunk->getPosZ();
			return chunk->getBlock(lx, y, lz);
		}
		return BlockState::None;
	}

	void setBlock(int x, int y, int z,BlockState block) {
		Chunk*	chunk = getChunk(x, z);
		if (chunk != nullptr) {
			int lx = x - chunk->getPosX();
			int lz = z - chunk->getPosZ();
			return chunk->setBlock(lx,y,lz,block);
		}
	}
};
 
