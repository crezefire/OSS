# OSS : Operating System Services

The OS abstraction library you've never needed. Windows & Linux only.

## Getting Started
- Run `get_latest_deps.sh` to pull down 3rd party dependencies from Github. Use `[-s|--ssh]` to use ssh.
- `mkdir build && cd build`
- `cmake -G "Your Favourite Build Type" ../` Supported options are (OFF by default): `-D<OPTION>=ON`
  - OSS_ENABLE_BENCHMARKING - Creates sample Google Benchmark project
  - OSS_ENABLE_TESTING - Creats sample Google Test project
  - OSS_USE_LIBCXX - Sets `-stdlib=libc++` for Clang only
