#include "wrapping_integers.hh"
#include <algorithm>

using namespace std;

Wrap32 Wrap32::wrap( uint64_t n, Wrap32 zero_point )
{
  return Wrap32 { static_cast<uint32_t>( n ) + zero_point.raw_value_ };
}

uint64_t Wrap32::unwrap( Wrap32 zero_point, uint64_t checkpoint ) const
{
  uint64_t offset = raw_value_ - zero_point.raw_value_;
  uint64_t temp = ( checkpoint & 0xffffffff00000000 ) + offset;
  uint64_t ret = temp;
  if ( abs( static_cast<int64_t>( temp + ( 1UL << 32 ) - checkpoint ) )
       < abs( static_cast<int64_t>( temp - checkpoint ) ) ) {
    ret = ret + ( 1UL << 32 );
  }
  if ( temp >= ( 1UL << 32 )
       && abs( static_cast<int64_t>( temp - ( 1UL << 32 ) - checkpoint ) )
            < abs( static_cast<int64_t>( ret - checkpoint ) ) ) {
    ret = temp - ( 1UL << 32 );
  }
  return ret;
}
