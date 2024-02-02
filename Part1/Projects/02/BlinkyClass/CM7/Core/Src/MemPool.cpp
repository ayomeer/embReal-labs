
// origin: https://github.com/green-anger/MemoryPool/tree/master
/*
 * MemPool.cpp - Fixed Size Memory Pool (both pool, and block size fixed)
 *
 *  Created on: Oct 16, 2023
 *      Author: ayome
 */
/*
#include "MemPool.h"

template<typename T, size_t NumCells>
MemPool<T, NumCells>::MemPool()
{
	static_assert( sizeof( uint32_t ) <= sizeof( T ), "sizeof( T ) must be equal or greater than sizeof( uint32_t )" );
}

template<typename T, size_t NumCells>
MemPool<T, NumCells>::~MemPool()
{}

template<typename T, size_t NumCells>
void MemPool<T, NumCells>::CreatePool( uint32_t num_cells )
{
    num_cells_ = num_cells;
    num_free_cells_ = num_cells_;
    mem_beg_ = &mempool_buffer[0];
    next_ = mem_beg_;
}


template<typename T, size_t NumCells>
void MemPool<T, NumCells>::DestroyPool()
{
    mem_beg_ = nullptr;
}


template<typename T, size_t NumCells>
T* MemPool<T, NumCells>::Allocate()
{
	if ( num_init_ < num_cells_ )
	{
		uint32_t* p = reinterpret_cast<uint32_t*>( AddrFromIndex( num_init_ ) );
		*p = ++num_init_;
	}

	T* res = nullptr;
	if ( num_free_cells_ > 0 )
	{
		res = reinterpret_cast<T*>( next_ );
		if ( --num_free_cells_ > 0 )
		{
			next_ = AddrFromIndex( *reinterpret_cast<uint32_t*>( next_ ) );
		}
		else
		{
			next_ = nullptr;
		}
	}
	return res;
}

template<typename T, size_t NumCells>
void MemPool<T, NumCells>::Deallocate( void* p )
{
	*static_cast<uint32_t*>( p ) = next_ == nullptr ? num_cells_ :
	IndexFromAddr( next_ );
	next_ = static_cast<uint8_t*>( p );
	++num_free_cells_;
}

template<typename T, size_t NumCells>
uint8_t* MemPool<T,NumCells>::AddrFromIndex( uint32_t i ) const
{
	return mem_beg_ + ( i * cell_size_ );
}

template<typename T, size_t NumCells>
uint32_t MemPool<T, NumCells>::IndexFromAddr( const uint8_t* p ) const
{
	return static_cast<uint32_t>( p - mem_beg_ ) / cell_size_;
}
*/
