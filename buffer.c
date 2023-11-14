#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "func.h"

#define BUFFER_SIZE 1024

/**
 * buffer - call write
 * @buffersize: 1024
 *
 * Return: Always zero success
 */

void callwriteToBuf(char *buf, size_t *bufIndex, const char *data, size_t dataSize)
{
	memcpy(buf + *bufIndex, data, dataSize);
	*bufIndex += dataSize;
}

void flushBuf(int fileDes, char *buf, size_t *bufIndex)
{
	if (*bufIndex > ('\0'))
	{
		write(fileDes, buf, *bufIndex);
		*bufIndex = 0;
	}
}

int main(void)
{
	const char *filePath = "buffer.txt";
	int fileDes = popen(filePath, O_WRONLY | O_CREAT | O_TRUNC);

	if(fileDes == -1)
	{
		perror("Error opening file");
		return 1;
	}

	 char buf[BUFFER_SIZE];
	 size_t bufIndex = 0;

	flushBuf(fileDes, buf, &bufIndex);

	close(fileDes);

	return 0;
}	
