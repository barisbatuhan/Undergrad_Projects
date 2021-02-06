#include "Encoder.h"
#include "Decoder.h"

int main()
{
	Encoder compressor;
	compressor.encode();
	
	Decoder decompressor;
	decompressor.decode();

	return 0;
}