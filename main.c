#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHexArray(unsigned char* a){
    for(int i = 0; i < 16; i++){
        printf("%x ",a[i]);
    }
    printf("\n");
}

unsigned char S[] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

// AES Inverse S-Box
unsigned char SI[] = {
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D };


unsigned int M[] = {
    0x02, 0x03, 0x01, 0x01,
    0x01, 0x02, 0x03, 0x01,
    0x01, 0x01, 0x02, 0x03,
    0x03, 0x01, 0x01, 0x02
};

unsigned int MI[] = {
    0x0E, 0x0B, 0x0D, 0x09,
    0x09, 0x0E, 0x0B, 0x0D,
    0x0D, 0x09, 0x0E, 0x0B,
    0x0B, 0x0D, 0x09, 0x0E
};

int hex2int(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    return -1;
}

unsigned char* sub_bytes(unsigned char* input) {
   unsigned char* output = malloc(16);
   for(int i = 0; i < 16; i++){
        output[i] = S[input[i]];
   }
   return output;
}

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

unsigned char multiply_by_2(unsigned char input){
    unsigned char output;
    output = input << 1;
    if(CHECK_BIT(input, 7)){
        output = output ^ 0x1b;
    }
    return output;
}

//seems correct
unsigned char multiply_by_3(unsigned char input){
    unsigned char output;
    output = multiply_by_2(input);
    output = output ^ input;
    return output;
}


unsigned char* mix_columns(unsigned char* a){
    unsigned char * output = malloc(16);
    for(int i = 0; i < 4; i++){
        output[0 + 4 * i] = multiply_by_2(a[0 + 4 * i]) ^ multiply_by_3(a[1 + 4 * i])^ a[2 + 4 * i] ^ a[3 + 4 * i];
        output[1 + 4 * i] = a[0 + 4 * i] ^ multiply_by_2(a[1 + 4 * i]) ^ multiply_by_3(a[2 + 4 * i]) ^ a[3 + 4 * i];
        output[2 + 4 * i] = a[0 + 4 * i] ^ a[1 + 4 * i] ^ multiply_by_2(a[2 + 4 * i]) ^ multiply_by_3(a[3 + 4 * i]);
        output[3 + 4 * i] = multiply_by_3(a[0 + 4 * i]) ^ a[1 + 4 * i] ^ a[2 + 4 * i] ^ multiply_by_2(a[3 + 4 * i]);
    }
    return output;
}

unsigned char* add_round_key(unsigned char* key, unsigned char* state){
    unsigned char* result = malloc(16);
    for(int i = 0; i < 16; i++){
        result[i] = key[i]^state[i];
    }
    return result;
}

unsigned char* shift_rows(unsigned char* state){
    unsigned char* result = malloc(16);
    //first row
    result[0] = state[0];
    result[4] = state[4];
    result[8] = state[8];
    result[12] = state[12];

    result[1] = state[5];
    result[5] = state[9];
    result[9] = state[13];
    result[13] = state[1];

    result[2] = state[10];
    result[6] = state[14];
    result[10] = state[2];
    result[14] = state[6];

    result[3] = state[15];
    result[7] = state[3];
    result[11] = state[7];
    result[15] = state[11];
    return result;
}



void schedule_core(unsigned char *in, unsigned char round) {
    unsigned char roundConstant[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36};

    // move the input 8 bits to the left
    unsigned char tmp;
    tmp = in[0];
    for(int i = 0;i < 3; i++)
        in[i] = in[i + 1];
    in[3] = tmp;

    for(int i = 0; i < 4; i++)
        in[i] = S[in[i]];

    in[0] ^= roundConstant[round];

}

unsigned char * key_expansion(unsigned char *input) {
    unsigned char * output;
    output = malloc(176);
    unsigned char last_bytes[4];

    // cursor
    unsigned char c = 16;
    unsigned char round = 0;

    for (int i = 0; i < 16; i++)
    {
        output[i] = input[i];
    }

    while(c < 176)
    {

        for(int i = 0; i < 4; i++)
        {
            last_bytes[i] = output[i + c - 4];
        }

        if(c % 16 == 0)
        {
            schedule_core(last_bytes, round++);
        }

        for(int i = 0; i < 4; i++)
        {
            output[c] = output[c - 16] ^ last_bytes[i];
            c++;
        }
    }
    return output;
}

