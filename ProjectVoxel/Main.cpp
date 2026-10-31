#include "raylib.h"
#include <iostream>
#include "BlockMeshConfigs.h"
#include <vector>
#include "raymath.h"
#include "Chunk.h"
#include "World.h"
using namespace std;

Camera3D cam = { 0,2,-2 };


//void breakBlock(float step, int dist) {
//	Vector3 forward = Vector3Normalize(Vector3Subtract(cam.target, cam.position));
//	for (float i = 0; i < dist; i += step) {
//		Vector3 floating_blockPos = forward * i + cam.position;
//		int bx = (int)std::floor(floating_blockPos.x);
//		int by = (int)std::floor(floating_blockPos.y);
//		int bz = (int)std::floor(floating_blockPos.z);
//		if (world.getBlock(bx, by, bz) == BlockState::Stone) {
//			Chunk* chunk = world.getChunk(bx, bz);
//			world.setBlock(bx, by, bz, BlockState::None);
//			if (chunk != nullptr) {
//				chunk->construct();
//			}
//			break;
//		}
//
//
//	}
//}

Vector3 getChunkCoord(float x, float z) {
	float cx = std::floor(x / (float)Chunk::WIDTH) * Chunk::WIDTH;
	float cz = std::floor(z / (float)Chunk::DEPTH) * Chunk::DEPTH;

	return Vector3{ cx,0,cz };
}


int main() {
	InitWindow(1000, 600, "Window");
	SetTargetFPS(100);

	
	cam.fovy = 70;
	cam.target = { 0,0,0 };
	cam.projection = CAMERA_PERSPECTIVE;
	cam.up = { 0,1,0 };

	Color skyColor = { 70, 127, 219 ,255 };
	DisableCursor();

	Material mat = LoadMaterialDefault();
	Matrix matrix = MatrixIdentity();

	World world = { 1,1 };
	world.constructAllChunks();

	while (!WindowShouldClose()) {
		UpdateCamera(&cam, CAMERA_FREE);
		/*if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			breakBlock(0.05f,20);
		}*/
		BeginDrawing();
		ClearBackground(BLANK);
		BeginMode3D(cam);
		DrawGrid(16, 16);
		DrawLine3D(Vector3{ 0,0,0 }, Vector3{ 0,1,0 },GREEN);
		DrawLine3D(Vector3{ 0,0,0 }, Vector3{ 0,0.001,1 }, SKYBLUE);
		DrawLine3D(Vector3{ 0,0,0 }, Vector3{ 1,0.001,0 },  RED);
		Vector3 chunkCoord = getChunkCoord(cam.position.x, cam.position.z);
		cout << "chunk pos X: " << chunkCoord.x << endl;
		cout << "chunk pos Y: " << chunkCoord.y << endl;
		cout << "chunk pos Z: " << chunkCoord.z << endl;

		world.renderAllChunks();
		EndMode3D();
		EndDrawing();
	}
	CloseWindow();
	world.deleteAllChunks();
	return 0;
}

