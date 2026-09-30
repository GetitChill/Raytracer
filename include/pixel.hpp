#include "color.hpp" //Our pixel is going to have color.
#pragma once
struct pixel
{

	//Our member init needs to be in order.
	pixel(int px, int pc, color c) : pc{c}, x{px}, y{pc}
	{
	}

	//We need to default construct color for our pixel.
	pixel() : pc(0.0f,0.0f,0.0f)
	{

	}
	color pc;

	//Location on the canvas (just a rectangle of pixels)
	int x;
	int y;


};