unsigned char* aes(char* key, char* state){
    unsigned char* keys = malloc(176);
    keys = &key_expansion(key);
    state = add_round_key(keys[0], state);
    for(int i=0; i<3; i++){
        state = sub_bytes(state);
        state = shift_rows(state);
        state = mix_columns(state);
        state = add_round_key(keys[i+1], state);
    }
    state = sub_bytes(state);
    state = shift_rows(state);
    state = add_round_key(keys[4], state);
    return state;
}

void test(){
    unsigned char plaintext[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char cipher_key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char cipher_text[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};
//Round 0:
   unsigned char state00[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff}; // <-- Plaintext
   unsigned char round_key0[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f}; //
   unsigned char state01[] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0}; // <-- AddRoundKey()

//Round 1:

   unsigned char state10[] = {0x63, 0xca, 0xb7, 0x04, 0x09, 0x53, 0xd0, 0x51, 0xcd, 0x60, 0xe0, 0xe7, 0xba, 0x70, 0xe1, 0x8c}; // <-- SubBytes()
   unsigned char* lma = shift_rows(&state10);
   printHexArray(lma);
   printf("\n");
   free(lma);
   unsigned char state11[] = {0x63, 0x53, 0xe0, 0x8c, 0x09, 0x60, 0xe1, 0x04, 0xcd, 0x70, 0xb7, 0x51, 0xba, 0xca, 0xd0, 0xe7}; // <-- ShiftRows()
   printHexArray(state11);
   unsigned char state12[] = {0x5f, 0x72, 0x64, 0x15, 0x57, 0xf5, 0xbc, 0x92, 0xf7, 0xbe, 0x3b, 0x29, 0x1d, 0xb9, 0xf9, 0x1a}; // <-- MixColumns()
   unsigned char round_key1[] = {0xd6, 0xaa, 0x74, 0xfd, 0xd2, 0xaf, 0x72, 0xfa, 0xda, 0xa6, 0x78, 0xf1, 0xd6, 0xab, 0x76, 0xfe}; //
   unsigned char state13[] = {0x89, 0xd8, 0x10, 0xe8, 0x85, 0x5a, 0xce, 0x68, 0x2d, 0x18, 0x43, 0xd8, 0xcb, 0x12, 0x8f, 0xe4}; // <-- AddRoundKey()

//Round 2:
   unsigned char state20[] = {0xa7, 0x61, 0xca, 0x9b, 0x97, 0xbe, 0x8b, 0x45, 0xd8, 0xad, 0x1a, 0x61, 0x1f, 0xc9, 0x73, 0x69}; // <-- SubBytes()
   unsigned char state21[] = {0xa7, 0xbe, 0x1a, 0x69, 0x97, 0xad, 0x73, 0x9b, 0xd8, 0xc9, 0xca, 0x45, 0x1f, 0x61, 0x8b, 0x61}; // <-- ShiftRows()
   unsigned char state22[] = {0xff, 0x87, 0x96, 0x84, 0x31, 0xd8, 0x6a, 0x51, 0x64, 0x51, 0x51, 0xfa, 0x77, 0x3a, 0xd0, 0x09}; // <-- MixColumns()
   unsigned char round_key2[] = {0xb6, 0x92, 0xcf, 0x0b, 0x64, 0x3d, 0xbd, 0xf1, 0xbe, 0x9b, 0xc5, 0x00, 0x68, 0x30, 0xb3, 0xfe}; //
   unsigned char state23[] = {0x49, 0x15, 0x59, 0x8f, 0x55, 0xe5, 0xd7, 0xa0, 0xda, 0xca, 0x94, 0xfa, 0x1f, 0x0a, 0x63, 0xf7}; // <-- AddRoundKey()
}

