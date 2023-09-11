#include <cstddef>
#include <cstdint>

class Timer
{
private:
  uint64_t initial_RTO_ms_;
  uint64_t curr_RTO_ms;
  size_t time_ms_ { 0 };
  bool running_ { false };

public:
  explicit Timer( uint64_t init_RTO ) : initial_RTO_ms_( init_RTO ), curr_RTO_ms( init_RTO ) {}

  void start()
  {
    running_ = true;
    time_ms_ = 0;
  }

  void stop() { running_ = false; }

  bool is_running() const { return running_; }

  bool is_expired() const { return running_ && ( time_ms_ >= curr_RTO_ms ); }

  void tick( size_t const ms_since_last_tick )
  {
    if ( running_ ) {
      time_ms_ += ms_since_last_tick;
    }
  }

  void double_RTO() { curr_RTO_ms *= 2; }

  void reset_RTO() { curr_RTO_ms = initial_RTO_ms_; }
};
