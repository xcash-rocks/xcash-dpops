#ifndef BLOCK_VERIFIERS_SYNCHRONIZE_CHECK_FUNCTIONS_H_   /* Include guard */
#define BLOCK_VERIFIERS_SYNCHRONIZE_CHECK_FUNCTIONS_H_

/*
-----------------------------------------------------------------------------------------------------------
Function prototypes
-----------------------------------------------------------------------------------------------------------
*/

int sync_check_previous_blocks_reserve_bytes(void);
int check_if_databases_are_synced(const int SETTINGS, const int reserve_bytes_start_settings);
int sync_check_reserve_proofs_database(int settings);
void sync_check_majority_reserve_proofs_database(void);
int sync_check_reserve_bytes_database(int settings, const int reserve_bytes_start_settings);
void sync_check_majority_reserve_bytes_database(const int reserve_bytes_start_settings);
int sync_check_delegates_database(int settings);
void sync_check_majority_delegates_database(void);
int sync_check_statistics_database(int settings);
void sync_check_majority_statistics_database(void);
#endif