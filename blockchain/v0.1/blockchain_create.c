#include "blockchain.h"
/**
 * block_create - creates a new block
 * @prev: previous block
 * @data: data for a new block
 * @data_len: length of @data
 * Return: a block or NULL if failed
 */
blockchain_t *blockchain_create(void)
{
block_t const _genesis = GENESIS_BLOCK;

blockchain_t *blockchain;
block_t *ptr;
ptr = (block_t *) malloc(sizeof(block_t));
memcpy(ptr, (block_t *) &_genesis, sizeof(block_t));
blockchain = (blockchain_t *) malloc(sizeof(blockchain_t));
blockchain->chain = llist_create(MT_SUPPORT_TRUE);
if (llist_add_node(blockchain->chain, ptr, ADD_NODE_FRONT) != 0)
return (NULL);
return (blockchain);
}
