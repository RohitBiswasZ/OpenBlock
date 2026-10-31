#include "World.h"
World::World(int width, int depth) {
	for (int x = 0; x < width; x++){
		for (int z = 0; z < depth; z++) {
			Chunk* chunk = new Chunk(x * Chunk::WIDTH, z * Chunk::DEPTH, BlockState::Stone);
			activeChunks.push_back(chunk);
			chunkMap[{x * Chunk::WIDTH, z * Chunk::DEPTH}] = chunk;
		}
	}
}

void World::constructAllChunks() {
	for (int i = 0; i < activeChunks.size(); i++) {
		activeChunks[i]->construct();
	}
}

void World::renderAllChunks() {
	for (int i = 0; i < activeChunks.size(); i++) {
		activeChunks[i]->render();
	}
}

