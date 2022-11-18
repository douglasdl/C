#include <iostream>
#include <vector>

std::vector<uint16_t> crc16_table;

uint16_t generateCRC(std::vector<uint8_t> buffer) {
	uint16_t crc = 0xffff;
	size_t size = buffer.size();
	if (size == 0) {
		return false;
	}
    for (size_t i = 0; i < size; i++) {
        crc = crc16_table[(crc ^ buffer[i]) & 0xFF] ^ (crc >> 8);
    }
	return crc;
}

std::vector<uint8_t> addCRC(std::vector<uint8_t> buffer) {
    uint16_t crc = generateCRC(buffer);
    buffer.push_back(crc % 0x100);
    buffer.push_back(crc / 0x100);
    return buffer;
}

int main() {
    
    for (uint16_t i = 0; i < 256; i++) {
		uint16_t c = i;
		for (int j = 0; j < 8; j++) {
			c = (c & 1) ? (0xA001 ^ (c >> 1)) : (c >> 1);
		}
		crc16_table.emplace_back(c);
	}
    std::vector<uint8_t> vec = {
        0x32,
        0x03,
        0x02,
        0x02,
        0x1c
    };
    uint16_t crc = generateCRC(vec);
    uint16_t result = generateCRC(addCRC(vec));
    printf("0x%04x\n", crc);
    printf("%x\n", result);
    return 0;
}
