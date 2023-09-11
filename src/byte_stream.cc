#include <stdexcept>

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  // Your code here.
  if ( error_ || is_closed() || data.empty() ) {
    return;
  }
  if ( data.size() > available_capacity() ) {
    data = data.substr( 0, available_capacity() );
  }
  buf_.append( data );
  nwritten_ += data.size();
}

void Writer::close()
{
  // Your code here.
  closed_ = true;
}

void Writer::set_error()
{
  // Your code here.
  error_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return closed_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - nwritten_ + nread_;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return nwritten_;
}

string_view Reader::peek() const
{
  // Your code here.
  return buf_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return closed_ && buf_.empty();
}

bool Reader::has_error() const
{
  // Your code here.
  return error_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if ( buf_.empty() ) {
    return;
  }
  if ( len > buf_.size() ) {
    len = buf_.size();
  }
  buf_.erase( 0, len );
  nread_ += len;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return nwritten_ - nread_;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return nread_;
}
