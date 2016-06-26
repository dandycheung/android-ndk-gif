
#include <stdio.h>
#include <stdint.h>
#include "IGifEncoder.h"
#include "LCTGifEncoder.h"
#include "SimpleGCTEncoder.h"
#include "GifEncoder.h"
#include "BitWritingBlock.h"
#include <vector>

using namespace std;

GifEncoder::GifEncoder(EncodingType encodingType)
{
	switch (encodingType)
	{
	case ENCODING_TYPE_SIMPLE_FAST:
		gifEncoder = new SimpleGCTGifEncoder();
		break;
	case ENCODING_TYPE_NORMAL_LOW_MEMORY:
	default:
		gifEncoder = new LCTGifEncoder();
		break;
	}
}

bool GifEncoder::init(uint16_t width, uint16_t height, const char* fileName)
{
	return gifEncoder->init(width, height, fileName);
}

void GifEncoder::release()
{
	gifEncoder->release();
}

void GifEncoder::setDither(bool useDither) {
	gifEncoder->setDither(useDither);
}

uint16_t GifEncoder::getWidth()
{
	return gifEncoder->getWidth();
}

uint16_t GifEncoder::getHeight()
{
	return gifEncoder->getHeight();
}

void GifEncoder::encodeFrame(uint32_t* pixels, int delayMs)
{
	gifEncoder->encodeFrame(pixels, delayMs);
}
