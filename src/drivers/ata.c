#include "ata.h"

#define STATUS_BSY 0x80
#define STATUS_RDY 0x40
#define STATUS_DRQ 0x08
#define STATUS_DF 0x20
#define STATUS_ERR 0x01

struct device_desc ATA_DEV_DESC = {LEGACY, LEG_ATA, 0};

static void ATA_wait_BSY();
static void ATA_wait_DRQ();
void read_sectors(unsigned int target_address, unsigned int LBA, unsigned char sector_count);

void* ATA_FUNC[] = {
    read_sectors
};


void read_sectors(unsigned int target_address, unsigned int LBA, unsigned char sector_count)
{
	ATA_wait_BSY();
	outb(0x1F6,0xE0 | ((LBA >>24) & 0xF));
	outb(0x1F2,sector_count);
	outb(0x1F3, (unsigned char) LBA);
	outb(0x1F4, (unsigned char)(LBA >> 8));
	outb(0x1F5, (unsigned char)(LBA >> 16));
	outb(0x1F7,0x20); //Send the read command

	unsigned short *target = (unsigned short*) target_address;

	for (int j =0;j<sector_count;j++)
	{
		ATA_wait_BSY();
		ATA_wait_DRQ();
		for(int i=0;i<256;i++)
			target[i] = inw(0x1F0);
		target+=256;

	}
}


static void ATA_wait_BSY()   //Wait for bsy to be 0
{
	while(inb(0x1F7)&STATUS_BSY);
}
static void ATA_wait_DRQ()  //Wait fot drq to be 1
{
	while(!(inb(0x1F7)&STATUS_RDY));
}

unsigned int ata_probe(void* data){
    return 1;
}