void key_expansion_test()
{
//    K00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//    K01: 62 63 63 63 62 63 63 63 62 63 63 63 62 63 63 63
//    K02: 9b 98 98 c9 f9 fb fb aa 9b 98 98 c9 f9 fb fb aa
//    K03: 90 97 34 50 69 6c cf fa f2 f4 57 33 0b 0f ac 99
//    K04: ee 06 da 7b 87 6a 15 81 75 9e 42 b2 7e 91 ee 2b
//    K05: 7f 2e 2b 88 f8 44 3e 09 8d da 7c bb f3 4b 92 90
//    K06: ec 61 4b 85 14 25 75 8c 99 ff 09 37 6a b4 9b a7
//    K07: 21 75 17 87 35 50 62 0b ac af 6b 3c c6 1b f0 9b
//    K08: 0e f9 03 33 3b a9 61 38 97 06 0a 04 51 1d fa 9f
//    K09: b1 d4 d8 e2 8a 7d b9 da 1d 7b b3 de 4c 66 49 41
//    K10: b4 ef 5b cb 3e 92 e2 11 23 e9 51 cf 6f 8f 18 8e
//
//
//    K00: 10 a5 88 69 d7 4b e5 a3 74 cf 86 7c fb 47 38 59
//    K01: b1 a2 43 66 66 e9 a6 c5 12 26 20 b9 e9 61 18 e0
//    K02: 5c 0f a2 78 3a e6 04 bd 28 c0 24 04 c1 a1 3c e4
//    K03: 6a e4 cb 00 50 02 cf bd 78 c2 eb b9 b9 63 d7 5d
//    K04: 99 ea 87 56 c9 e8 48 eb b1 2a a3 52 08 49 74 0f
//    K05: b2 78 f1 66 7b 90 b9 8d ca ba 1a df c2 f3 6e d0
//    K06: 9f e7 81 43 e4 77 38 ce 2e cd 22 11 ec 3e 4c c1
//    K07: 6d ce f9 8d 89 b9 c1 43 a7 74 e3 52 4b 4a af 93
//    K08: 3b b7 25 3e b2 0e e4 7d 15 7a 07 2f 5e 30 a8 bc
//    K09: 24 75 40 66 96 7b a4 1b 83 01 a3 34 dd 31 0b 88
//    K10: d5 5e 84 a7 43 25 20 bc c0 24 83 88 1d 15 88 00

    unsigned char K00[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    unsigned char K01[] = {0x62, 0x63, 0x63, 0x63, 0x62, 0x63, 0x63, 0x63, 0x62, 0x63, 0x63, 0x63, 0x62, 0x63, 0x63, 0x63};
    unsigned char K02[] = {0x9b, 0x98, 0x98, 0xc9, 0xf9, 0xfb, 0xfb, 0xaa, 0x9b, 0x98, 0x98, 0xc9, 0xf9, 0xfb, 0xfb, 0xaa};
    unsigned char K03[] = {0x90, 0x97, 0x34, 0x50, 0x69, 0x6c, 0xcf, 0xfa, 0xf2, 0xf4, 0x57, 0x33, 0x0b, 0x0f, 0xac, 0x99};
    unsigned char K04[] = {0xee, 0x06, 0xda, 0x7b, 0x87, 0x6a, 0x15, 0x81, 0x75, 0x9e, 0x42, 0xb2, 0x7e, 0x91, 0xee, 0x2b};
    unsigned char K05[] = {0x7f, 0x2e, 0x2b, 0x88, 0xf8, 0x44, 0x3e, 0x09, 0x8d, 0xda, 0x7c, 0xbb, 0xf3, 0x4b, 0x92, 0x90};
    unsigned char K06[] = {0xec, 0x61, 0x4b, 0x85, 0x14, 0x25, 0x75, 0x8c, 0x99, 0xff, 0x09, 0x37, 0x6a, 0xb4, 0x9b, 0xa7};
    unsigned char K07[] = {0x21, 0x75, 0x17, 0x87, 0x35, 0x50, 0x62, 0x0b, 0xac, 0xaf, 0x6b, 0x3c, 0xc6, 0x1b, 0xf0, 0x9b};
    unsigned char K08[] = {0x0e, 0xf9, 0x03, 0x33, 0x3b, 0xa9, 0x61, 0x38, 0x97, 0x06, 0x0a, 0x04, 0x51, 0x1d, 0xfa, 0x9f};
    unsigned char K09[] = {0xb1, 0xd4, 0xd8, 0xe2, 0x8a, 0x7d, 0xb9, 0xda, 0x1d, 0x7b, 0xb3, 0xde, 0x4c, 0x66, 0x49, 0x41};
    unsigned char K10[] = {0xb4, 0xef, 0x5b, 0xcb, 0x3e, 0x92, 0xe2, 0x11, 0x23, 0xe9, 0x51, 0xcf, 0x6f, 0x8f, 0x18, 0x8e};


    unsigned char K00snd[] = {0x10, 0xa5, 0x88, 0x69, 0xd7, 0x4b, 0xe5, 0xa3, 0x74, 0xcf, 0x86, 0x7c, 0xfb, 0x47, 0x38, 0x59};
    unsigned char K01snd[] = {0xb1, 0xa2, 0x43, 0x66, 0x66, 0xe9, 0xa6, 0xc5, 0x12, 0x26, 0x20, 0xb9, 0xe9, 0x61, 0x18, 0xe0};
    unsigned char K02snd[] = {0x5c, 0x0f, 0xa2, 0x78, 0x3a, 0xe6, 0x04, 0xbd, 0x28, 0xc0, 0x24, 0x04, 0xc1, 0xa1, 0x3c, 0xe4};
    unsigned char K03snd[] = {0x6a, 0xe4, 0xcb, 0x00, 0x50, 0x02, 0xcf, 0xbd, 0x78, 0xc2, 0xeb, 0xb9, 0xb9, 0x63, 0xd7, 0x5d};
    unsigned char K04snd[] = {0x99, 0xea, 0x87, 0x56, 0xc9, 0xe8, 0x48, 0xeb, 0xb1, 0x2a, 0xa3, 0x52, 0x08, 0x49, 0x74, 0x0f};
    unsigned char K05snd[] = {0xb2, 0x78, 0xf1, 0x66, 0x7b, 0x90, 0xb9, 0x8d, 0xca, 0xba, 0x1a, 0xdf, 0xc2, 0xf3, 0x6e, 0xd0};
    unsigned char K06snd[] = {0x9f, 0xe7, 0x81, 0x43, 0xe4, 0x77, 0x38, 0xce, 0x2e, 0xcd, 0x22, 0x11, 0xec, 0x3e, 0x4c, 0xc1};
    unsigned char K07snd[] = {0x6d, 0xce, 0xf9, 0x8d, 0x89, 0xb9, 0xc1, 0x43, 0xa7, 0x74, 0xe3, 0x52, 0x4b, 0x4a, 0xaf, 0x93};
    unsigned char K08snd[] = {0x3b, 0xb7, 0x25, 0x3e, 0xb2, 0x0e, 0xe4, 0x7d, 0x15, 0x7a, 0x07, 0x2f, 0x5e, 0x30, 0xa8, 0xbc};
    unsigned char K09snd[] = {0x24, 0x75, 0x40, 0x66, 0x96, 0x7b, 0xa4, 0x1b, 0x83, 0x01, 0xa3, 0x34, 0xdd, 0x31, 0x0b, 0x88};
    unsigned char K10snd[] = {0xd5, 0x5e, 0x84, 0xa7, 0x43, 0x25, 0x20, 0xbc, 0xc0, 0x24, 0x83, 0x88, 0x1d, 0x15, 0x88, 0x00};


    unsigned char * exp_key = key_expansion(K00);

//    printHexArray(k[0]);
    printHexArray(exp_key);
    printHexArray(exp_key+16);
    printHexArray(exp_key+32);
    printHexArray(exp_key+160);


}

int main()
{
    char plaintext[] = {0x00, 0x11,0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    aes(&plaintext, &key);
//    sub_bytes(plaintext);
//    test();
    // key_expansion(key);
    //c har* state = add_round_key(key,plaintext);


    key_expansion_test();


    return 0;
}
