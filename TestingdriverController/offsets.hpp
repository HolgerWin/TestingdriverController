#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <string>
#include <vector>


//"ac_client.exe" + 0x18AC00 = PlaterEnt
//"ac_client.exe" + 0x17E0A8 = player/gun
// player/gun + 0x140 = holster ammo
// player/gun + 0x11c = reserve ammo
//player/gun + 0xEC = health

#ifndef LOCALPLAYERADDR 
#define LOCALPLAYERADDR 0x58AC00
#endif

struct Vector2 {
	float x, y;
};

struct Vector3 {
	float x, y, z;

	Vector3 Delta(Vector3 Vec) {
		Vector3 Result;
		Result.x = Vec.x - x;
		Result.y = Vec.y - y;
		Result.z = Vec.z - z;
		return Result;
	}
	float Dist(Vector3 Coords) {
		Vector3 DeltaCoords = Delta(Coords);
		return sqrtf(DeltaCoords.x * DeltaCoords.x + DeltaCoords.y * DeltaCoords.y + DeltaCoords.z * DeltaCoords.z);
	}
};

struct Vector4 {
	float x, y, z, w;
};

struct Matrix4x4 {
	Vector4 a, b, c, d;
};


class PlayerEnt
{
public:
	char pad_0000[4]; //0x0000
	Vector3 Coords; //0x0004
	char pad_0010[36]; //0x0010
	Vector2 Viewangles; //0x0034
	char pad_003C[176]; //0x003C
	int32_t Health; //0x00EC
	char pad_00F0[212]; //0x00F0
	int32_t PlayerIndex; //0x01C4
	char pad_01C8[61]; //0x01C8
	char Name[16]; //0x0205
	char pad_0215[549]; //0x0215
}; //Size: 0x043A

template<class Type>
class Vector
{
public:
	void* List; //0x0000
	char pad_0004[4]; //0x0004
	uint32_t ListSize; //0x0008
}; //Size: 0x0018
