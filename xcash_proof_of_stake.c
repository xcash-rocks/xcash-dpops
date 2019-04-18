#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"
#include "variables.h"

#include "network_wallet_functions.h"
#include "server_functions.h"

#include "xcash_proof_of_stake_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Main function
-----------------------------------------------------------------------------------------------------------
*/

int main(int parameters_count, char* parameters[])
{
  // iniltize the random number generator
  srand(time(0));

  // Variables
  char* data = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  FILE* file;
  size_t count = 0;

  // iniltize the global variables
  xcash_wallet_public_address = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  nodes_public_address_list_received_data = (char*)calloc(BUFFER_SIZE,sizeof(char));
  server_message = (char*)calloc(BUFFER_SIZE,sizeof(char));
  current_consensus_nodes_IP_address = (char*)calloc(BUFFER_SIZE,sizeof(char));
  main_nodes_public_address = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  vrf_public_key_part_1 = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  vrf_alpha_string_part_2 = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  current_vote_results = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  vote_results_valid = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  vote_results_invalid = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  current_round_part = (char*)calloc(BUFFER_SIZE,sizeof(char)); 
  current_round_part_backup_node = (char*)calloc(BUFFER_SIZE,sizeof(char));

  // check if the memory needed was allocated on the heap successfully
  if (data == NULL || xcash_wallet_public_address == NULL || nodes_public_address_list_received_data == NULL || server_message == NULL || current_consensus_nodes_IP_address == NULL || main_nodes_public_address == NULL || vrf_public_key_part_1 == NULL || vrf_alpha_string_part_2 == NULL || current_vote_results == NULL || vote_results_valid == NULL || vote_results_invalid == NULL || current_round_part == NULL || current_round_part_backup_node == NULL)
  {
    if (data != NULL)
    {
      pointer_reset(data);
    }
    if (xcash_wallet_public_address != NULL)
    {
      pointer_reset(xcash_wallet_public_address);
    }
    if (nodes_public_address_list_received_data != NULL)
    {
      pointer_reset(nodes_public_address_list_received_data);
    }
    if (server_message != NULL)
    {
      pointer_reset(server_message);
    }
    if (current_consensus_nodes_IP_address != NULL)
    {
      pointer_reset(current_consensus_nodes_IP_address);
    }
    if (main_nodes_public_address != NULL)
    {
      pointer_reset(main_nodes_public_address);
    }
    if (vrf_public_key_part_1 != NULL)
    {
      pointer_reset(vrf_public_key_part_1);
    }
    if (vrf_alpha_string_part_2 != NULL)
    {
      pointer_reset(vrf_alpha_string_part_2);
    }
    if (current_vote_results != NULL)
    {
      pointer_reset(current_vote_results);
    }
    if (vote_results_valid != NULL)
    {
      pointer_reset(vote_results_valid);
    }
    if (vote_results_invalid != NULL)
    {
      pointer_reset(vote_results_invalid);
    }
    if (current_round_part != NULL)
    {
      pointer_reset(current_round_part);
    }
    if (current_round_part_backup_node != NULL)
    {
      pointer_reset(current_round_part_backup_node);
    }
    color_print("Could not allocate the memory needed on the heap","red");
    exit(0);
  } 

  // initialize the block_verifiers_list struct 
  for (count = 0; count < BLOCK_VERIFIERS_AMOUNT; count++)
  {
    block_verifiers_list.block_verifiers_name[count] = (char*)calloc(BLOCK_VERIFIERS_NAME_TOTAL_LENGTH+1,sizeof(char));
    block_verifiers_list.block_verifiers_public_address[count] = (char*)calloc(XCASH_WALLET_LENGTH+1,sizeof(char));
    block_verifiers_list.block_verifiers_IP_address[count] = (char*)calloc(BLOCK_VERIFIERS_IP_ADDRESS_TOTAL_LENGTH+1,sizeof(char));

    // check if the memory needed was allocated on the heap successfully
    if (block_verifiers_list.block_verifiers_name[count] == NULL || block_verifiers_list.block_verifiers_public_address[count] == NULL || block_verifiers_list.block_verifiers_IP_address[count] == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }

  // initialize the current_round_part_consensus_node_data struct
  current_round_part_consensus_node_data.vrf_public_key = (char*)calloc(BUFFER_SIZE,sizeof(char));
  current_round_part_consensus_node_data.vrf_alpha_string = (char*)calloc(BUFFER_SIZE,sizeof(char));
  current_round_part_consensus_node_data.vrf_proof = (char*)calloc(BUFFER_SIZE,sizeof(char));
  current_round_part_consensus_node_data.vrf_beta_string = (char*)calloc(BUFFER_SIZE,sizeof(char));
  current_round_part_consensus_node_data.block_blob = (char*)calloc(BUFFER_SIZE,sizeof(char));

  if (current_round_part_consensus_node_data.vrf_public_key == NULL || current_round_part_consensus_node_data.vrf_alpha_string == NULL || current_round_part_consensus_node_data.vrf_proof == NULL || current_round_part_consensus_node_data.vrf_beta_string == NULL || current_round_part_consensus_node_data.block_blob == NULL)
  {
    color_print("Could not allocate the memory needed on the heap","red");
    exit(0);
  }

  // initialize the VRF_data_block_verifiers struct 
  for (count = 0; count < BLOCK_VERIFIERS_AMOUNT; count++)
  {
    VRF_data_block_verifiers.public_address[count] = (char*)calloc(XCASH_WALLET_LENGTH+1,sizeof(char));
    VRF_data_block_verifiers.vrf_public_key_round_part_1[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_alpha_string_round_part_1[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_proof_round_part_1[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_beta_string_round_part_1[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_public_key_round_part_2[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_alpha_string_round_part_2[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_proof_round_part_2[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_beta_string_round_part_2[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_public_key_round_part_3[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_alpha_string_round_part_3[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_proof_round_part_3[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    VRF_data_block_verifiers.vrf_beta_string_round_part_3[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));

    // check if the memory needed was allocated on the heap successfully
    if (VRF_data_block_verifiers.public_address[count] == NULL || VRF_data_block_verifiers.vrf_public_key_round_part_1[count] == NULL  || VRF_data_block_verifiers.vrf_alpha_string_round_part_1[count] == NULL  || VRF_data_block_verifiers.vrf_proof_round_part_1[count] == NULL  || VRF_data_block_verifiers.vrf_beta_string_round_part_1[count] == NULL || VRF_data_block_verifiers.vrf_public_key_round_part_2[count] == NULL  || VRF_data_block_verifiers.vrf_alpha_string_round_part_2[count] == NULL  || VRF_data_block_verifiers.vrf_proof_round_part_2[count] == NULL  || VRF_data_block_verifiers.vrf_beta_string_round_part_2[count] == NULL || VRF_data_block_verifiers.vrf_public_key_round_part_3[count] == NULL  || VRF_data_block_verifiers.vrf_alpha_string_round_part_3[count] == NULL  || VRF_data_block_verifiers.vrf_proof_round_part_3[count] == NULL  || VRF_data_block_verifiers.vrf_beta_string_round_part_3[count] == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }

  // initialize the blockchain_data struct 
  blockchain_data.network_version_data = (char*)calloc(5,sizeof(char));
  blockchain_data.timestamp_data = (char*)calloc(11,sizeof(char));
  blockchain_data.previous_block_hash_data = (char*)calloc(65,sizeof(char));
  blockchain_data.nonce_data = (char*)calloc(9,sizeof(char));
  blockchain_data.block_reward_transaction_version_data = (char*)calloc(3,sizeof(char));
  blockchain_data.unlock_block_data = (char*)calloc(9,sizeof(char));
  blockchain_data.block_reward_input_data = (char*)calloc(3,sizeof(char));
  blockchain_data.vin_type_data = (char*)calloc(3,sizeof(char));
  blockchain_data.block_height_data = (char*)calloc(9,sizeof(char));
  blockchain_data.block_reward_output_data = (char*)calloc(3,sizeof(char));
  blockchain_data.block_reward_data = (char*)calloc(15,sizeof(char));
  blockchain_data.stealth_address_output_tag_data = (char*)calloc(3,sizeof(char));
  blockchain_data.stealth_address_output_data = (char*)calloc(65,sizeof(char));
  blockchain_data.extra_bytes_size_data = (char*)calloc(5,sizeof(char));
  blockchain_data.transaction_public_key_tag_data = (char*)calloc(3,sizeof(char));
  blockchain_data.transaction_public_key_data = (char*)calloc(65,sizeof(char));
  blockchain_data.extra_nonce_tag_data = (char*)calloc(3,sizeof(char));
  blockchain_data.reserve_bytes_size_data = (char*)calloc(5,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_delegates_name_data = (char*)calloc(41,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_delegates_name = (char*)calloc(21,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_public_address_data = (char*)calloc(197,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_public_address = (char*)calloc(99,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_node_backup_count_data = (char*)calloc(2,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_backup_nodes_names_data = (char*)calloc(249,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.block_producer_backup_nodes_names = (char*)calloc(125,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_delegates_name_data = (char*)calloc(41,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_delegates_name = (char*)calloc(21,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_public_address_data = (char*)calloc(197,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_public_address = (char*)calloc(99,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_node_backup_count_data = (char*)calloc(2,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_backup_nodes_names_data = (char*)calloc(249,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_backup_nodes_names = (char*)calloc(125,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_delegates_name_data = (char*)calloc(41,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_delegates_name = (char*)calloc(21,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_public_address_data = (char*)calloc(197,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_public_address = (char*)calloc(99,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_node_backup_count_data = (char*)calloc(2,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_backup_nodes_names_data = (char*)calloc(249,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_backup_nodes_names = (char*)calloc(125,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_public_key_round_part_1 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_alpha_string_round_part_1 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_proof_round_part_1 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_beta_string_round_part_1 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_public_key_round_part_2 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_alpha_string_round_part_2 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_proof_round_part_2 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_beta_string_round_part_2 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_public_key_round_part_3 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_alpha_string_round_part_3 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_proof_round_part_3 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.vrf_beta_string_round_part_3 = (char*)calloc(BUFFER_SIZE,sizeof(char));
  blockchain_data.blockchain_reserve_bytes.previous_block_hash_data = (char*)calloc(BUFFER_SIZE,sizeof(char));

  // check if the memory needed was allocated on the heap successfully
  if (blockchain_data.network_version_data == NULL || blockchain_data.timestamp_data == NULL || blockchain_data.previous_block_hash_data == NULL || blockchain_data.nonce_data == NULL || blockchain_data.block_reward_transaction_version_data == NULL || blockchain_data.unlock_block_data == NULL || blockchain_data.block_reward_input_data == NULL || blockchain_data.vin_type_data == NULL || blockchain_data.block_height_data == NULL || blockchain_data.block_reward_output_data == NULL || blockchain_data.block_reward_data == NULL || blockchain_data.stealth_address_output_tag_data == NULL || blockchain_data.stealth_address_output_data == NULL || blockchain_data.extra_bytes_size_data == NULL || blockchain_data.transaction_public_key_tag_data == NULL || blockchain_data.transaction_public_key_data == NULL || blockchain_data.extra_nonce_tag_data == NULL || blockchain_data.reserve_bytes_size_data == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_delegates_name_data == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_delegates_name == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_public_address_data == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_public_address == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_node_backup_count_data == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_backup_nodes_names_data == NULL || blockchain_data.blockchain_reserve_bytes.block_producer_backup_nodes_names == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_delegates_name_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_delegates_name == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_public_address_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_public_address == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_node_backup_count_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_backup_nodes_names_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_public_and_secret_key_backup_nodes_names == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_delegates_name_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_delegates_name == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_public_address_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_public_address == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_node_backup_count_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_backup_nodes_names_data == NULL || blockchain_data.blockchain_reserve_bytes.vrf_node_random_data_backup_nodes_names == NULL || blockchain_data.blockchain_reserve_bytes.vrf_public_key_round_part_1 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_alpha_string_round_part_1 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_proof_round_part_1 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_beta_string_round_part_1 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_public_key_round_part_2 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_alpha_string_round_part_2 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_proof_round_part_2 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_beta_string_round_part_2 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_public_key_round_part_3 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_alpha_string_round_part_3 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_proof_round_part_3 == NULL || blockchain_data.blockchain_reserve_bytes.vrf_beta_string_round_part_3 == NULL || blockchain_data.blockchain_reserve_bytes.previous_block_hash_data == NULL)
  {
    color_print("Could not allocate the memory needed on the heap","red");
    exit(0);
  }
  for (count = 0; count < BLOCK_VALIDATION_NODES_AMOUNT; count++)
  {
    blockchain_data.blockchain_reserve_bytes.block_validation_node_signature_data[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));
    blockchain_data.blockchain_reserve_bytes.block_validation_node_signature[count] = (char*)calloc(BUFFER_SIZE,sizeof(char));

    // check if the memory needed was allocated on the heap successfully
    if (blockchain_data.blockchain_reserve_bytes.block_validation_node_signature_data[count] == NULL || blockchain_data.blockchain_reserve_bytes.block_validation_node_signature[count] == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }
  blockchain_data.ringct_version_data = (char*)calloc(3,sizeof(char));
  blockchain_data.transaction_amount_data = (char*)calloc(5,sizeof(char));
  for (count = 0; count < 1000000; count++)
  {
    blockchain_data.transactions[count] = (char*)calloc(65,sizeof(char));

    // check if the memory needed was allocated on the heap successfully
    if (blockchain_data.transactions[count] == NULL)
    {
      color_print("Could not allocate the memory needed on the heap","red");
      exit(0);
    }
  }

  // set the current_round_part, current_round_part_backup_node and server message, this way the node will start at the begining of a round
  memset(current_round_part,0,strnlen(current_round_part,BUFFER_SIZE));
  memset(current_round_part_backup_node,0,strnlen(current_round_part_backup_node,BUFFER_SIZE));
  memcpy(current_round_part,"1",1);
  memcpy(current_round_part_backup_node,"0",1);
  memset(server_message,0,strnlen(server_message,BUFFER_SIZE));
  memcpy(server_message,"CONSENSUS_NODE_TO_NODES_MAIN_NODE_PUBLIC_ADDRESS|CONSENSUS_NODE_TO_MAIN_NODE_START_PART_OF_ROUND",96);

  // write the message
  color_print("X-CASH Proof Of Stake, Version 1.0.0\n","green");

  // get the wallets public address
  printf("Getting the public address\n\n");
  if (get_public_address(0) == 1)
  {  
    // print the public address
    memcpy(data,"Successfully received the public address:",41);
    memcpy(data+41,xcash_wallet_public_address,XCASH_WALLET_LENGTH);
    memcpy(data+41+XCASH_WALLET_LENGTH,"\n",1);
    color_print(data,"green");
  }
  else
  {
    color_print("Could not get the wallets public address\n","red");
    exit(0);
  }
  
  // check if the program needs to run the test
  if (parameters_count == 2)
  {
    if (strncmp(parameters[1],"--test",BUFFER_SIZE) == 0)
    {
      test();
    }
    else
    {
      color_print("Invalid parameters\n","red");
      printf(INVALID_PARAMETERS_ERROR_MESSAGE);
    }
    exit(0);
  }

  // check if the files are created and if not create them with default values
  file = fopen(NODES_UPDATED_TIME_FILE_NAME,"r");
  if (file == NULL)
  {
    file = fopen(NODES_UPDATED_TIME_FILE_NAME,"w");
    fprintf(file,"0");
    fclose(file);
  }
  else
  {    
    fclose(file);
  }

  // get the current consensus nodes IP address
  printf("Getting the current consensus nodes IP address\n\n");
  if (get_current_consensus_nodes_IP_address() == 1)
  {
    memcpy(data,"Successfully received the current consensus nodes IP address:\n",61);
    if (strncmp(current_consensus_nodes_IP_address,CONSENSUS_NODES_IP_ADDRESS,BUFFER_SIZE) == 0)
    {
      const size_t CONSENSUS_NODES_IP_ADDRESS_LENGTH = strnlen(CONSENSUS_NODES_IP_ADDRESS,BUFFER_SIZE);
      memcpy(data,"Successfully received the current consensus nodes IP address:\nConsensus nodes IP address:",90);
      memcpy(data+90,CONSENSUS_NODES_IP_ADDRESS,CONSENSUS_NODES_IP_ADDRESS_LENGTH);
      memcpy(data+90+CONSENSUS_NODES_IP_ADDRESS_LENGTH,"\n",1);      
    }
    else if (strncmp(current_consensus_nodes_IP_address,CONSENSUS_BACKUP_NODES_IP_ADDRESS,BUFFER_SIZE) == 0)
    {
      const size_t CONSENSUS_BACKUP_NODES_IP_ADDRESS_LENGTH = strnlen(CONSENSUS_BACKUP_NODES_IP_ADDRESS,BUFFER_SIZE);
      memcpy(data,"Successfully received the current consensus nodes IP address:\nConsensus backup nodes IP address:",97);
      memcpy(data+97,CONSENSUS_BACKUP_NODES_IP_ADDRESS,CONSENSUS_BACKUP_NODES_IP_ADDRESS_LENGTH);
      memcpy(data+97+CONSENSUS_BACKUP_NODES_IP_ADDRESS_LENGTH,"\n",1);      
    }
    else
    {
      color_print("Could not get the current consensus nodes IP address\n","red");
      exit(0); 
    }
    color_print(data,"green");
  }
  else
  {
    color_print("Could not get the current consensus nodes IP address\n","red");
    exit(0);    
  }
  
  // get the updated node list
  printf("Getting the updated node list\n\n");
  if (get_current_consensus_nodes_IP_address() == 0)
  {
    color_print("Could not get the updated node list\n","red");
    exit(0);    
  }

  // start the server
  for (;;)
  {
    if (create_server(1) == 0)
    {
      color_print("Could not start the server","red");
      exit(0);
    }
  }  

  return 0;   
}