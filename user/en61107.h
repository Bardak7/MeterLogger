#include <stdint.h>
#include <stdbool.h>

#define EN61107_FRAME_L         1024

typedef struct {
    int16_t rid;
    uint8_t unit;
    uint8_t length;
    uint8_t si_ex;
    int32_t value;
} en61107_response_register_t;

typedef en61107_response_register_t en61107_response_register_list_t[8];   // max 8 registers per request

typedef struct {
    unsigned int en61107_response_serial;
    unsigned int en61107_response_meter_type;
    unsigned int en61107_response_sw_revision;
    en61107_response_register_list_t en61107_response_register_list;
} en61107_response_t;

ICACHE_FLASH_ATTR
unsigned int en61107_get_type(unsigned char *frame);

ICACHE_FLASH_ATTR
unsigned int en61107_get_serial(unsigned char *frame);

ICACHE_FLASH_ATTR
unsigned int en61107_set_clock(unsigned char *frame, uint64_t unix_time);

ICACHE_FLASH_ATTR
unsigned int en61107_get_register(unsigned char *frame, uint16_t *register_list, uint16_t register_list_length);

ICACHE_FLASH_ATTR
int en61107_decode_frame(unsigned char *frame, unsigned char frame_length, en61107_response_t *response);