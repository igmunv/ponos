#pragma once

#include "../libs/device.h"

struct device_desc ATA_DEV_DESC;
void* ATA_FUNC[];
unsigned int ata_probe(void* data);
