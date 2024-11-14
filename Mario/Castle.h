#pragma once
#include "Print.h"

class Castle
{
private:
	Print _print;

#pragma region 도트
	int castleFlag[16][16] =
	{
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,14,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,14,14,14,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,14,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20, 4,15,15,15,15,15,15,15,15,15,15,15,20,20},
		{20,20, 4,15,15,15,15,15,15,15,15,15,15,15,20,20},
		{20,20, 4,15,15,15,15,15, 4,15,15,15,15,15,20,20},
		{20,20, 4,15,15,15,15,15, 4,15,15,15,15,15,20,20},
		{20,20, 4,15,15, 4, 4, 4, 4, 4, 4, 4,15,15,20,20},
		{20,20, 4,15,15,15, 4, 4, 4, 4, 4,15,15,15,20,20},
		{20,20, 4,15,15,15,15, 4, 4, 4,15,15,15,15,20,20},
		{20,20, 4,15,15,15, 4, 4,15, 4, 4,15,15,15,20,20},
		{20,20, 4,15,15,15, 4,15,15,15, 4,15,15,15,20,20},
		{20,20, 4,15,15,15,15,15,15,15,15,15,15,15,20,20},
		{20,20, 4,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20, 4,20,20,20,20,20,20,20,20,20,20,20,20,20}
	};

	int castle[80][80] =
	{
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,13,13,13,13,20,20,20,20,20,20,20,20,13,13,13,13,13,13,13,13,20,20,20,20,20,20,20,20,13,13,13,13,13,13,13,13,20,20,20,20,20,20,20,20,13,13,13,13,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20},
		{13,13,13,13,20,20,20,20,20,20,20,20,13,13,13,13,13,13,13,13, 5, 5, 5, 0, 5, 5, 5, 5,13,13,13,13,13,13,13,13, 5, 5, 5, 0, 5, 5, 5, 5,13,13,13,13,13,13,13,13, 5, 5, 5, 0, 5, 5, 5, 5,13,13,13,13,13,13,13,13,20,20,20,20,20,20,20,20,13,13,13,13},
		{ 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 0, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 0, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 0, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5},
		{ 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 0, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 0, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 0, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5},
		{ 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13, 0, 0, 0, 0, 0, 0, 0, 0,13, 5, 5, 5, 5, 5, 5,13, 0, 0, 0, 0, 0, 0, 0, 0,13, 5, 5, 5, 5, 5, 5,13, 0, 0, 0, 0, 0, 0, 0, 0,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5},
		{ 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5},
		{ 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5},
		{ 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5, 5, 5,13, 5, 5, 5, 5, 5, 5,13,20,20,20,20,20,20,20,20,13, 5, 5, 5},
		{ 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0, 5, 5, 5,13,13,13,13,13,13,13,13,13,13, 0, 0, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
#pragma endregion

public:
	// 도트 출력
	void DrawCastle(short startpPosX, short cutArr);
	void DrawCastleFlag(short posy);

	Castle();
	~Castle();
};

