#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define_macro_functions.h"
#include "define_macros.h"

#include "blockchain_functions.h"

#include "define_macros_test.h"
#include "variables_test.h"
#include "blockchain_functions_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: blockchain_test
Description: Test the blockchain_functions
Return: The number of passed blockchain test
-----------------------------------------------------------------------------------------------------------
*/

int blockchain_test()
{   
  // Variables

  // define macros
  #define BLOCKCHAIN_TEST 4
  #define NETWORK_BLOCK "0d0da5d5f1e005064b0a0061c007fdce72d7a6ec85175ad8837ebb978725d722f6ec97a2650dbd0000000002aa9a0c01ffb2b81201b2cce199a30202b1ae08c48f3b3e9ba6e22d9fdaf289eda8565179ebff7787883ecaf49f1ebdfba51201159a7ed6a1065b708355d900b06e4e1c47238397723f4d379945b3bcdf10f09702811200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000500000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000300000000000000000000000000000000000000000000000000000000000000040000000000000000000000000000000000000000000000000000000000000005"
  #define VARINT_ENCODED_VALUE_1 0xb2f58199a302 // random value
  #define VARINT_ENCODED_VALUE_TEXT_1 "b2f58199a302" // random value
  #define VARINT_DECODED_VALUE_1 78167177906 // random value
  #define VARINT_ENCODED_VALUE_2 0x7d // no encoding or decoding
  #define VARINT_ENCODED_VALUE_TEXT_2 "7d" // no encoding or decoding
  #define VARINT_DECODED_VALUE_2 125 // no encoding or decoding
  #define VARINT_ENCODED_VALUE_3 0x8002 // start of 1 byte length
  #define VARINT_ENCODED_VALUE_TEXT_3 "8002" // start of 1 byte length
  #define VARINT_DECODED_VALUE_3 256 // start of 1 byte length
  #define VARINT_ENCODED_VALUE_4 0xff7f // end of 1 byte length
  #define VARINT_ENCODED_VALUE_TEXT_4 "0xff7f" // end of 1 byte length
  #define VARINT_DECODED_VALUE_4 16383 // end of 1 byte length
  #define VARINT_ENCODED_VALUE_5 0x808001 // start of 2 byte length
  #define VARINT_ENCODED_VALUE_TEXT_5 "808001" // start of 2 byte length
  #define VARINT_DECODED_VALUE_5 16384 // start of 2 byte length
  #define VARINT_ENCODED_VALUE_6 0xffff7f // end of 2 byte length
  #define VARINT_ENCODED_VALUE_TEXT_6 "ffff7f" // end of 2 byte length
  #define VARINT_DECODED_VALUE_6 2097151 // end of 2 byte length
  #define VARINT_ENCODED_VALUE_7 0x80808001 // start of 3 byte length
  #define VARINT_ENCODED_VALUE_TEXT_7 "80808001" // start of 3 byte length
  #define VARINT_DECODED_VALUE_7 2097152 // start of 3 byte length
  #define VARINT_ENCODED_VALUE_8 0xffffff7f // end of 3 byte length
  #define VARINT_ENCODED_VALUE_TEXT_8 "ffffff7f" // end of 3 byte length
  #define VARINT_DECODED_VALUE_8 268435455 // end of 3 byte length
  #define VARINT_ENCODED_VALUE_9 0x8080808001 // start of 4 byte length
  #define VARINT_ENCODED_VALUE_TEXT_9 "8080808001" // start of 4 byte length
  #define VARINT_DECODED_VALUE_9 268435456 // start of 4 byte length
  #define VARINT_ENCODED_VALUE_10 0xffffffff7f // end of 4 byte length
  #define VARINT_ENCODED_VALUE_TEXT_10 "ffffffff7f" // end of 4 byte length
  #define VARINT_DECODED_VALUE_10 34359738367 // end of 4 byte length
  #define VARINT_ENCODED_VALUE_11 0x808080808001 // start of 5 byte length
  #define VARINT_ENCODED_VALUE_TEXT_11 "808080808001" // start of 5 byte length
  #define VARINT_DECODED_VALUE_11 34359738368 // start of 5 byte length
  #define VARINT_ENCODED_VALUE_12 0xffffffffff7f // end of 5 byte length
  #define VARINT_ENCODED_VALUE_TEXT_12 "ffffffffff7f" // end of 5 byte length
  #define VARINT_DECODED_VALUE_12 4398046511103 // end of 5 byte length
  #define VARINT_ENCODED_VALUE_13 0x80808080808001 // start of 6 byte length
  #define VARINT_ENCODED_VALUE_TEXT_13 "80808080808001" // start of 6 byte length
  #define VARINT_DECODED_VALUE_13 4398046511104 // start of 6 byte length
  #define VARINT_ENCODED_VALUE_14 0xffffffffffff7f // end of 6 byte length
  #define VARINT_ENCODED_VALUE_TEXT_14 "ffffffffffff7f" // end of 6 byte length
  #define VARINT_DECODED_VALUE_14 562949953421311 // end of 6 byte length
  #define VARINT_ENCODED_VALUE_15 0x8080808080808001 // start of 7 byte length
  #define VARINT_ENCODED_VALUE_TEXT_15 "8080808080808001" // start of 7 byte length
  #define VARINT_DECODED_VALUE_15 562949953421312 // start of 7 byte length
  #define VARINT_ENCODED_VALUE_16 0xffffffffffffff7f // end of 7 byte length
  #define VARINT_ENCODED_VALUE_TEXT_16 "ffffffffffffff7f" // end of 7 byte length
  #define VARINT_DECODED_VALUE_16 72057594037927935 // end of 7 byte length
  #define VARINT_ENCODED_VALUE_17 0x808080808080808001 // start of 8 byte length
  #define VARINT_ENCODED_VALUE_TEXT_17 "808080808080808001" // start of 8 byte length
  #define VARINT_DECODED_VALUE_17 72057594037927936 // start of 8 byte length
  #define VARINT_ENCODED_VALUE_18 0xffffffffffffffff7f // end of 8 byte length
  #define VARINT_ENCODED_VALUE_TEXT_18 "ffffffffffffffff7f" // end of 8 byte length
  #define VARINT_DECODED_VALUE_18 9223372036854775807 // end of 8 byte length

  // reset the variables
  memset(data_test,0,strnlen(data_test,BUFFER_SIZE));
  count_test = 0;

  // write the start test message
  color_print(TEST_OUTLINE,"blue");
  printf("\033[1;34mvarint_decode test - Total test: %d\033[0m\n",BLOCKCHAIN_TEST);
  color_print(TEST_OUTLINE,"blue");
  printf("\n");

  // run the varint_decode test
  if (varint_decode(VARINT_ENCODED_VALUE_1) == VARINT_DECODED_VALUE_1 ||
      varint_decode(VARINT_ENCODED_VALUE_2) == VARINT_DECODED_VALUE_2 ||
      varint_decode(VARINT_ENCODED_VALUE_3) == VARINT_DECODED_VALUE_3 ||
      varint_decode(VARINT_ENCODED_VALUE_4) == VARINT_DECODED_VALUE_4 ||
      varint_decode(VARINT_ENCODED_VALUE_5) == VARINT_DECODED_VALUE_5 ||
      varint_decode(VARINT_ENCODED_VALUE_6) == VARINT_DECODED_VALUE_6 ||
      varint_decode(VARINT_ENCODED_VALUE_7) == VARINT_DECODED_VALUE_7 ||
      varint_decode(VARINT_ENCODED_VALUE_8) == VARINT_DECODED_VALUE_8 ||
      varint_decode(VARINT_ENCODED_VALUE_9) == VARINT_DECODED_VALUE_9 ||
      varint_decode(VARINT_ENCODED_VALUE_10) == VARINT_DECODED_VALUE_10 ||
      varint_decode(VARINT_ENCODED_VALUE_11) == VARINT_DECODED_VALUE_11 ||
      varint_decode(VARINT_ENCODED_VALUE_12) == VARINT_DECODED_VALUE_12 ||
      varint_decode(VARINT_ENCODED_VALUE_13) == VARINT_DECODED_VALUE_13 ||
      varint_decode(VARINT_ENCODED_VALUE_14) == VARINT_DECODED_VALUE_14 ||
      varint_decode(VARINT_ENCODED_VALUE_15) == VARINT_DECODED_VALUE_15 ||
      varint_decode(VARINT_ENCODED_VALUE_16) == VARINT_DECODED_VALUE_16)
  {
    color_print("PASSED! Test for varint decode","green");
    count_test++;
  }
  else
  {
    color_print("FAILED! Test for varint decode","red");
  }

  // run the varint_encode test
  if ((varint_encode(VARINT_DECODED_VALUE_1,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_1,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_2,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_2,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_3,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_3,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_4,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_4,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_5,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_5,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_6,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_6,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_7,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_7,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_8,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_8,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_9,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_9,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_10,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_10,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_11,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_11,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_12,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_12,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_13,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_13,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_14,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_14,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_15,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_15,BUFFER_SIZE) == 0) ||
      (varint_encode(VARINT_DECODED_VALUE_16,data_test) == 1 && strncmp(data_test,VARINT_ENCODED_VALUE_TEXT_16,BUFFER_SIZE) == 0))
  {
    color_print("PASSED! Test for varint encode","green");
    count_test++;
    varint_encode(562949953421311,data_test);printf("%s\n",data_test);
    varint_encode(1020304050,data_test);printf("%s\n",data_test);
  }
  else
  {
    color_print("FAILED! Test for varint encode","red");
  }

  // run the network_block_string_to_blockchain_data test and verify the network block data
  if (network_block_string_to_blockchain_data(NETWORK_BLOCK) == 1)
  {
    // verify the blockchain_data
    if (verify_network_block_data(1,0) == 1)
    {
      color_print("PASSED! Test for converting a network_block_string to a blockchain_data struct","green");
      count_test++;
    }
    else
    {
      color_print("FAILED! Test for converting a network_block_string to a blockchain_data struct","red");
    }
  }
  else
  {
    color_print("FAILED! Test for converting a network_block_string to a blockchain_data struct","red");
  }

  // run the blockchain_data_to_network_block_string test and verify the network_block_string
  if (blockchain_data_to_network_block_string(data_test) == 1)
  {
    // verify the network_block_string
    if (strncmp(NETWORK_BLOCK,data_test,BUFFER_SIZE) == 0)
    {
      color_print("PASSED! Test for converting a blockchain_data struct to a network_block_string","green");
      count_test++;
    }
    else
    {
      color_print("FAILED! Test for converting a blockchain_data struct to a network_block_string","red");
    }
  }
  else
  {
    color_print("FAILED! Test for converting a blockchain_data struct to a network_block_string","red");
  }



  // write the end test message
  if (count_test == BLOCKCHAIN_TEST)
  {
    printf("\n");
    color_print(TEST_OUTLINE,"green");
    printf("\033[1;32mvarint_decode test - Passed test: %d, Failed test: 0\033[0m\n",BLOCKCHAIN_TEST);
    color_print(TEST_OUTLINE,"green");
    printf("\n\n");
  }
  else
  {
    printf("\n");
    color_print(TEST_OUTLINE,"red");
    printf("\033[1;31mvarint_decode test - Passed test: %d, Failed test: %d\033[0m\n",count_test,BLOCKCHAIN_TEST-count_test);
    color_print(TEST_OUTLINE,"red");
    printf("\n\n");
  } 
  return count_test;

  #undef BLOCKCHAIN_TEST
  #undef NETWORK_BLOCK
  #undef VARINT_ENCODED_VALUE_1
  #undef VARINT_ENCODED_VALUE_TEXT_1
  #undef VARINT_DECODED_VALUE_1
  #undef VARINT_ENCODED_VALUE_2
  #undef VARINT_ENCODED_VALUE_TEXT_2
  #undef VARINT_DECODED_VALUE_2
  #undef VARINT_ENCODED_VALUE_3
  #undef VARINT_ENCODED_VALUE_TEXT_3
  #undef VARINT_DECODED_VALUE_3
  #undef VARINT_ENCODED_VALUE_4
  #undef VARINT_ENCODED_VALUE_TEXT_4
  #undef VARINT_DECODED_VALUE_4
  #undef VARINT_ENCODED_VALUE_5
  #undef VARINT_ENCODED_VALUE_TEXT_5
  #undef VARINT_DECODED_VALUE_5
  #undef VARINT_ENCODED_VALUE_6
  #undef VARINT_ENCODED_VALUE_TEXT_6
  #undef VARINT_DECODED_VALUE_6
  #undef VARINT_ENCODED_VALUE_7
  #undef VARINT_ENCODED_VALUE_TEXT_7
  #undef VARINT_DECODED_VALUE_7
  #undef VARINT_ENCODED_VALUE_8
  #undef VARINT_ENCODED_VALUE_TEXT_8
  #undef VARINT_DECODED_VALUE_8
  #undef VARINT_ENCODED_VALUE_9
  #undef VARINT_ENCODED_VALUE_TEXT_9
  #undef VARINT_DECODED_VALUE_9
  #undef VARINT_ENCODED_VALUE_10
  #undef VARINT_ENCODED_VALUE_TEXT_10
  #undef VARINT_DECODED_VALUE_10
  #undef VARINT_ENCODED_VALUE_11
  #undef VARINT_ENCODED_VALUE_TEXT_11
  #undef VARINT_DECODED_VALUE_11
  #undef VARINT_ENCODED_VALUE_12
  #undef VARINT_ENCODED_VALUE_TEXT_12
  #undef VARINT_DECODED_VALUE_12
  #undef VARINT_ENCODED_VALUE_13
  #undef VARINT_ENCODED_VALUE_TEXT_13
  #undef VARINT_DECODED_VALUE_13
  #undef VARINT_ENCODED_VALUE_14
  #undef VARINT_ENCODED_VALUE_TEXT_14
  #undef VARINT_DECODED_VALUE_14
  #undef VARINT_ENCODED_VALUE_15
  #undef VARINT_ENCODED_VALUE_TEXT_15
  #undef VARINT_DECODED_VALUE_15
  #undef VARINT_ENCODED_VALUE_16
  #undef VARINT_ENCODED_VALUE_TEXT_16
  #undef VARINT_DECODED_VALUE_16
  #undef VARINT_ENCODED_VALUE_17
  #undef VARINT_ENCODED_VALUE_TEXT_17
  #undef VARINT_DECODED_VALUE_17
  #undef VARINT_ENCODED_VALUE_18
  #undef VARINT_ENCODED_VALUE_TEXT_18
  #undef VARINT_DECODED_VALUE_18
}