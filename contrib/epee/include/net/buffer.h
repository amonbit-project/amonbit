
#pragma once

#include <vector>
#include "misc_log_ex.h"
#include "span.h"

#undef MONERO_DEFAULT_LOG_CATEGORY
#define MONERO_DEFAULT_LOG_CATEGORY "net.buffer"

//#define NET_BUFFER_LOG(x) MDEBUG(x)
#define NET_BUFFER_LOG(x) ((void)0)

namespace epee
{
namespace net_utils
{
class buffer
{
public:
  buffer(size_t reserve = 0): offset(0) { storage.reserve(reserve); }

  void append(const void *data, size_t sz);
  void erase(size_t sz) { NET_BUFFER_LOG("erasing " << sz << "/" << size()); CHECK_AND_ASSERT_THROW_MES(offset + sz <= storage.size(), "erase: sz too large"); offset += sz; if (offset == storage.size()) { storage.resize(0); offset = 0; } }
  epee::span<const uint8_t> span(size_t sz) const { CHECK_AND_ASSERT_THROW_MES(sz <= size(), "span is too large"); return epee::span<const uint8_t>(storage.data() + offset, sz); }
  // carve must keep the data in scope till next call, other API calls (such as append, erase) can invalidate the carved buffer
  epee::span<const uint8_t> carve(size_t sz) { CHECK_AND_ASSERT_THROW_MES(sz <= size(), "span is too large"); offset += sz; return epee::span<const uint8_t>(storage.data() + offset - sz, sz); }
  size_t size() const { return storage.size() - offset; }

private:
  std::vector<uint8_t> storage;
  size_t offset;
};
}
}
