#include<REGX52.H>
#include<intrins.h> 
#define TRUE 1
#define dataPort P0
#define ledConPort P2
unsigned char code ch[8]={0x76,0x79,0x38,0x38,0x3f,0x40,0x6f,0x4f};

void time(unsigned int ucMs);
void main(void)
{
	unsigned char i,counter=0;
	for(i=0;i<30;i++){
		for(counter=0;counter<8;counter++)
		{
			ledConPort=counter;
			dataPort=0xff;
			time(5);
		}
	}
	ledConPort=0xff;time(2000);
	while(TRUE)
	{
		for(counter=0;counter<8;counter++)
		{
			ledConPort=counter;
			dataPort=ch[counter];
			time(5);
		}
	}
}

void time(unsigned int ucMs)
{
	#define DELAYTIMES 239
	unsigned char ucCounter;
	while (ucMs!=0){
		for(ucCounter=0;ucCounter<DELAYTIMES;ucCounter++){}
		ucMs--;
	}
}





