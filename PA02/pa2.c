/*
This project uses Huffman encoding and decoding and checks whether compressed 
files are compressed efficiently using the Huffman algorithm or not
*/

/*
There are 6 parameters going into the main function

argv[1]: Name of the input file that is going to be decoded

    long integer: total number of bytes in compressed file
    long integer: total number of bytes storing the topology of the Huffman coding tree
    long integer: total number of bytes in the original un compressed file

    topology of huffman tree

    encoded file

argv[2]: Name of output file
    This is where you will save the topography of the Huffman tree of argv[1]

argv[3]: Name of output file2
    This is where you store the decoded file of argv[1]
    Should be a replica of the original file

argv[4]: Name of output file3
    This file should contain the frequencies of occurences of all 256 ASCII characters of the decoded file
    Size should be: 256*sizeof(long)
    Save frequencies as long
        Can count from argv[3] or while decoding argv[1]

argv[5]: Name of output file4
    This file should contain the topology information of the constructed Huffman coding tree
*/


#include "huffman.h"
/*
For now we shall only encode and decode
*/
int main(int argc, char ** argv)
{
    compress(argv[1], argv[2]);
    //decode(argv[2], argv[3]);
    return 0;
}